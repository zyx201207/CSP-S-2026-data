#include <bits/stdc++.h>
using namespace std ;

int a , b ;
string x , y ;

int main ()
{
	freopen ("travel.in" , "r" , stdin) ;
	freopen ("travel.out" , "w" , stdout) ;
	ios :: sync_with_stdio (0) ;
	cin . tie (0) ;
	cout . tie (0) ;
	cin >> a >> x >> b >> y ;
	if (a == b)
	{
		cout << 1 ;
		if ((x [0] - '0') * 10 + (x [1] - '0') == (y [0] - '0') * 10 + (y [1] - '0'))
		{
			cout << 1 ;
			int flag1 , flag2 ;
			if (x [2] >= 'A' && x [2] <= 'C')
				flag1 = 1 ;
			else
				flag1 = 0 ;
			if (y [2] >= 'A' && y [2] <= 'C')
				flag2 = 1 ;
			else
				flag2 = 0 ;
			if (flag1 == flag2)
			{
				cout << 1 ;
				if (abs ((int) (x [2]) - (int) (y [2])) == 1)
					cout << 1 ;
				else
					cout << 0 ;
			}
			else
				cout << "00" ;
		}
		else
			cout << "000" ;
	}
	else
		cout << "0000" ;
	return 0 ;
}
// 02 01A 02 01B
