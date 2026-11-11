#include <iostream>
#include <cstdio>
#include <unordered_map>
#include <vector>
#include <cstring>

using namespace std;
using ll = long long;

int constexpr N = 5e5 + 5, M = 3e5 + 5;
int a[ N ], ans[ M ], index[ M ];
int main() {
	freopen( "card.in", "r", stdin );
	freopen( "card.out", "w", stdout );
	ios::sync_with_stdio( false ), cin.tie( 0 );

	int n, m; cin >> n >> m;
	for ( int i = 1; i <= n; ++i ) { cin >> a[ i ]; }
	for ( int role = 1; role <= n; ++role ) {
		memset( index, -1, sizeof( index ) );
		vector<int> table;
		for ( int card = role; card <= n; ++card ) {
			int k = a[ card ], start = index[ k ];
			if ( start == -1 ) {
				table.push_back( card );
				index[ k ] = table.size() - 1;
			} else {
				for ( int i = start; i < table.size(); ++i )
				{ index[ a[ table[ i ] ] ] = -1; }
				table.resize( start );
				table.push_back( card );
				index[ k ] = table.size() - 1;
			}
 		}
 		for ( int card : table ) { ++ans[ a[ card ] ]; }
	}
	bool space = false;
	for ( int i = 1; i <= m; ++i ) {
		if ( space ) { cout << ' '; }
		else { space = true; }
		cout << ans[ i ];
	}
	cout << '\n';
	return 0;
}

