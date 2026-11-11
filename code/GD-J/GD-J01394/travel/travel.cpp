#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen ( "travel.in" , "r" , stdin );
	freopen ( "travel.out" , "w" , stdout );
	string c1 , c2 , c3 , c4;
	cin >> c1 >> c2 >> c3 >> c4;
	if ( c1 != c3 )
	{
		cout << "0000";
		return 0;
	}
	else 
	{
		for ( int i = 0;i < 2; i++ )
		{
			if ( c2[i] - '0' != c4[i] - '0' ) 
			{
				cout << "1000";
				return 0;
			}
		}
		char a , b;
		a = c2[2];
		b = c4[2];
		if ( a == 'A' && b == 'B' ) 
		{
			cout << "1111";
			return 0;
		}
		else if ( a == 'B' && b == 'C' ) 
		{
			cout << "1111";
			return 0;
		}
		else if ( a == 'D' && b == 'F' ) 
		{
			cout << "1111";
			return 0;
		}
		else 
		{
			int a1  , a2;
			if ( a == 'A' ) a1 = 1;
			else if ( a == 'B') a1 = 2;
			else if ( a == 'C' ) a1 = 3;
			else if ( a == 'D' ) a1 = 4;
			else a1 = 5;
			
			if ( b == 'A') a2 = 1;
			else if ( b == 'B' ) a2 = 2;
			else if ( b == 'C') a2 = 3;
			else if ( b == 'D') a2 = 4;
			else a2 = 5;
			
			
			if ( a1 <= 3 && a2 <= 3 ) 
			{
				cout << "1110";
				return 0;
			}
			else if ( a1 > 3 && a1 <= 5 && a2 > 3 && a2 <= 5 ) 
			{
				cout << "1110";
				return 0;
			}
			else 
			{
				cout << "1100";
				return 0;
			}
		} 
	}
	return 0;
}
