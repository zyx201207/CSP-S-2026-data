#include <bits/stdc++.h>
using namespace std ;
string s, c, t, b ;
signed main ()
{
	freopen ("travel.in", "r", stdin) ;
	freopen ("travel.out", "w", stdout) ;
	ios :: sync_with_stdio (false) ;
	cin.tie (0), cout.tie (0) ;
	cin >> s >> c >> t >> b ;
	if (s == t)
	{
		cout << 1 ;
		if (c[0] == b[0] && c[1] == b[1])
		{
			cout << 1 ;
			if (c[2] <= 'C' && c[2] >= 'A' && b[2] <= 'C' && b[2] >= 'A')
			{
				cout << 1 ;
				if (abs (int (c[2] - b[2])) == 1)
					cout << 1 ;
				else cout << 0 ;
				return 0 ;
			}
			else if ((c[2] == 'F' || c[2] == 'D') && (b[2] == 'F' || b[2] == 'D'))
			{
				cout << "11" ;
				return 0 ;
			}
			else
			{
				cout << "00" ;
				return 0 ;
			}
		}
		else
		{
			cout << "000" ;
			return 0 ;
		}
	}
	else
	{
		cout << "0000" ;
		return 0 ;
	}
	return 0 ;
}
