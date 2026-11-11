#include <bits/stdc++.h>
using namespace std;
string s1, s2, c1, c2;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1[0] == c2[0] && c1[1] == c2[1])
		cout << 1;
	else
		cout << 0;
	if (s1[0] == s2[0] && s1[1] == s2[1] && c1[0] == c2[0] && c1[1] == c2[1])
		cout << 1;
	else
		cout << 0;
	if (((s1[2] <= 'C' && s2[2] <= 'C') || (s1[2] >= 'D' && s2[2] >= 'D')) && s1[0] == s2[0] && s1[1] == s2[1] && c1[0] == c2[0] && c1[1] == c2[1])
		cout << 1;
	else
		cout << 0;
	if (((s1[2] <= 'C' && s2[2] <= 'C') || (s1[2] >= 'D' && s2[2] >= 'D')) && s1[0] == s2[0] && s1[1] == s2[1] && c1[0] == c2[0] && c1[1] == c2[1]
		&& ((abs(s1[2] - s2[2]) == 1 || (s1[2] == 'D' && s2[2] == 'F') || (s1[2] == 'F' && s2[2] == 'D')) && !(s1[2] == 'C' && s2[2] == 'D') && !(s1[2] == 'D' && s2[2] == 'C')))
		cout << 1;
	else
		cout << 0;
	return 0;
}
