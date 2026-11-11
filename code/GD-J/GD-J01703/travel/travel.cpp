#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int w = 1e5 + 10;
const int inf = 0x3f3f3f3f;
string c1,s1,c2,s2;
int path(int z)
{
	char x;
	if (z == 1)
		x = s1[2];
	else
		x = s2[2];
	if (x == 'A' || x == 'B' || x == 'C')
		return 1;
	return 2;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 != c2)
	{
		cout << "0000";
		return 0;
	}
	else if (s1[0] != s2[0] || s1[1] != s2[1])
	{
		cout << "1000";
		return 0;
	}
	else if (path(1) != path(2))
	{
		cout << "1100";
		return 0;
	}
	else
	{
		if (path(1) == 2 && path(2) == 2)
		{
			cout << "1111";
			return 0;
		}
		else
		{
			if ((s1[2] == 'A' && s2[2] == 'C') || (s1[2] == 'C' && s2[2] == 'A'))
			{
				cout << "1110";
				return 0;
			}
			else
			{
				cout << "1111";
				return 0;
			}
		}
	}
	return 0;
}
