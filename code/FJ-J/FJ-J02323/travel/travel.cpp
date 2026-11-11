#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1;
	string s1;
	string c2;
	string s2;
	cin >> c1 >> s1 >> c2 >> s2;
	bool flag = true;
	bool flag2 = true;
	bool flag3 = true;
	bool flag4 = true;
	for (int i = 0; i < c1.size(); i++) {
		if (c1[i] != c2[i]) {
			flag = false;
		}
	}
	for (int i = 0; i < 2; i++) {
		if (s1[i] != s2[i]) {
			flag2 = false;
		}
	}
	if ((s1[2] <= 'C' && s2[2] <= 'C') || (s1[2] >= 'D' && s2[2] >= 'D')) {
		flag3 = true;
	} else {
		flag3 = false;
	}
	if (flag && flag2 && flag3) {
		if (s1[2] >= 'D' && s2[2] >= 'D') {
			flag4 = true;
		} else if (s1[2] - s2[2] == 1 || s2[2] - s1[2] == 1) {
			flag4 = true;
		} else {
			flag4 = false;
		}
	}
	if (flag) {
		cout << '1';
		if (flag2) {
			cout << '1';
			if (flag3) {
				cout << '1';
				if (flag4) {
					cout << '1';
				} else {
					cout << '0';
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
