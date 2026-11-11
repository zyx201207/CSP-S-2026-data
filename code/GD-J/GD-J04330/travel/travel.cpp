#include <bits/stdc++.h>
using namespace std;
string a[5], b[5];
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> a[0] >> a[1] >> b[0] >> b[1];
	if (a[0] == b[0]) {
		cout << "1";
		bool flag = 1;
		for (int i = 0; i < 2; i++) {
			if(a[1][i] != b[1][i]) {
				flag = 0;
			}
		}
		if (flag) {
			cout << "1";
			if ((a[1][2] == 'A' || a[1][2] == 'B' || a[1][2] == 'C') && (b[1][2] == 'A' || b[1][2] == 'B' || b[1][2] == 'C')) {
				if ((a[1][2] == 'A' && b[1][2] == 'C') || (b[1][2] == 'A' && a[1][2] == 'C')) {
					cout << "10";
				}
				else {
					cout << "11";
				}
			}
			else if ((a[1][2] == 'D' || a[1][2] == 'F') && (b[1][2] == 'D' || b[1][2] == 'F')){
				cout << "11";
			}
			else {
				cout << "00";
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
