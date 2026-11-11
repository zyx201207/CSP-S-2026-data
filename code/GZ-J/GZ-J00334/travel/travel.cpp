//GZ-J00334贵阳市第十六中学曾楠博
#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a[2] = {}, b[2] = {};
	cin >> a[0] >> a[1] >> b[0] >> b[1];
	if( a[0] == b[0] )
	{
		if( a[1][0] == b[1][0] && a[1][1] == b[1][1] )
		{
			if( a[1][2] == 'D' )
			{
				if( b[1][2] == 'F' )
				{
					cout << "1111";
				}
				else cout << "1100";
			}
			else if( a[1][2] == 'F' )
			{
				if( b[1][2] == 'D' )
				{
					cout << "1111";
				}
				else cout << "1100";
			}
			else if( a[1][2] == 'C' )
			{
				if( b[1][2] == 'B' ) cout << "1111";
				else if( b[1][2] == 'A' ) cout << "1110";
				else cout << "1100";
			}
			else if( a[1][2] == 'B' )
			{
				if( b[1][2] == 'C' || b[1][2] == 'A' ) cout << "1111";
				else cout << "1100";
			}
			else if( a[1][2] == 'A' )
			{
				if( b[1][2] == 'B' ) cout << "1111";
				else if( b[1][2] == 'C' ) cout << "1110";
				else cout << "1100";
			}
		}
		else cout << "1000";
	}
	else cout << "0000";
	return 0;
}
