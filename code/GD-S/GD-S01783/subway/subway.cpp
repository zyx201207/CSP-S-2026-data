#include<bits/stdc++.h>
#define ll long long
using namespace std ;
const ll M = 5e5 + 7 ;
const ll Q_MAX = 1e5 + 7 ;
const ll N = 507 ;
ll c , n , m , D , Q ; 
ll k [ N ] ;
ll w [ M ] ;
ll d [ 2 * M + N ] ;
vector < ll > a [ N ] , t [ N ] ;
struct question {
	ll s , t , id , res ;
} dif [ Q_MAX ] ;
struct edge {
	ll x , len ;
};
vector < edge > e [ 2 * M + N ] ;
struct node {
	ll x , d ;
	bool friend operator < ( node _x , node _y ) {
		return _x . d < _y . d ;
	}
};
priority_queue < node > q ;
void dis ( ll s ) {
	for ( ll i = 1 ; i <= 2 * m + n ; i ++ ) {
		d [ i ] = 1e18 ;
	}
	d [ s ] = 0 ;
	q . push ( { s , 0 } ) ;
	while ( ! q . empty () ) {
		ll _x = q . top () . x ;
		ll _d = q . top () . d ;
		q . pop () ;
		if ( _d != d [ _x ] ) continue ;
		for ( edge g : e [ _x ] ) {
			if ( _d + g . len < d [ g . x ] ) {
				d [ g . x ] = _d + g . len ;
				q . push ( { g . x , d [ g . x ] } ) ;
			}
		}
	}
}
bool cmp_s ( question _x , question _y ) {
	return _x . s < _y . s ;
}
bool cmp_id ( question _x , question _y ) {
	return _x . id < _y . id ;
}
int main () {
	freopen ( "subway.in" , "r" , stdin ) ;
	freopen ( "subway.out" , "w" , stdout ) ;
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> c >> n >> m >> D >> Q ;
	for ( ll i = 1 , w ; i <= m ; i ++ ) {
		cin >> w ;
		e [ i ] . push_back ( { i + m , w } ) ;
		e [ i + m ] . push_back ( { i , w } ) ;
	}
	for ( ll i = 1 ; i <= n ; i ++ ) {
		cin >> k [ i ] ;
		for ( ll j = 1 , _a , _t ; j <= k [ i ] ; j ++ ) {
			cin >> _a >> _t ;
			e [ 2 * m + i ] . push_back ( { _a + m , _t } ) ;
			e [ _a + m ] . push_back ( { 2 * m + i , _t } ) ;
		}
	}
	for ( ll i = 1 , s , t ; i <= Q ; i ++ ) {
		cin >> s >> t ;
		dif [ i ] . s = min ( s , t ) ;
		dif [ i ] . t = max ( s , t ) ;
		dif [ i ] . id = i ;
	}
	sort ( dif + 1 , dif + 1 + Q , cmp_s ) ;
	ll st = -1 ;
	for ( ll i = 1 ; i <= Q ; i ++ ) {
		if ( st != dif [ i ] . s ) {
			dis ( dif [ i ] . s ) ;
			st = dif [ i ] . s ;
		}
		dif [ i ] . res = d [ dif [ i ] . t ] ;
	}
	sort ( dif + 1 , dif + 1 + Q , cmp_id ) ;
	for ( ll i = 1 ; i <= Q ; i ++ ) {
		cout << dif [ i ] . res << '\n' ;
	}
	return 0 ;
}
