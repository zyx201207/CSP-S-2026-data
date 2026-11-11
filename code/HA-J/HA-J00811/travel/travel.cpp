#include <bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
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
	cout << 1;
	if (s1[0] != s2[0] or s1[1] != s2[1])
	{
		cout << 0 << 0 << 0;
		return 0;
	}
	cout << 1;
	int cs1 = s1[2] - 'A' + 1;
	int cs2 = s2[2] - 'A' + 1;
	if ((cs1 <= 3 and cs2 >= 4) or (cs1 >= 4 and cs2 <= 3))
	{
		cout << 0 << 0;
		return 0;
	}
	cout << 1;
	if (cs1 >= 4 and cs2 >= 4)
	{
		cout << 1;
		return 0;
	}
	else
	{
		if (abs(cs1 - cs2) == 2)
		{
			cout << 0;
			return 0;
		}
		else
		{
			cout << 1;
			return 0;
		}
	}
}
