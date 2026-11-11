#include<bits/stdc++.h>
#define ll long long
using namespace std ;
const int N = 2e6 + 7 ;
ll c , T ;
ll n , D ;
ll x [ N ] ;
ll d [ N ] , t [ N ] ;
vector < ll > e [ N ] ;
void spfa ( ll st ) {
	queue < ll > q ;
	memset ( d , 0x3f , sizeof d ) ;
	memset ( t , 0 , sizeof t ) ;
	d [ st ] = 0 ;
	t [ st ] = 1 ;
	q . push ( st ) ;
	while ( ! q . empty () ) {
		ll g = q . front () ;
		q . pop () ;
		for ( ll i : e [ g ] ) {
			if ( d [ g ] + 1 < d [ i ] ) {
				d [ i ] = d [ g ] + 1 ;
				t [ i ] = t [ g ] ;
				q . push ( i ) ;
			} else if ( d [ g ] + 1 == d [ i ] ) {
				t [ i ] += t [ g ] ;
			}
		}
	}
}
int main () {
	freopen ( "migrate.in" , "r" , stdin ) ;
	freopen ( "migrate.out" , "w" , stdout ) ;
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> c >> T ;
	while ( T -- ) {
		cin >> n >> D ;
		for ( int i = 1 ; i <= n ; i ++ ) e [ i ] . clear () ;
		for ( ll i = 1 ; i <= n ; i ++ ) {
			cin >> x [ i ] ;
			for ( ll j = i - 1 ; j >= 1 ; j -- ) {
				if ( x [ i ] - x [ j ] <= D ) {
					e [ i ] . push_back ( j ) ;
					e [ j ] . push_back ( i ) ;
				} else {
					break ;			
				}
			}
		}
		ll res = 0 ;
		for ( ll i = 1 ; i <= n ; i ++ ) {
			spfa ( i ) ;
			for ( ll j = 1 ; j <= n ; j ++ ) {
				if ( t [ j ] == 2 ) res ++ ;
			}
		}
		if ( res ) res /= 2 ;
		cout << res << '\n' ;
	}
	return 0 ;
}
