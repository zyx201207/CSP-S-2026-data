#include<bits/stdc++.h>
#define ll long long
using namespace std ;
int main () {
	freopen ( "hub.in" , "r" , stdin ) ;
	freopen ( "hub.out" , "w" , stdout ) ;
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n >> m ;
	for ( ll i = 1 ; i <= n ; i ++ ) {
		cin >> a [ i ] ;
	}
	sort ( a + 1 , a + 1 + n ) ;
	ll t = 1 ;
	ll res = 0 ;
	for ( ll i = 1 ; i <= n ; i ++ ) {
		p [ i ] = p [ i - 1 ] + a [ i ] ;
		while ( a [ i ] * ( i - t + 1 ) > m - p [ t - 1 ] + p [ i ] ) {
			t ++ ;
		}
		res = max ( res , i - t + 1 ) ;
	}
	cout << res ;
	return 0 ;
} 
