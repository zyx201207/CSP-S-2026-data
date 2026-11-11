#include <bits/stdc++.h>
using namespace std;
int main ( ) {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string s1, c1, s2, c2;
	cin >> s1 >> c1 >> s2 >> c2;
	if (s1 != s2) {
		cout << "0000";
		return 0;
	}
	else {
		cout << "1";
		string a = "";
		string b = "";
		for (int i = 0; i < 2; i++) {
			a += c1[i];
			b += c2[i];
		}
		if (a == b) {
			cout << "1";
			if ((c1[2] == 'A' && c2[2] == 'B') || (c1[2] == 'A' && c2[2] == 'C') || (c1[2] == 'B' && c2[2] == 'C') || (c1[2] == 'B' && c2[2] == 'A') || (c1[2] == 'C' && c2[2] == 'A') || (c1[2] == 'C' && c2[2] == 'B') || (c1[2] == 'D' && c2[2] == 'E') || (c1[2] == 'E' && c2[2] == 'D')) {
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
	bool flag = true;
	for (int i = 0; i < 3; i++) {
		if (c1[i] != c2[i]) {
			if (((c1[i] == 'C' && c2[i] == 'D') || (c1[i] == 'D' && c2[i] == 'C') || abs(c1[i] - c2[i]) != 1) || flag == false) {
				cout << "0";
				return 0;
			}
			flag = false;
		}
	}
	cout << "1";
	return 0;
}
