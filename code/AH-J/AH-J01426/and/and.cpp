#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef bool bl;
typedef double db;
const ll N = 2e5 + 10;
ll n, m, ans = LLONG_MIN;
ll a[ N ], suma[ N ], sumb[ N ];
bl f1, f2 = true, f3 = true;
void dfs( ll u, ll sum, ll g ) {
	if ( g == m ) { ans = max( ans, sum ); return ; }
	if ( sum <= ans ) return ;
	for ( ll i = u; i <= n; ++i ) {
		if ( !g ) dfs( i + 1, a[ i ], g + 1 );
		else dfs( i + 1, sum & a[ i ], g + 1 );
	}
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio( false );
	cin.tie( 0 ), cout.tie( 0 );
	cin >> n >> m;
	for ( ll i = 1; i <= n; ++i ) {
		cin >> a[ i ]; bl f = false; ll sum = 1;
		if ( a[ i ] == 0 ) f = true;
		for ( ll i = 1; i <= 20; ++i ) {
			sum *= 2; if ( sum - 1 == a[ i ] ) f = true;
		} f1 = f;
		if ( a[ i ] >= 4 ) f3 = false;
		if ( a[ i ] != i - 1 ) f2 = false;
	} sort( a + 1, a + n + 1 );
	if ( n <= 20 ) {
		dfs( 1, 0, 0 ); cout << ans;
	} else if ( m == 1 ) {
		cout << a[ n ];
	} else if ( m == n ) {
		ans = a[ 1 ];
		for ( ll i = 2; i <= n; ++i ) ans &= a[ i ];
		cout << ans;
	} else if ( m == 2 ) {
		for ( ll i = 1; i <= n; ++i ) {
			for ( ll j = i + 1; j <= n; ++j ) {
				ans = max( ans, a[ i ] & a[ j ] );
			}
		} cout << ans;
	} else if ( m == n - 1 ) {
		suma[ 1 ] = a[ 1 ]; sumb[ n ] = a[ n ];
		for ( ll i = 2; i <= n; ++i ) suma[ i ] = suma[ i - 1 ] & a[ i ];
		for ( ll i = n - 1; i >= 1; --i ) sumb[ i ] = sumb[ i + 1 ] & a[ i ];
		for ( ll i = 2; i <= n - 1; ++i ) ans = max( ans, suma[ i - 1 ] & sumb[ i + 1 ] );
		cout << max( { ans, sumb[ 2 ], suma[ n - 1 ] } );
	} else if ( f1 ) {
		cout << a[ n - m + 1 ];
	} else if ( f2 ) {
		ans = a[ n ];
		for ( ll i = n - 1; i >= n - m + 1; --i ) {
			ans &= a[ i ];
		} cout << ans;
	} else if ( f3 ) {
		ll s1, s2, s3; s1 = s2 = s3 = 0;
		for ( ll i = 1; i <= n; ++i ) {
			s1 += ( a[ i ] == 1 );
			s2 += ( a[ i ] == 2 );
			s3 += ( a[ i ] == 3 );
		}
		if ( s3 >= m ) cout << 3;
		else if ( s2 >= m ) cout << 2;
		else cout << 1;
	} else {
		dfs( 1, 0, 0 ); cout << ans;
	}
	return 0;
}
