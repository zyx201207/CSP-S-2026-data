#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 != c2) {
		cout << "0000";
		return 0;
	}
	if (s1.substr(0, 2) != s2.substr(0, 2)) {
		cout << "1000";
		return 0;
	}
	if ((s1[2] <= 'C' && s2[2] >= 'D') || (s1[2] >= 'D' && s2[2] <= 'C')) {
		cout << "1100";
		return 0;
	}
	if ((s1[2] == 'A' && s2[2] == 'C') || (s1[2] == 'C' && s2[2] == 'A')) {
		cout << "1110";
		return 0;
	}
	cout << "1111";
	return 0;
}
