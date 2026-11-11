#include <bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;
int a, b;
char c, d;
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 != c2)
	{
		cout << "0000";
		return 0;
	}
	a = ((s1[0] - '0') * 10 + (s1[1] - '0'));
	b = ((s2[0] - '0') * 10 + (s2[1] - '0'));
	if(a != b)
	{
		cout << "1000";
		return 0;
	}
	c = s1[2];
	d = s2[2];
	if(((c == 'A' || c == 'B' || c == 'C') && (d == 'D' || d == 'F')) || ((d == 'A' || d == 'B' || d == 'C') && (c == 'D' || c == 'F')))
	{
		cout << "1100";
		return 0;
	}
	if((c == 'A' && d == 'B') || (c == 'B' && (d == 'A' || d == 'C')) || (c == 'C' && d == 'B') || (c == 'D' && d == 'F') || (c == 'F' && d == 'D'))
	{
		cout << "1111";
	}
	else
	{
		cout << "1110";
	}
	return 0;
}
