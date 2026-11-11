#include<bits/stdc++.h>
using namespace std;

long long n ;
long long a[300000] ;
char c[300000] ;
long long m[300000] ;
long long l ;
long long ans ;
long long cnt ;

void jisuan() {
	for( long long i = 1 ; i <= n/2 ; i ++ ) {
		while( l - m[cnt-1] <= m[i] ) {
			if( c[i] != c[cnt] ) {
				ans = ans + a[cnt] ;
			}
			cnt -- ;
		}
		if( c[i] != c[cnt] ) {
			ans = ans + ( m[i] - (l - m[cnt]) ) ;
			a[cnt] = a[cnt] - ( m[i] - (l - m[cnt]) ) ;
		}
	}
	cout << ans ;
}

int main() {
	freopen( "string.in", "r", stdin ) ;
	freopen( "string.out", "w", stdout ) ;
	
	cin >> n ;
	m[0] = 0 ;
	for( long long i = 1 ; i <= n ; i ++ ) {
		cin >> a[i] >> c[i] ;
		m[i] = m[i-1] + a[i] ;
	}
	l = m[n] ;
	cnt = n ;
	jisuan() ;
	return 0 ;
}
