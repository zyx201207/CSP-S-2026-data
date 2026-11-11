#include <bits/stdc++.h>
using namespace std ;

const int MAXN = 5e5 ;
const int N = MAXN + 10 ;

long long a [ N ] , pre [ N ] , b [ N ] ;

int can ( int x , int n , int m ) ;

int main ( ) {
    freopen ( "crystal.in" , "r" , stdin ) ;
    freopen ( "crystal.out" , "w" , stdout ) ;
    // freopen ( "crystal.err" , "w" , stderr ) ;
    ios :: sync_with_stdio ( false ) ; cin . tie ( 0 ) ; cout . tie ( 0 ) ;
    int n ;
    long long m ;
    cin >> n >> m ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a [ i ] ;
    }
    sort ( a + 1 , a + n + 1 ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        pre [ i ] = pre [ i - 1 ] - a [ n - i + 1 ] ;
        if ( i == 1 || a [ i ] != a [ i - 1 ] ) b [ ++ b [ 0 ] ] = a [ i ] ;
    }
    int ans = 0 ;
    for ( int i = 1 ; i <= b [ 0 ] ; ++ i ) {
        int t = can ( b [ i ] , n , m ) ;
        ans = max ( ans , t ) ;
    }
    cout << ans ;
    return 0 ;
}

int can ( int x , int n , int m ) {
    int l = 1 , r = n , t1 = 0 , t2 = n ;
    while ( l <= r ) {
        int mid = ( ( r - l ) >> 1 ) + l ;
        if ( x >= a [ mid ] ) l = ( t1 = mid ) + 1 ;
        else r = mid - 1 ;
    }
    l = n - t1 + 1 , r = n ;
    if ( !t1 ) return t1 ;
    long long delta = pre [ n - t1 ] ;
    // for ( int i = l ; i <= r ; ++ i ) cerr << pre [ i ] - delta + 1ll * ( i - l + 1 ) * x << " \n" [ i == r ] ;
    while ( l <= r ) {
        int mid = ( ( r - l ) >> 1 ) + l ;
        if ( m >= pre [ mid ] - delta + 1ll * ( mid - n + t1 ) * x ) l = ( t2 = mid ) + 1 ;
        else r = mid - 1 ;
    }
    return t2 - n + t1 ;
}
/*
-9 -17 -21 -23 -24
*/
