#include <cmath>
#include <iostream>
using namespace std ;
string c1 , s1 , c2 , s2 ;
int main()
{
	freopen ( "travel.in" , "r" , stdin ) ;
	freopen ( "travel.out" , "w" , stdout ) ;
	cin >> c1 >> s1 >> c2 >> s2 ;
	for ( int i = 0 ; i < c1 . size ( ) ; i ++ )
	{
		if ( c1 [ i ] != c2 [ i ] )
		{
			cout << 0 << 0 << 0 << 0 ;
			return 0 ;
		}
	}
	if ( s1 [ 0 ] != s2 [ 0 ] || s1 [ 1 ] != s2 [ 1 ] )
	{
		cout << 1 << 0 << 0 << 0 ;
		return 0 ;
	}
	if ( ( s1 [ 2 ] >= 'A' && s1 [ 2 ] <= 'C' ) && ( s2 [ 2 ] >= 'D' && s2 [ 2 ] <= 'F' ) )
	{
		cout << 1 << 1 << 0 << 0 ;
		return 0 ;
	}
	if ( ( s1 [ 2 ] >= 'D' && s1 [ 2 ] <= 'F' ) && ( s2 [ 2 ] >= 'A' && s2 [ 2 ] <= 'C' ) )
	{
		cout << 1 << 1 << 0 << 0 ;
		return 0 ;
	}
	if ( abs ( s1 [ 2 ] - s2 [ 2 ] ) > 1 )
	{
		cout << 1 << 1 << 1 << 0 ;
		return 0 ;
	}
	cout << 1 << 1 << 1 << 1 ;
	return 0 ;
}
