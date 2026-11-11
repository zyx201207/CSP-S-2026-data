#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2,af,bf;
	cin >> c1 >> s1 >> c2 >> s2;
	af = s1[0] + s1[1];
	bf = s2[0] + s2[1];
	char ac = s1[2];
	char bc = s2[2];
	if (c1 != c2)
	{
		cout << "0000";
		return 0;
	}
	cout << "1";
	if (af != bf)
	{
		cout << "000";
		return 0;
	}
	cout << "1";
	if (ac >= 'A' && ac <= 'C')
	{
		if (bc >= 'A' && bc <= 'C')
		{
			cout << "1";
			if (ac == bc + 1 || ac == bc - 1)
			{
				cout << "1";
				return 0;
			}
			else
			{
				cout << "0";
				return 0;
			}
		}
		else
		{
			cout << "00";
			return 0;
		}
	}
	else
	{
		if (bc >= 'D' && bc <= 'F')
		{
			cout << "1";
			if (ac == bc + 1 || ac == bc - 1)
			{
				cout << "1";
				return 0;
			}
			else
			{
				cout << "0";
				return 0;
			}
		}
		else
		{
			cout << "00";
			return 0;
		}
	}
	return 0;
}
