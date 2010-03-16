/**
 * sensorPinHole.cpp
 *
 *  Created on: 10/03/2010
 *      Author: jsola
 *
 *  \file sensorPinHole.cpp
 *
 *  ## Add a description here ##
 *
 * \ingroup rtslam
 */

#include "rtslam/sensorPinHole.hpp"

namespace jafar {
	namespace rtslam {
		using namespace std;

		/*
		 * Constructor from Gaussian pose
		 */
		SensorPinHole::SensorPinHole(const Gaussian & _pose) :
			SensorAbstract(_pose) {
			type("Pin-hole-camera");
		}

		/*
		 * Constructor from mean pose
		 */
		SensorPinHole::SensorPinHole(const jblas::vec7 & _pose) :
			SensorAbstract(_pose) {
			type("Pin-hole-camera");
		}

		/*
		 * Construction from map and indirect array
		 */
		SensorPinHole::SensorPinHole(MapAbstract & _map) :
			SensorAbstract(_map) {
			type("Pin-hole-camera");
		}

		/**
		 * Selectable LOCAL or REMOTE pose constructor.
		 */
		SensorPinHole::SensorPinHole(RobotAbstract & _rob, bool inFilter) :
			SensorAbstract(_rob, inFilter){
			type("Pin-hole-camera");
		}


		/**
		 * Pin-hole sensor parameters setup.
		 */
		void SensorPinHole::set_parameters(const jblas::vec4 & k, const jblas::vec & d, const jblas::vec & c,
		    const size_t hsize, const size_t vsize) {
			parameters.intrinsic = k;
			parameters.distortion.resize(d.size());
			parameters.distortion = d;
			parameters.correction.resize(c.size());
			parameters.correction = c;
			image.pixels.resize(hsize,vsize);
			image.H_size = hsize;
			image.V_size = vsize;
		}

	}
}

