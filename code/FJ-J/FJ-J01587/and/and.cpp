#include <bits/stdc++.h>
#define ll long long
using namespace std ;
const int N = 2e5 + 10 ;
int n , m , maxx , a [N] , cnt ;
int b [25] ;

inline int qpow( int a , int b ) {
	if ( b == 0 )
		return 1 ;
	int res = 1 ;
	while ( b ) {
		if ( ( b & 1 ) == 1 )
			res *= a ;
		a *= a ;
		b >>= 1 ;
	}
	return res ;
}

inline void solve() {
	int sum = ( b [1] & b [2] ) ;
	for ( int i = 3 ; i <= m ; i++ ) {
		sum &= b [i] ;
	}
	maxx = max ( sum , maxx ) ;
}

inline void dfs( int steps ) {
	if ( cnt == m ) {
		solve() ;
		return ;
	}
	if ( steps == n + 1 )
		return ;
	b [++cnt] = a [steps] ;
	dfs( steps + 1 ) ;
	b [cnt] = 0 , --cnt ;
	if ( m - cnt > n - steps + 1 )
		return ;
	dfs( steps + 1 ) ;
}

int main() {
	freopen ( "and.in" , "r" , stdin ) ;
	freopen ( "and.out" , "w" , stdout ) ;
//	freopen ( "text.in" , "r" , stdin ) ;
//	freopen ( "my.out" , "w" , stdout ) ;
	ios::sync_with_stdio ( false ) ;
	cin.tie ( 0 ) ;
	cout.tie ( 0 ) ;
	cin >> n >> m ;
	for ( int i = 1 ; i <= n ; ++i ) {
		cin >> a [i] ;
		maxx = max ( maxx , a [i] ) ;
	}
	if ( m == 1 ) {
		cout << maxx ;
		return 0 ;
	}
	if ( m == 2 && n <= 2000 ) {
		maxx = 0 ;
		for ( int i = 1 ; i <= n ; i++ ) {
			for ( int j = i + 1 ; j <= n ; j++ ) {
				maxx = max ( maxx , ( a [i] & a [j] ) ) ;
			}
		}
		cout << maxx ;
		return 0 ;
	}
	if ( m == n ) {
		maxx = ( a [1] & a [2] ) ;
		for ( int i = 3 ; i <= n ; i++ ) {
			maxx &= a [i] ;
		}
		cout << maxx ;
		return 0 ;
	}
	if ( n <= 20 ) {
		maxx = 0 ;
		dfs( 1 ) ;
		cout << maxx ;
		return 0 ;
	}
	int id = -1 ;
	for ( int i = 0 ; i <= 30 ; i++ ) {
		if ( qpow ( 2 , i ) == n ) {
			id = i ;
			break ;
		}
	}
	if ( id != -1 ) {
		cout << n - 2 ;
		return 0 ;
	}
	bool flag = true ;
	for ( int i = 1 ; i <= n && flag ; i++ ) {
		bool flag2 = false ;
		for ( int j = 0 ; j <= 30 ; j++ ) {
			if ( qpow ( 2 , j ) == a [i] ) {
				flag2 = true ;
				break ;
			}
		}
		if ( !flag2 )
			flag = false ;
	}
	if ( flag ) {
		sort ( a + 1 , a + n + 1 ) ;
		cout << a [ n - m + 1 ] ;
		return 0 ;
	}
	return 0 ;
}
