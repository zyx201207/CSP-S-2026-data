#include<bits/stdc++.h>
using namespace std ;
int n , m ;
long long a [ 212345 ] ;
bool vis [ 25 ] ;
long long dfs ( int x , int sum ) {
	if ( x > n ) {
		if ( sum != m ) return 0 ;
		else {
			bool flag = 1 ;
			long long res  ;
			for ( int i = 1 ; i <= n ; i ++ ) {
				if ( vis [ i ] ) {
					if ( flag ) {
						res = a [ i ] ;
						flag = 0 ;
					} else res = ( res & a [ i ] );
				}
//				cout << vis [ i ] << " " ;
//				cout << " ans =" << res << " " ;
			}
//			cout << " ans =" << res << "\n" ;
			return res ; 
		}
	}
	long long res = 0;
	vis [ x ] = 0 ;
	res = max ( res , dfs ( x + 1 , sum ) ) ;
	vis [ x ] = 1 ;
	res = max ( res , dfs ( x + 1 , sum + 1 ) ) ;
	return res ;
}
int main ( ) {
	freopen ( "and.in" , "r" , stdin ) ;
	freopen ( "and.out" , "w" , stdout ) ;
	cin >> n >> m ;
	for ( int i = 1 ; i <= n ; i ++ ) {
		cin >> a [ i ] ;
	}
	if ( n <= 20 ) {
		cout << dfs ( 1 , 0 ) ;
	} else {
		if ( m == 1 ) {
			long long maxn = 0 ;
			for ( int i = 1 ; i <= n ; i ++ ) {
				maxn = max ( maxn , a [ i ] ) ;
			}
			cout << maxn ;
		} else if ( m == n ) {
			long long ans = a [ 1 ] ;
			for ( int i = 2 ; i <= n ; i ++ ) {
				ans &= a [ i ] ;
			}
			cout << ans ;
		} else if ( m == 2 ) {
			long long ans = 0 ;
			for ( int i = 1 ; i <= n ; i ++ ) {
				for (int j = i + 1; j <= n ; j ++ ) {
					ans = a [ i ] & a [ j ] ;
				}
			}
			cout << ans ;
		} else {
			cout << "我不会了" ; 
		}
	}
	return 0 ; 
}
