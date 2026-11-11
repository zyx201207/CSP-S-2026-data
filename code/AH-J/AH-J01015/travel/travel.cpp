#include <bits/stdc++.h>
using namespace std;
int c1, c2;
string s1, s2;
bool flag1 = 0, flag2 = 0;
bool xl(char a, char b)
{
	if (a == 'A' && b == 'B') return 1;
	if (a == 'B' && b == 'A') return 1;
	if (a == 'B' && b == 'C') return 1;
	if (a == 'C' && b == 'B') return 1;
	if (a == 'D' && b == 'F') return 1;
	if (a == 'F' && b == 'D') return 1;
	return 0;
}
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2) 
	{
		cout << 1;
		if (s1[0] == s2[0] && s1[1] == s2[1])
		{
			cout << 1;
			if (s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C') flag1 = 1;
			if (s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C') flag2 = 1;
			if (flag1 == flag2)
			{
				cout << 1;
				if (c1 == c2 && s1[0] == s2[0] && s1[1] == s2[1] && xl(s1[2], s2[2]) == 1) cout << 1;
				else cout << 0;
			}
			else cout << "00";
		}
		else cout << "000";
	}
	else cout << "0000";
	return 0;
}
