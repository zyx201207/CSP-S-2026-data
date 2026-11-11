#include<bits/stdc++.h>
#define ll long long
using namespace std ;
const int N = 2e5 + 7 ;
int n , m ;
int f [ N ] ;
int main () {
	freopen ( "and.in" , "r" , stdin ) ;
	freopen ( "and.out" , "w" , stdout ) ;
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n >> m ;
	for ( int i = 1 , x ; i <= n ; i ++ ) {
		cin >> x ;
		for ( int j = m ; j >= 1 ; j -- ) {
			f [ j ] = max ( f [ j ] , ( f [ j - 1 ] & x ) ) ;
		}
		f [ 1 ] = max ( f [ 1 ] , x ) ;
	}
	cout << f [ m ] ;
	return 0;
}

