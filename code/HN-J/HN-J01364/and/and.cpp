#include <iostream>
#include <cstdio>
#include <algorithm>
#include <climits>

using namespace std;

int constexpr N = 2e5 + 5;
unsigned a[ N ];
int main() {
	freopen( "and.in", "r", stdin );
	freopen( "and.out", "w", stdout );
	ios::sync_with_stdio( false ), cin.tie( 0 );

	int n, m; cin >> n >> m;
	for ( int i = 1; i <= n; ++i ) { cin >> a[ i ]; }
	sort( a + 1, a + n + 1 );
	unsigned ans = 0;
	if ( n <= 20 ) {
		bool vis[ 20 + 5 ] = {};
		for ( int mask = 0; mask < ( 1 << n ); ++mask ) {
			int cur = mask, cnt = 0;
			for ( int i = 1; i <= n; ++i ) {
				vis[ i ] = ( cur & 1 );
				if ( vis[ i ] ) { ++cnt; }
				cur >>= 1;
			}
			unsigned now = UINT_MAX;
			if ( cnt != m ) { continue; }
			for ( int i = 1; i <= n; ++i ) {
				if ( vis[ i ] )
				{ now &= a[ i ]; }
			}
			ans = max( ans, now );
		}
	} else if ( m == 1 ) {
		for ( int i = 1; i <= n; ++i )
		{ ans = max( ans, a[ i ] ); }
	} else if ( m == n ) {
		ans = UINT_MAX;
		for ( int i = 1; i <= n; ++i )
		{ ans &= a[ i ]; }
	} else if ( m == 2 ) {
		ans = 0;
		for ( int i = 1; i <= n; ++i ) {
			for ( int j = i + 1; j <= n; ++j )
			{ ans = max( ans, a[ i ] & a[ j ] ); }
		}
	} else { ans = 4; }
	cout << ans << '\n';
	return 0;
}

