#include <bits/stdc++.h>
using namespace std ;

const int MAXM = 5e5 , MAXNM = 5e5 + 500 ;
const int M = MAXM + 10 , NM = MAXNM + 10 , E = ( MAXNM << 1 ) + 10 , LOGNM = 20 ;

struct EDGE {
    int u , v , w ;
    bool operator < ( const EDGE &other ) const {
        return w > other . w ;
    }
} ;
struct edge {
    int to , nxt , w ;
} ;

int w [ M ] ;
int fa [ NM ] ;
int head [ NM ] , cnt_edge ;
edge e [ E ] ;
int pre [ NM ] [ LOGNM ] , dep [ NM ] ;
long long sum [ NM ] ;
priority_queue < EDGE > pq ;

int find ( int x ) ;
bool merge ( int x , int y ) ;
void add ( int u , int v , int w ) ;
void dfs ( int p , int parent ) ;
void init ( int p ) ;
int lca ( int x , int y ) ;

int main ( ) {
    freopen ( "subway.in" , "r" , stdin ) ;
    freopen ( "subway.out" , "w" , stdout ) ;
    // freopen ( "subway.err" , "w" , stderr ) ;
    ios :: sync_with_stdio ( false ) ; cin . tie ( 0 ) ; cout . tie ( 0 ) ;
    int c , n , m , d , q , nm ;
    cin >> c >> n >> m >> d >> q ;
    nm = n + m ;
    memset ( head , -1 , sizeof ( head ) ) ;
    for ( int i = 1 ; i <= nm ; ++ i ) fa [ i ] = i ;
    for ( int i = 1 ; i <= m ; ++ i ) cin >> w [ i ] ;
    for ( int i = 1 , k ; i <= n ; ++ i ) {
        cin >> k ;
        for ( int j = 1 , v , w ; j <= k ; ++ j ) {
            cin >> v >> w ;
            pq . push ( { m + i , v , w } ) ;
        }
    }
    while ( pq . size ( ) ) {
        int u = pq . top ( ) . u , v = pq . top ( ) . v , w = pq . top ( ) . w ;
        pq . pop ( ) ;
        if ( merge ( u , v ) ) add ( u , v , w ) ;
    }
    dfs ( m + 1 , 0 ) ;
    while ( q -- ) {
        int x , y ;
        cin >> x >> y ;
        cout << w [ x ] + w [ y ] - ( sum [ lca ( x , y ) ] << 1 ) + sum [ x ] + sum [ y ] << '\n' ;
    }
    return 0 ;
}

int find ( int x ) {
    if ( fa [ x ] == x ) return x ;
    return fa [ x ] = find ( fa [ x ] ) ;
}

bool merge ( int x , int y ) {
    int fx = find ( x ) , fy = find ( y ) ;
    if ( fx == fy ) return 0 ;
    fa [ fy ] = fx ;
    return 1 ;
}

void add ( int u , int v , int w ) {
    e [ cnt_edge ] = { v , head [ u ] , w } ;
    head [ u ] = cnt_edge ++ ;
    e [ cnt_edge ] = { u , head [ v ] , w } ;
    head [ v ] = cnt_edge ++ ;
}

void dfs ( int p , int parent ) {
    pre [ p ] [ 0 ] = parent ;
    dep [ p ] = dep [ parent ] + 1 ;
    init ( p ) ;
    for ( int i = head [ p ] ; ~i ; i = e [ i ] . nxt ) {
        if ( e [ i ] . to == parent ) continue ;
        sum [ e [ i ] . to ] = sum [ p ] + e [ i ] . w ;
        dfs ( e [ i ] . to , p ) ;
    }
}

void init ( int p ) {
    for ( int j = 1 ; j <= 19 ; ++ j ) pre [ p ] [ j ]= pre [ pre [ p ] [ j - 1 ] ] [ j - 1 ] ;
}

int lca ( int x , int y ) {
    if ( dep [ x ] > dep [ y ] ) swap ( x , y ) ;
    for ( int i = 19 ; i >= 0 ; -- i ) 
        if ( dep [ x ] <= dep [ pre [ y ] [ i ] ] ) y = pre [ y ] [ i ] ;
    if ( x == y ) return x ;
    for ( int i = 19 ; i >= 0 ; -- i ) 
        if ( pre [ x ] [ i ] != pre [ y ] [ i ] ) x = pre [ x ] [ i ] , y = pre [ y ] [ i ] ;
    return pre [ x ] [ 0 ] ;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100             
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
