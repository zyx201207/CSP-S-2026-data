#include <bits/stdc++.h>

using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s1, t1, s2, t2;
	cin >> s1 >> t1 >> s2 >> t2;
	if (s1 == s2) {
		if (t1.substr(0, 2) == t2.substr(0, 2)) {
			if ((t1[2] <= 'C' and t2[2] <= 'C') or (t1[2] >= 'D' and t2[2] >= 'D')) {
				if (t1[2] + 1 == t2[2]) cout << "1111" << '\n';
				else cout << "1110" << '\n';
			} else cout << "1100" << '\n';
		} else cout << "1000" << '\n';
	} else cout << "0000" << '\n';
	return 0;
}
