#include <bits/stdc++.h>
using namespace std;
string cR, sR, cX, sX;
int main() {
	freopen ("travel.in", "r", stdin);
	freopen ("travel.out", "w", stdout);
	cin >> cR >> sR >> cX >> sX;
	bool flaga = false;
	for (int i = 0; i < 2; i++) {
		if (cR[i] == cX[i]) {
			flaga = true;
		} else {
			flaga = false;
		}
	}
	bool flagb = false, flagc = false, flagd = false;
	int xr = 0, xx = 0;
	char x, y;
	for (int i = 0; i <= 3; i++) {
		if (sR[i] >= '0' && sR[i] <= '9') {
			xr = sR[i] - '0';
		} else{
			x = sR[i];
		}
		if (sX[i] >= '0' && sX[i] <= '9') {
			xx = sX[i] - '0';
		} else {
			y = sX[i];
		}
		if (xr == xx) {
			
			flagb = true;
		} else {
			flagb = false;
		}
		if ((x == 'A' && y == 'B') || (x == 'A' && y == 'C') || (x == 'B' && y == 'C') || (x == 'D' && y == 'F') || (x == 'B' && y == 'A') || (x == 'C' && y == 'A') || (x == 'C' && y == 'B') || (x == 'F' && y == 'D')) {
			flagc = true;
		}
		if ((x == 'A' && y == 'B') || (x == 'B' && y == 'C') || (x == 'D' && y == 'F')){
			flagd = true;
		}
 	}
	if (flaga == true) {
		cout << "1";
	} else {
		cout << "0";
	}
	if (flaga == true && flagb == true) {
		cout << "1";
	} else {
		cout << "0";
	}
	if (flagb == true && flagc == true) {
		cout << "1";
	} else {
		cout << "0";
	}
	if (flagd == true) {
		cout << "1";
	} else {
		cout << "0";
	}
 	return 0;
}
