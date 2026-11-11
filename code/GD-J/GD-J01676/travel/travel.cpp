#include <bits/stdc++.h>
#define int long long
using namespace std;
bool ch(char c)
{
	if (c == 'A' || c == 'B' || c == 'C')
	{
		return true;
	}
	else
	{
		return false;
	}
}
signed main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,s3,s4;
	cin >> s1 >> s2 >> s3 >> s4;
	if (s1 == s3)
	{
		cout << 1;
		if (s2[0] == s4[0] && s2[1] == s4[1])
		{
			cout << 1;
			if (ch(s2[2]) == ch(s4[2]))
			{
				cout << 1;
				if (abs((int)s2[2] - (int)s4[2]) == 1)
				{
					cout << 1;
				}
				else
				{
					cout << 0;
				}
			}
			else
			{
				cout << "00";
			}
		}
		else
		{
			cout << "000";
		}
	}
	else
	{
		cout << "0000";
	}
	return 0;
}
