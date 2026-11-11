#include <bits/stdc++.h>
using namespace std;
#define up(i, a, b) for(int i = a; i <= b; i++)
#define dn(i, a, b) for(int i = a; i >= b; i--)
#define VI vector <int>
int toint(string k) {
	int ans = (k[0] - '0') * 10 + k[1] - '0';
	ans *= 10;
	if (k[2] == 'A') ans += 1;
	if (k[2] == 'B') ans += 2;
	if (k[2] == 'C') ans += 3;
	if (k[2] == 'D') ans += 4;
	if (k[2] == 'F') ans += 5;
	return ans;
}
signed main () {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int c1, c2, x1, x2;
	string s1, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	x1 = toint(s1), x2 = toint(s2);
	if (c1 != c2) cout << "0000";
	else {
		cout << 1;
		if (x1 / 10 != x2 / 10) cout << "000";
		else {
			cout << 1;
			if ((x1 % 10 <= 3 && x2 % 10 >= 4) || (x1 % 10 >= 4 && x2 % 10 <= 3)) cout << "00";
			else {
				cout << 1;
				if (abs (x1 - x2) != 1) cout << 0;
				else cout << 1;
			}
		}
	}
	return 0;
}

