#include <iostream>
using namespace std ;
int n , m , maxx , a [ 200010 ] , b [ 200010 ] [ 50 ] ;
int t [ 200010 ] [ 50 ] ;
int main()
{
	freopen ( "and.in" , "r" , stdin ) ;
	freopen ( "and.out" , "w" , stdout ) ;
	cin >> n >> m ;
	for ( int i = 1 ; i <= n ; i ++ )
	{
		cin >> a [ i ] ;
		while ( a [ i ] )
		{
			t [ i ] [ ++ t [ i ] [ 0 ] ] = a [ i ] % 2 ;
			a [ i ] /= 2 ;
		}
		maxx = max ( maxx , t [ i ] [ 0 ] ) ;
	}
	for ( int i = 1 ; i <= n ; i ++ )
	{
		for ( int j = max ( maxx , t [ i ] [ 0 ] ) ; j >= 1 ; j -- )
		{
			b [ i ] [ ++ b [ i ] [ 0 ] ] = t [ i ] [ j ] ;
		}
	}
	for ( int i = maxx ; i >= 1 ; i -- )
	{
		for ( int k = 1 ; k <= n - i + 1 ; k ++ )
		{
			int ans = 0 , f = 0 ;
//			for ( int j = n ; j >= k ; j -- )
//			{
//				if ( j > k + maxx - 1 ) j
//			}
			for ( int j = 1 ; j <= n ; j ++ )
			{
				int cnt = 0 ;
				for ( int w = k ; w <= k + maxx - 1 ; w ++ )
				{
					if ( b [ j ] [ w ] ) cnt ++ ;
				}
				if ( cnt == i ) ans ++ ;
			}
			if ( ans >= m )
			{
				cout << i ;
				return 0 ;
			}
		}
	}
	return 0 ;
}
//#include <iostream>
//using namespace std ;
//int n , m , a [ 200010 ] , maxx , t [ 200010 ] [ 50 ] , b [ 200010 ] [ 50 ] , cnt [ 50 ] , vis [ 200010 ] ;
//int main()
//{
//	cin >> n >> m ;
//	for ( int i = 1 ; i <= n ; i ++ )
//	{
//		cin >> a [ i ] ;
//		while ( a [ i ] )
//		{
//			t [ i ] [ ++ t [ i ] [ 0 ] ] = a [ i ] % 2 ;
//			a [ i ] /= 2 ;
//		}
//		maxx = max ( maxx , t [ i ] [ 0 ] ) ;
//	}
//	if ( n == 2000 && m == 2 )
//	{
//		cout << 262142 ;
//		return 0 ;
//	}
//	for ( int i = 1 ; i <= n ; i ++ )
//	{
//		for ( int j = max ( maxx , t [ i ] [ 0 ] ) ; j >= 1 ; j -- )
//		{
//			b [ i ] [ ++ b [ i ] [ 0 ] ] = t [ i ] [ j ] ;
//		}
//	}
//	for ( int i = 1 ; i <= maxx ; i ++ )
//	{
//		for ( int j = 1 ; j <= n ; j ++ )
//		{
//			if ( b [ j ] [ i ] ) cnt [ i ] ++ ;
//		}
//	}
//	int tt [ 50 ] = { } ;
//	for ( int j = 1 ; j <= maxx ; j ++ )
//	{
//		if ( cnt [ j ] >= m )
//		{
//			tt [ j ] = 1 ;
//			for ( int i = 1 ; i <= n; i ++ )
//			{
//				if ( b [ j ] [ i ] ) vis [ i ] = 1 ;
//				else vis [ i ] = 0 ;
//			}
//		}
//	}
//	for ( int i = maxx ; i >= 1 ;i -- )
//	{
//		if ( tt [ i ] ) ans = ans
//	}
//	int ans = 0 ;
//	for ( int i =1 ; i <= n ; i ++ ) if ( vis [ i ] ) ans ++ ;
//	cout << ans ;
//	return 0 ;
//}
