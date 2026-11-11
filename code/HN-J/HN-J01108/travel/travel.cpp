#include <bits/stdc++.h>
using namespace std;
#define int long long
// A B C    D F
string c1, c2, k1, k2; 
signed main() {
	freopen("travel.in" , "r", stdin );
	freopen("travel.out", "w", stdout);
	
	ios::sync_with_stdio(NULL);
	cin.tie(0);
	cout.tie(0);
	cin >> c1 >> k1 >> c2 >> k2;
	if (c1 == c2) {
		cout << "1";
		if (k1[0] == k2[0] && k1[1] == k2[1]) {
			cout << "1";
			if (k1[2] >= 'A' && k1[2] <= 'C' && k2[2] >= 'A' && k2[2] <= 'C') {
				cout << "1";
				if ((k1[2] == 'A' && k2[2] == 'B') || (k1[2] == 'B' && k2[2] == 'C')) {
					cout << "1";
				}
				else {
					cout << "0";
				}
			}
			else {
				if (k1[2] >= 'D' && k1[2] <= 'F' && k2[2] >= 'D' && k2[2] <= 'F') {
					cout << "1";
					if (k1[2] == 'D' && k2[2] == 'E') {
						cout << "1";
					}
					else {
						cout << "0";
					}
				}
				else {
					cout << "00";
				}
			}
		}
		else {
			cout << "000";
		}
	}
	else {
		cout << "0000";
	}
	return 0;
}
