#include <iostream>
using namespace std ;
char c [ 200010 ] ;
long long n , sum , ans , x [ 200010 ] ;
int main()
{
	freopen ( "string.in" , "r" , stdin ) ;
	freopen ( "string.out" , "w" , stdout ) ;
	cin >> n ;
	for ( int i = 1 ; i <= n ; i ++ )
	{
		cin >> x [ i ] >> c [ i ] ;
		sum += x [ i ] ;
	}
	long long i = x [ 1 ] , j = x [ n ] , ti = 1 , tj = n ;
	while ( ti < tj )
	{
		if ( j < i && c [ ti ] != c [ tj ] )
		{
			ans += j , sum -= j * 2 , i -= j , tj -- , j = x [ tj ] ;
		}
		else if ( j < i && c [ ti ] == c [ tj ] )
		{
			sum -= j * 2 , i -= j , tj -- , j = x [ tj ] ;
		}
		else if ( i < j && c [ ti ] != c [ tj ] )
		{
			ans += i , sum -= i * 2 , j -= i , ti ++ , i = x [ ti ] ;
		}
		else if ( i < j && c [ ti ] == c [ tj ] )
		{
			sum -= i * 2 , j -= i , ti ++ , i = x [ ti ] ;
		}
		else if ( i == j && c [ ti ] != c [ tj ] )
		{
			ans += i , sum -= i * 2 , ti ++ , tj -- , i = x [ ti ] , j = x [ tj ] ;
		}
		else sum -= i * 2 , ti ++ , tj -- , i = x [ ti ] , j = x [ tj ] ;
	}
	cout << ans ;
	return 0 ;
}
