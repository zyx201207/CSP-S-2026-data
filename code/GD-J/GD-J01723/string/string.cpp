#include<bits/stdc++.h>
#define ll long long
using namespace std ;
const int N = 2e5 + 7 ;
int n ;
int a [ N ] ;
char c [ N ] ;
int main () {
	freopen ( "string.in" , "r" , stdin ) ;
	freopen ( "string.out" , "w" , stdout ) ;
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n ;
	for ( int i = 1 ; i <= n ; i ++ ) cin >> a [ i ] >> c [ i ] ;
	ll res = 0 ;
	int st = 1 , ed = n ;
	while ( st < ed ) {
		int t = min ( a [ st ] , a [ ed ] ) ;
		if ( c [ st ] != c [ ed ] ) {
			res += t ;
		}
		a [ st ] -= t ;
		a [ ed ] -= t ;
		if ( ! a [ st ] ) {
			st ++ ;
		}
		if ( ! a [ ed ] ) {
			ed -- ;
		}
	}
	cout << res ;
	return 0;
}
