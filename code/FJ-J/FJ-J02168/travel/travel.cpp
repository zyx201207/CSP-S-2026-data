#include <iostream>
using namespace std;
string s1 , s2 , a , b ;
int main()
{
	freopen("problem1.in","r",stdin);
	freopen("problem1.out","w",stdout);
	cin >> a >> s1 >> b >> s2 ;
	if ( a[0] == b[0] && a[1] == b[1] )
	{
		if ( s1[0] == s2[0] && s1[1] == s2[1] )
		{
			if ( ('A' <= s1[2] && s1[2] <= 'C' && 'A' <= s2[2] && s2[2] <= 'C') || ( 'D' <= s1[2] && s1[2] <= 'F' && 'D' <= s2[2] && s2[2] <= 'F'))
			{
				if ('D' <= s1[2] && s1[2] <= 'F' && 'D' <= s2[2] && s2[2] <= 'F')
				{
					cout << "1111";
					cout << 2 ;
					return 0;
				}
				if( s1[2] == 'B' || s2[2] == 'B' )
				{
					cout << "1111";
					cout << 1;
					return 0 ;
				}
				else
				{
					cout << "1110";
					return 0 ;
				}
			}
			else
			{
				cout << "1100";
				return 0 ;
			}
		}
		else
		{
			cout << "1000";
			return 0;
		}
	}
	else
	{
		cout << "0000" ;
		return 0;
	}
	return 0 ;
}
