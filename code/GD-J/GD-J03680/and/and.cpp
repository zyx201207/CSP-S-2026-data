#include <bits/stdc++.h>
using namespace std ;

const int MAXN = 2e5 ;
const int N = MAXN + 10 ;

int a [ N ] , tmp [ N ] ;

bool check ( int m , int k ) ;

int main ( ) {
    freopen ( "and.in" , "r" , stdin ) ;
    freopen ( "and.out" , "w" , stdout ) ;
    // freopen ( "err.txt" , "w" , stderr ) ;
    ios :: sync_with_stdio ( false ) ; cin . tie ( 0 ) ; cout . tie ( 0 ) ;
    int n , m ;
    cin >> n >> m ;
    a [ 0 ] = n ;
    for ( int i = 1 ; i <= n ; ++ i ) cin >> a [ i ] ;
    for ( int i = 30 ; i >= 0 ; -- i ) {
        if ( check ( m , i ) ) {
            // cerr << "ok ------ ";
            a [ 0 ] = tmp [ 0 ] ;
            for ( int j = 1 ; j <= tmp [ 0 ] ; ++ j ) a [ j ] = tmp [ j ] ;
        }
        // for ( int i = 1 ; i <= a [ 0 ] ; ++ i ) cerr << a [ i ] << " \n" [ i == a [ 0 ] ] ;
    }
    int ans = a [ 1 ] ;
    for ( int i = 2 ; i <= a [ 0 ] ; ++ i ) ans &= a [ i ] ;
    cout << ans ;
    return 0 ;
}

bool check ( int m , int k ) {
    k = 1 << k ;
    tmp [ 0 ] = 0 ;
    for ( int i = 1 ; i <= a [ 0 ] ; ++ i ) if ( a [ i ] & k ) tmp [ ++ tmp [ 0 ] ] = a [ i ] ;
    return tmp [ 0 ] >= m ;
}
