#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 9;
struct node {
    int num;
    long long time;
};
int c, n, m, d, q;
int w[ N ], f[ N ];
int tp, ff;
queue< node > tpy;
vector< node > g[ N ];
vector< node > t[ N ];
long long ans = INT_MAX;
void dfs( int x, int en, long long sum ) {
    if ( f[ x ] ) {
        return ;
    }
    if ( x == en ) {
        ans = min( ans, sum );
        return ;
    }
    f[ x ] = 1;
    //cout << sum << endl;
    for ( int i = 0; i < g[ x ].size( ); i++ ) {
        //f[ g[ x ][ i ].num ] = 1;
        //cout << "abcluzhuanfen" << endl;
        dfs( g[ x ][ i ].num, en, sum + g[ x ][ i ].time );
        //f[ g[ x ][ i ].num ] = 0;
    }
    f[ x ] = 0;
}
long long bfs( int st, int en ) {
    tpy.push( { st, 0 } );
    f[ st ] = 1;
    node toop;
    while ( !tpy.empty( ) ) {
        toop = tpy.front( );
        tpy.pop( );
        for ( int i = 0; i < g[ toop.num ].size ( ); i++ ) {
            int too = g[ toop.num ][ i ].num;
            f[ too ] = 1;
            tpy.push( { too, g[ toop.num ][ too ].time + toop.time } );
        }
    }
    return toop.time;
}
int main ( ) {
    ios::sync_with_stdio( 0 );
    cin.tie( 0 );
    cout.tie( 0 );
    freopen( "subway.in", "r", stdin );
    freopen( "subway.out", "w", stdout );
    cin >> c >> n >> m >> d >> q;
    for ( int i = 1; i <= m; i++ ) {
        cin >> w[ i ];
    }
    for ( int i = 1; i <= n; i++ ) {
        int k;
        cin >> k;
        for ( int j = 1; j <= k; j++ ) {
            int to, ti;
            if ( ( i != 1 || j != 1 )&& ff ) {
                if ( ti != tp ) {
                    ff = 0;
                }
            } else if ( i == 1 && j == 1 ) {
                tp = ti;
            }
            cin >> to >> ti;
            t[ i ].push_back( { to, ti } );
            for ( int k = 0; k < t[ i ].size( ) - 1; k++ ) {
                g[ to ].push_back( { t[ i ][ k ].num, t[ i ][ k ].time + ti } );
                g[ t[ i ][ k ].num ].push_back( { to, t[ i ][ k ].time + ti } );
            }
        }
    }
    long long sum = 0;
    if ( ff ) {
        while ( q-- ) {
            int st, en;
            cin >> st >> en;
            sum += w[ st ] + w[ en ];
            cout << sum + bfs( st, en ) << endl;
            sum = 0;
        }
        return 0;
    }
    for ( int i = 1; i <= q; i++ ) {
        int st, en;
        cin >> st >> en;
        sum += w[ st ] + w[ en ];
        dfs( st, en, 0 );
        cout << sum + ans << endl;
        ans = INT_MAX;
        sum = 0;
    }
    return 0;
}
