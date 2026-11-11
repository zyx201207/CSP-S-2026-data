/**
 * @file CSP-J 2026
 *       Problem A. travel
 * @author BJ-J01847
 *         LG-1014842 liuli688
 * @date 2026/10/31
*/

// Nothing could save you.
// Lament Rain - Ashrount vs. D-D-Dice

// password: Trick||Treat!

#include <bits/stdc++.h>
using namespace std;
typedef pair<char, char> pcc;

int c1, c2, a, b, c, d;
string s1, s2;

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	a = (c1 == c2);
	b = a && (s1[0] == s2[0] && s1[1] == s2[1]);
	c = b && (s1[2] <= 'C' && s2[2] <= 'C' || s1[2] >= 'D' && s2[2] >= 'D');
	auto mn = min(s1[2], s2[2]), mx = max(s1[2], s2[2]);
	d = c && (mn == 'A' && mx == 'B' || mn == 'B' && mx == 'C' || mn == 'D' && mx == 'F');
	cout << a << b << c << d << '\n';
	return 0;
}

//08:43