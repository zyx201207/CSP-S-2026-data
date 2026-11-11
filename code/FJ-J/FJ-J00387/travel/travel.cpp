#include <bits/stdc++.h>
using namespace std;

bool check1(char x, char y)
{
	if (x > y) swap(x, y);
	if (x == 'A' && y == 'B') return 1;
	if (x == 'A' && y == 'C') return 1;
	if (x == 'B' && y == 'C') return 1;
	if (x == 'D' && y == 'F') return 1;
	return 0;
}

bool check2(char x, char y)
{
	if (x > y) swap(x, y);
	if (x == 'A' && y == 'B') return 1;
	if (x == 'B' && y == 'C') return 1;
	if (x == 'D' && y == 'F') return 1;
	return 0;
}

signed main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin.tie(0) -> sync_with_stdio(0);
	int c1, c2; string s1, s2; cin >> c1 >> s1 >> c2 >> s2;
	if (c1 != c2) return cout << "0000", 0;
	else cout << '1';
	if (s1.substr(0, 2) != s2.substr(0, 2)) cout << '0';
	else cout << '1';
	if (s1.substr(0, 2) == s2.substr(0, 2) && check1(s1[2], s2[2])) cout << '1';
	else cout << '0';
	if (s1.substr(0, 2) == s2.substr(0, 2) && check2(s1[2], s2[2])) cout << '1';
	else cout << '0';
	return 0;
}
