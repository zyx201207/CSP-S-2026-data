#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("travel.in", "r", stdin); 
	freopen ("travel.out", "w", stdout);
	
	string ca, sa, cb, sb;
	cin >> ca >> sa >> cb >> sb;
	if (ca != cb) {
		cout << "0000" << endl;
		return 0;
	} else {
		if (sa[0] != sb[0] || sa[1] != sb[1]) {
			cout << "1000" << endl;
			return 0;
		} else {
			if (sa[2] <= 'C' && sb[2] >'C' || sa[2] > 'C' && sb[2] <= 'C') {
				cout << "1100" << endl;
				return 0;
			} else {
				if (sa[2] - sb[2]  == 1 || sb[2] - sa[2]  == 1) {
					cout << "1111" << endl;
				} else {
					cout << "1110" << endl;
				}
 			}
		}
	}
	return 0;
}
