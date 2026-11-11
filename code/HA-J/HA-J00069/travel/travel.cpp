#include <bits/stdc++.h>

using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	bool b = true;
	b &= (c1 == c2);
	cout << b;
	b &= ((s1[0] == s2[0]) && (s1[1] == s2[1]));
	cout << b;
	b &= ((min(s1[2], s2[2]) >= 'D') || (max(s1[2], s2[2]) <= 'C'));
	cout << b;
	b &= (min(s1[2], s2[2]) + 1 == max(s1[2], s2[2]));
	cout << b;
	return 0;
}