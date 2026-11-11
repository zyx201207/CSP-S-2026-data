#include <bits/stdc++.h>
using namespace std;
bool f1, f2, f3;
int x, y;
string c1, s1, c2, s2;
int main () {
	freopen ("travel.in", "r", stdin);
	freopen ("travel.out", "w", stdout);
	ios::sync_with_stdio (false);
	cin.tie (0);cout.tie (0);
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2) {
		cout << 1;
		f1 = 1;
	}
	else cout << 0;
	if (f1 && s1[0] == s2[0] && s1[1] == s2[1]) {
		cout << 1;
		f2 = 1;
	}
	else cout << 0;
	x = (int)s1[2] - 'A', y = (int)s2[2] - 'A';
	if (f2 && ((x <= 2 && y <= 2) || (x >= 3 && y >= 3))) {
		cout << 1;
		f3 = 1;
	}
	else cout << 0;
	if (f3 && (x + 1 == y || x - 1 == y))  cout << 1;
	else cout << 0;
	return 0;
} 
