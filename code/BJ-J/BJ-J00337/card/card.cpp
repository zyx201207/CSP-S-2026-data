#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 9;
int n, m, f = 1;
int a[ N ];
int t[ N ];
int num[ N ];
int t2[ N ];
int g[ N ];
int main ( ) {
    ios::sync_with_stdio( 0 );
    cin.tie( 0 );
    cout .tie( 0 );
    freopen( "card.in", "r", stdin );
    freopen( "card.out", "w", stdout );
    cin >> n >> m;
    for ( int i = 1; i <= n; i++ ) {
        cin >> a[ i ];
        if ( t[ a[ i ] ] ) {
            g[ i ] = num[ a[ i ] ];
            num[ a[ i ] ] = i;
            t[ a[ i ] ]++;
        } else {
            t[ a[ i ] ] = 1;
            num[ a[ i ] ] = i;
        }
        if ( a[ i ] > a[ i - 1 ] ) {
            f = 0;
        }
    }
    if ( f ) {
        for ( int i = 1; i <= n; i++ ) {
            if ( a[ i ] == a[ i - 1 ] ) {
                    t2[ a[ i ] ] = 1;
            } else {
                t2[ a[ i ] ] += i;
            }
        }
        for ( int i = 1; i <= m; i++ ) {
            cout << t2[ i ] << " ";
        }
        cout << endl;
        return 0;
    }
    /*
    for ( int i = 1; i <= m; i++ ) {
        cout << t[ i ] << " ";
    }
    cout << endl;
    */
    //cout << g[ 3 ] << endl;
    for ( int i = 1; i <= n; i++ ) {
        int start = i;
        for ( int j = i; j <= n; j++ ) {
            if ( t[ a[ j ] ] > 1 && g[ j ] >= i ) {
                for ( int k = i; k < g[ i ]; k++ ) {
                    t2[ a[ k ] ]++;
                }
                start = j;
            }
        }
        //cout << start << endl;
        for ( int j = start; j <= n; j++ ) {
            t2[ a[ j ] ]++;
        }
    }
    for ( int i = 1; i <= m; i++ ) {
        cout << t2[ i ] << " ";
    }
    cout << endl;
    return 0;
}