#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 9;
int n, m, ma;
int a[ N ];
int dp[ N ];
int f = 1;
signed main ( ) {
    ios::sync_with_stdio( 0 );
    cin.tie( 0 );
    cout .tie( 0 );
    freopen( "and.in", "r", stdin );
    freopen( "and.out", "w", stdout );
    cin >> n >> m;
    for ( int i = 1; i <= n; i++ ) {
        cin >> a[ i ];
        if ( !f ) {
            continue;
        }
        int kkl = a[ i ];
        if ( kkl % 2 == 0 && kkl != 0 ) {
               f  = 0;
               continue;
        }
        while ( kkl % 2 ) {
                kkl /= 2;
                if ( kkl % 2 == 0 && kkl != 0 ) {
                    f = 0;
                }
        }
    }
    if ( f ) {
        sort( a + 1, a + n + 1 );
        cout << a[ n - 2 ];
        return 0;
    }
    dp[ 1 ] = a[ 1 ];
    for ( int i = 1; i <= n; i++ ) {
        for ( int j = 1; j <= m; j++ ) {
            dp[ j ] = max( dp[ j - 1 ] & a[ i ], dp[ j ] );
    //cout << dp[ i ][ j ] << " ";
            if ( j == m ) {
                ma = max( ma, dp[ j ] );
            }
        }
        dp[ 1 ] = a[ i ];
        //out << endl;
    }
    cout << ma;
    return 0;
}