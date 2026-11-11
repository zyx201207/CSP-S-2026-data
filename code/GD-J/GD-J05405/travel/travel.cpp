#include <bits/stdc++.h>
using namespace std;
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2;
	char l1, l2;
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2) {
		cout << "1";
	} else {
		cout << "0000";
		return 0;
	}
	if (s1.substr(0, 2) == s2.substr(0, 2)) {
		cout << "1";
	} else {
		cout << "000";
		return 0;
	}
	l1 = s1[2], l2 = s2[2];
	if ((('A' <= l1 && l1 <= 'C') && ('A' <= l2 && l2 <= 'C')) || 
		(('D' <= l1 && l1 <= 'F') && ('D' <= l2 && l2 <= 'F'))) {
		cout << "1";
	} else {
		cout << "00";
		return 0;
	}
	if (l1 > l2) swap(l1, l2);
	if ((l1 == 'A' && l2 == 'B') || 
		(l1 == 'B' && l2 == 'C') ||
		(l1 == 'D' && l2 == 'F')) {
		cout << "1";
	} else cout << "0";
	return 0;
}
