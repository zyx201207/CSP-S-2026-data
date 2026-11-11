#include <bits/stdc++.h>

using namespace std;

int main() {
	
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	string cp, sp, cq, sq;
	cin >> cp >> sp >> cq >> sq;
	
	if (cp == cq) {
		cout << "1";
		
		if (sp[0] == sq[0] && sp[1] == sq[1]) {
			cout << "1";
			
			int opa = 0, opb = 0;
			
			if (sp[2] == 'A' || sp[2] == 'B' || sp[2] == 'C') {
				opa = 1;
			} else {
				opa = 2;
			}
			
			if (sq[2] == 'A' || sq[2] == 'B' || sq[2] == 'C') {
				opb = 1;
			} else {
				opb = 2;
			}
			
			if (opa == opb) {
				cout << "1";
				
				if (abs(sp[2] - sq[2]) == 1) {
					cout << "1"; 
				} else {
					cout << "0";
				}
				 
			} else {
				cout << "00";
			}
		} else {
			cout << "000";
		}
		
	} else {
		cout << "0000";
	}
	
	return 0;
}
