#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 9;
long long c, t, n, d;
long long a[ N ];
int main ( ) {
    ios::sync_with_stdio( 0 );
    cin.tie( );
    cout.tie( );
    freopen( "migrate.in", "r", stdin );
    freopen( "migrate.out", "w", stdout );
    ios::sync_with_stdio( 0 );
    cin.tie( 0 );
    cout.tie( 0 );
    cin >> c >> t;
    while ( t-- ) {
        int f = 1, sn;
        int fl = 1, sm;
        cin >> n >> d;
        for ( int i = 1; i <= n; i++ ) {
            cin >> a[ i ];
            if ( a[ i ] - a[ i - 1 ] != sn && i != 1 && i != 2 ) {
                f = 0;
            } else if ( i == 2 ) {
                sn = a[ i ] - a[ i - 1 ];
            }
        }
        if ( f ) {
            if ( sn > d ) {
                cout << 0 << endl;
            } else {
                long long ssum = 0, dp[ N ];
                for ( int i = 1; i <= d / sn; i++ ) {
                    dp[ i ] = dp[ i - 1 ] * 2;
                    ssum += ( n - i ) * dp[ i ];
                }
                cout << ssum << endl;
            }
            continue;
        }
        cout << n + d << endl;
    }
    return 0;
}
