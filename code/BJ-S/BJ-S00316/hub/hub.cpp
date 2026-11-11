#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 9;
int c, t, n, k;
vector< int > g[ N ];
int main ( ){
    ios::sync_with_stdio( 0 );
    cin.tie( );
    cout.tie( );
    freopen( "hub.in", "r", stdin );
    freopen( "hub.out", "w", stdout );
    cin >> c >> t;
    while ( t-- ) {
        cin >> n >> k;
        bool f = 1;
        for ( int i = 1; i < n; i++ ) {
            int u, v;
            cin >> u >> v;
            g[ u ].push_back( v );
            g[ v ].push_back( u );
            if ( i <= n / 2 ) {
                if ( u != i || v != i + 1 ) {
                    f = 0;
                }
            } else {
                if ( u != ( i - ( n - 1 ) / 2 ) || v != i + 1 ) {
                    f = 0;
                }
            }
        }
        if ( f ) {
            if ( k == n ) {
                cout << 2 << endl;
            } else {
                cout << 1 << endl;
            }
        }
        cout << 2 + ( n - k ) % 2 << endl;
    }
    return 0;
}
