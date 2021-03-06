/*  =========================================================================
    dc - DC information

    Copyright (C) 2014 - 2020 Eaton

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
    =========================================================================
*/

#ifndef DC_H_INCLUDED
#define DC_H_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#ifndef DC_T_DEFINED
typedef struct _dc_t dc_t;
#define DC_T_DEFINED
#endif

//  @interface
//  Create a new dc
FTY_KPI_POWER_UPTIME_EXPORT dc_t *
    dc_new (void);

//  Destroy the dc
FTY_KPI_POWER_UPTIME_EXPORT void
    dc_destroy (dc_t **self_p);

// Get total value
FTY_KPI_POWER_UPTIME_EXPORT uint64_t
    dc_total (dc_t* self);

// Get off line value
FTY_KPI_POWER_UPTIME_EXPORT uint64_t
    dc_off_line (dc_t* self);

// Set total value
FTY_KPI_POWER_UPTIME_EXPORT void
    set_dc_total (dc_t* self, uint64_t total);

// Set off line value
FTY_KPI_POWER_UPTIME_EXPORT void
    set_dc_off_line (dc_t* self, uint64_t offline);

//  Return if dc is offline
bool
    dc_is_offline (dc_t *self);

//  Set UPS as as offline
void
    dc_set_offline (dc_t *self, char* ups);

// Set UPS as online
void
    dc_set_online (dc_t *self, char* ups);

// Compute uptime, return result in total/offline pointers
void
    dc_uptime (dc_t *self, uint64_t* total, uint64_t* offline);

// pack dc to frame
FTY_KPI_POWER_UPTIME_EXPORT zframe_t *dc_pack (dc_t *self);

// unpack dc class from frame
FTY_KPI_POWER_UPTIME_EXPORT dc_t *dc_unpack (zframe_t *frame);

//  Print properties of object
FTY_KPI_POWER_UPTIME_EXPORT void
    dc_print (dc_t *self);

//  Self test of this class
FTY_KPI_POWER_UPTIME_EXPORT void
    dc_test (bool verbose);
//  @end

#ifdef __cplusplus
}
#endif

#endif
