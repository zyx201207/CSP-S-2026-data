#include <bits/stdc++.h>
using namespace std;
#define int long long
#define wabs(a) ((a)<0 ? -(a) : (a))

signed main ()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);

	string s00,s01,s10,s11;
	cin >> s00 >> s01 >> s10 >> s11;
	if (s00==s10)
	{
		cout << "1";
		if (s01[0]==s11[0] && s01[1]==s11[1])
		{
			cout << "1";
			bool left0=0,left1=0;
			if (s01[2]=='A' || s01[2]=='B' || s01[2]=='C')
				left0=1;
			if (s11[2]=='A' || s11[2]=='B' || s11[2]=='C')
				left1=1;
			if (left0==left1)
			{
				cout << "1";
				if (left0 ? wabs(s01[2]-s11[2])==1 : 1)
				{
					cout << "1";
				}
				else
				{
					cout << "0";
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

/*
02 01A 02 01C
*/

/*
16 12D 16 12F
*/
