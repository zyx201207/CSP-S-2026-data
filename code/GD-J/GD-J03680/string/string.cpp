#include <bits/stdc++.h>
using namespace std ;

const int MAXN = 2e5 ;
const int N = MAXN + 10 ;

struct num {
    char ch ;
    int cnt ;
} ;

num a [ N ] ;

int main ( ) {
    freopen ( "string.in" , "r" , stdin ) ;
    freopen ( "string.out" , "w" , stdout ) ;
    ios :: sync_with_stdio ( false ) ; cin . tie ( 0 ) ; cout . tie ( 0 ) ;
    int n ;
    cin >> n ;
    for ( int i = 1 ; i <= n ; ++ i ) cin >> a [ i ] . cnt >> a [ i ] . ch ;
    int l = 1 , r = n ;
    long long ans = 0 ;
    while ( l < r ) {
        int mi = min ( a [ l ] . cnt , a [ r ] . cnt ) ;
        a [ l ] . cnt -= mi ;
        a [ r ] . cnt -= mi ;
        if ( a [ l ] . ch != a [ r ] . ch ) 
            ans += mi ;
        if ( !a [ l ] . cnt ) ++ l ;
        if ( !a [ r ] . cnt ) -- r ;
    }
    cout << ans ;
    return 0 ;
}
