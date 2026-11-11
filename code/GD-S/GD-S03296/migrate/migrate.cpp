#include <bits/stdc++.h>
using namespace std ;

const int MAXN = 2e6 ;
const int N = MAXN + 10 ;

struct seg {
    int l , r ;
} ;

int n ;
long long d ;
long long a [ N ] ;
long long ans ;

void bfs ( ) ;

int main ( ) {
    freopen ( "migrate.in" , "r" , stdin ) ;
    freopen ( "migrate.out" , "w" , stdout ) ;
    ios :: sync_with_stdio ( false ) ; cin . tie ( 0 ) ; cout . tie ( 0 ) ;
    int c , t ;
    cin >> c >> t ;
    while ( t -- ) {
        cin >> n >> d ;
        for ( int i = 1 ; i <= n ; ++ i ) cin >> a [ i ] ;
        if ( n <= 3 ) {
            cout << "0\n" ;
            continue ;
        }
        ans = 0 ;
        bfs ( ) ;
        cout << ans << '\n' ;
    }
    return 0 ;
}

void bfs ( ) {
    queue < seg > q ;
    for ( int l = 1 , r = 4 ; r <= n ; ++ l , ++ r ) {
        if ( a [ l + 2 ] - a [ l ] <= d && a [ r ] - a [ l + 1 ] <= d ) {
            ++ ans ;
            q . push ( { l , r } ) ;
        }
    }
    while ( q . size ( ) ) {
        int l = q . front ( ) . l , r = q . front ( ) . r ;
        q . pop ( ) ;
        if ( l > 1 && a [ l + 1 ] - a [ l - 1 ] > d && a [ l ] - a [ l - 1 ] <= d ) {
            ++ ans ;
            q . push ( { l - 1 , r } ) ;
        }
        if ( r < n && a [ r + 1 ] - a [ r - 1 ] > d && a [ r + 1 ] - a [ r ] <= d ) {
            ++ ans ;
            q . push ( { l , r + 1 } ) ;
        }
    }
}
