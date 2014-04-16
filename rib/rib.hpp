/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
/**
 * Copyright (c) 2014  Regents of the University of California,
 *                     Arizona Board of Regents,
 *                     Colorado State University,
 *                     University Pierre & Marie Curie, Sorbonne University,
 *                     Washington University in St. Louis,
 *                     Beijing Institute of Technology,
 *                     The University of Memphis
 *
 * This file is part of NFD (Named Data Networking Forwarding Daemon).
 * See AUTHORS.md for complete list of NFD authors and contributors.
 *
 * NFD is free software: you can redistribute it and/or modify it under the terms
 * of the GNU General Public License as published by the Free Software Foundation,
 * either version 3 of the License, or (at your option) any later version.
 *
 * NFD is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 * without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 * PURPOSE.  See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * NFD, e.g., in COPYING.md file.  If not, see <http://www.gnu.org/licenses/>.
 **/

#ifndef NFD_RIB_RIB_HPP
#define NFD_RIB_RIB_HPP

#include "common.hpp"

#include <ndn-cpp-dev/management/nrd-prefix-reg-options.hpp>

namespace nfd {
namespace rib {

using ndn::nrd::PrefixRegOptions;
namespace tlv = ndn::tlv;

/** \brief represents the RIB
 */
class Rib
{
public:
  typedef std::list<PrefixRegOptions> RibTable;
  typedef RibTable::const_iterator const_iterator;

  Rib();

  ~Rib();

  const_iterator
  find(const PrefixRegOptions& options) const;

  void
  insert(const PrefixRegOptions& options);

  void
  erase(const PrefixRegOptions& options);

  void
  erase(uint64_t faceId);

  const_iterator
  begin() const;

  const_iterator
  end() const;

  size_t
  size() const;

  size_t
  empty() const;

private:
  // Note: Taking a list right now. A Trie will be used later to store
  // prefixes
  RibTable m_rib;
};

inline Rib::const_iterator
Rib::begin() const
{
  return m_rib.begin();
}

inline Rib::const_iterator
Rib::end() const
{
  return m_rib.end();
}

inline size_t
Rib::size() const
{
  return m_rib.size();
}

inline size_t
Rib::empty() const
{
  return m_rib.empty();
}

} // namespace rib
} // namespace nfd

#endif // NFD_RIB_RIB_HPP