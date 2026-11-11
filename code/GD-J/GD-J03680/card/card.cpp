#include <bits/stdc++.h>
using namespace std ;

const int MAXN = 5e5 , MAXM = 3e5 ;
const int N = MAXN + 10 , M = MAXM + 10 ;

int n ;
int a [ N ] ;
int parent [ N ] ;
vector < int > child [ N ] ;
int last [ M ] , first [ M ] ;
long long sz [ N ] ;

void add ( int x , int p ) ;
void dfs ( int p ) ;

int main ( ) {
    freopen ( "card.in" , "r" , stdin ) ;
    freopen ( "card.out" , "w" , stdout ) ;
    // freopen ( "err.txt" , "w" , stderr ) ;
    ios :: sync_with_stdio ( false ) ; cin . tie ( 0 ) ; cout . tie ( 0 ) ;
    int m ;
    cin >> n >> m ;
    for ( int i = 1 ; i <= n ; ++ i ) cin >> a [ i ] ;
    first [ a [ n ] ] = n ;
    last [ a [ n ] ] = n ;
    for ( int i = n ; i >= 1 ; -- i )
        add ( a [ i ] , i ) ;
    dfs ( n ) ;
    for ( int i = 1 ; i <= m ; ++ i ) cout << sz [ first [ i ] ] << ' ' ;
    return 0 ;
}

void add ( int x , int p ) {
    if ( p == n ) return ;
    if ( last [ x ] ) {
        parent [ p ] = last [ x ] ;
    }
    else {
        first [ x ] = p ;
        parent [ p ] = p + 1 ;
    }
    child [ parent [ p ] ] . push_back ( p ) ;
    last [ x ] = p ;
}

void dfs ( int p ) {
    sz [ p ] = 1 ;
    // cerr << p << ' ' ;
    for ( int to : child [ p ] ) {
        dfs ( to ) ;
        sz [ p ] += sz [ to ] ;
    }
}
