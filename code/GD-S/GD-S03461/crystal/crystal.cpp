#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5 + 100 ;
int n ;
ll m , a[N] , answer ;
ll check( int x ) {
	ll ans = 0 , now_m = m ;
	for( int i = 1 ; i <= n ; i++ ) {
		if( a[i] > x ) return ans ;
		if( a[i] == x ) {
			while( a[i] == x && i <= n ) {
				ans++ ;
				i++ ;
			}
		}
		else {
			if( now_m >= x - a[i] ) {
				ans++ ;
				now_m -= ( x - a[i] ) ;
			}
		}
	}
	return ans ;
}
int main() {
	ios::sync_with_stdio(0) , cin.tie(0) ;
	freopen( "crystal.in" , "r" , stdin ) , freopen( "crystal.out" , "w" , stdout ) ; 
	cin>>n>>m ;
	for( int i = 1 ; i <= n ; i++ ) cin>>a[i] ; 
	sort( a + 1 , a + n + 1 ) ;
	ll l = 1 , r = n ;
	while( l <= r ) {
		ll mid = ( l + r ) / 2 , ans = check( a[mid] ) ;
		if( ans >= answer ) answer = ans , l = mid + 1 ;
		else r = mid - 1 ;
	}
	cout<<answer ;
	return 0 ;
}
/*
5 8
-3 -1 2 2 7
*/
