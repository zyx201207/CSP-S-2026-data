#include <bits/stdc++.h>
using namespace std;
string c1, c2, s1, s2;
bool f = false;
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> c1 >> s1 >> c2 >> s2;
	f = false;
	if (c1 == c2) {
		f = true;
		cout << 1;
	} else {
		f = false;
		cout << 0;
	}
	if (s1[0] == s2[0] && s1[1] == s2[1] && f) {
		f = true;
		cout << 1;
	} else {
		f = false;
		cout << 0;
	}
	char t1 = s1[2], t2 = s2[2];
	if (((t1 <= 'C' && t1 >= 'A' && t2 <= 'C' && t2 >= 'A') || (t1 <= 'F' && t1 >= 'D' && t2 <= 'F' && t2 >= 'D')) && f) {
		f = true;
		cout << 1;
	} else {
		f = false;
		cout << 0;
	}
	int tt1 = t1 - '0', tt2 = t2 - '0';
	if (abs(tt1 - tt2) == 1 && f) {
		cout << 1;
	} else {
		cout << 0;
	}
	return 0;
}
