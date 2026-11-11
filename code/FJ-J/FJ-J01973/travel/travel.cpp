#include <bits/stdc++.h>
using namespace std;
int c1, c2;
string s1, s2;
int main () {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	bool flag1 = (c1 == c2);
	bool flag2 = (flag1 && s1[0] == s2[0] && s1[1] == s2[1]);
	bool flag3 = (flag2 && ((s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C') && (s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C')) || ((s1[2] == 'D' || s1[2] == 'F') && (s2[2] == 'D' || s2[2] == 'F')));
	bool flag4 = (flag3 && (s1[2] == (char)s2[2] + 1 || s1[2] == (char)s2[2] - 1));
	cout << flag1 << flag2 << flag3 << flag4;
	return 0;
}
