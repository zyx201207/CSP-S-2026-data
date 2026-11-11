#include <bits/stdc++.h>
using namespace std ; 
const int N = 5e5 + 10 ;
#define ll long long
ll a[N] ;
int cnt = 1; 
int n , m ;
ll ans[N] ; 
queue <ll> q ;
bool pd (ll x ) {
	ll sum = 0 ; 
	for (int i = 1 ; i <= n && a[i] <= x ; i ++ ) {
		sum += x - a[i] ; 
	}
	return sum <= m ; 
}
ll finda () {
	ll l = 0 , r = 1e12 ; 
	while (l < r ) {
		ll m = (l + r + 1) >> 1 ; 
		if (pd(m) ) l = m ; 
		else r = m - 1 ; 
	}
	int p = upper_bound (a + 1 , a + n + 1 , l) - a - 1 ; 
	if (a[p] > l ) return p - 1 ; 
	else return p ;   
}
signed main () {
	freopen ("crystal.in" , "r" , stdin ) ;
	freopen ("crystal.out" , "w" , stdout ) ;
	scanf ("%lld%lld" , &n , &m ) ; 
	for (int i = 1 ; i <= n ; i ++ ) scanf ("%lld" , &a[i] ) ;
	sort (a + 1 , a + n + 1 ) ; 
	printf ("%lld" , finda() ) ; 
	return 0 ; 
}
