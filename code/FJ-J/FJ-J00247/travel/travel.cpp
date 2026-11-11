#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	bool flag = true;
	if (c1 == c2) {
		cout << 1;
	} else {
		cout << 0; 
		flag = false;
	}
	if (flag && s1[0] == s2[0] && s1[1] == s2[1]) {
		cout << 1;
	} else {
		cout << 0;
		flag = false;
	}
	if (flag && ((s1[2] >= 'A' && s1[2] <= 'C' && s2[2] >= 'A' && s2[2] <= 'C') || (s1[2] >= 'D' && s1[2] <= 'F' && s2[2] >= 'D' && s2[2] <= 'F'))) {
		cout << 1;
	} else {
		cout << 0;
		flag = false;
	}
	char q1 = s1[2], q2 = s2[2];
	int a = abs(q1 - q2);
	if (flag && a == 1 && !(q1 == 'C' && q2 == 'D') && !(q1 == 'D' && q2 == 'C')) {
		cout << 1;
	} else {
		cout << 0;
	}
	return 0;
}
