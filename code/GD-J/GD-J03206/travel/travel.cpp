#include <bits/stdc++.h>
#define ll long long
#define rep(i, x, y) for (int i = x; i <= y; i++)
#define rd read()
using namespace std;
string c1, s1, c2, s2;
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2) {
		cout << "1";
		if (s1[0] == s2[0] && s1[1] == s2[1]) {
			cout << "1";
			char r1 = s1[2], r2 = s2[2];
			if ((r1 <= 'C' && r2 <= 'C') || (r1 >= 'D' && r2 >= 'D')) {
				cout << "1";
				if (r1 <= 'C' && r2 <= 'C') {
					if ((int)r1 + 1 == (int)r2 || (int)r2 + 1 == (int)r1) cout << "1";
					else cout << "0";
				} else {
					if ((int)r1 + 1 == (int)r2 || (int)r2 + 1 == (int)r1) cout << "1";
					else cout << "0";
				}
			} else cout << "00";
		}
		else cout << "000";
	}
	else cout << "0000";
}
