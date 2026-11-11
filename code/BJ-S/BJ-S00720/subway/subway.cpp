#include<bits/stdc++.h>
using namespace std ;
const int N = 510 , M = 5e5 + 10 ;
int C , n , m , d , q ;
int w[ M ] , l[ N ] , g[ N ][ N ] , t[ N ][ M ] ;
long long dist[ N ][ N ] ;
vector<pair<int,int>> edges[ M ] , edges1[ N ] ;
bool b[ N ] ;
inline void dijkstra( int st ){
    for( int i = 1 ; i <= n ; i++ ){
        dist[ st ][ i ] = 1LL << 62 ;
        b[ i ] = 0 ;
    }
    dist[ st ][ st ] = 0 ;
    while( true ){
        int u = 0 ;
        for( int i = 1 ; i <= n ; i++ ){
            if( !b[ i ] && ( u == 0 || dist[ st ][ i ] < dist[ st ][ u ] ) ){
                u = i ;
            }
        }
        if( u == 0 ){
            break ;
        }
        for( auto v : edges1[ u ] ){
            dist[ st ][ v.first ] = min( dist[ st ][ v.first ] , dist[ st ][ u ] + v.second ) ;
        }
        b[ u ] = 1 ;
    }
}
int main(){
    freopen( "subway.in" , "r" , stdin ) ;
    freopen( "subway.out" , "w" , stdout ) ;
    scanf( "%d%d%d%d%d" , &C , &n , &m , &d , &q ) ;
    for( int i = 1 ; i <= m ; i++ ){
        scanf( "%d" , &w[ i ] ) ;
    }
    for( int i = 1 ; i <= n ; i++ ){
        scanf( "%d" , &l[ i ] ) ;
        for( int j = 1 ; j <= l[ i ] ; j++ ){
            int x , y ;
            scanf( "%d%d" , &x , &y ) ;
            t[ i ][ x ] = y ;
            edges[ x ].push_back( { i , y } ) ;
        }
    }
    for( int i = 1 ; i <= n ; i++ ){
        for( int j = 1 ; j <= n ; j++ ){
            g[ i ][ j ] = INT_MAX ;
        }
    }
    for( int i = 1 ; i <= m ; i++ ){
        for( auto u : edges[ i ] ){
            for( auto v : edges[ i ] ){
                if( u.first != v.first ){
                    g[ u.first ][ v.first ] = min( g[ u.first ][ v.first ] , u.second + v.second ) ;
                }
            }
        }
    }
    for( int i = 1 ; i <= n ; i++ ){
        for( int j = 1 ; j <= n ; j++ ){
            //printf( "%lld " , g[ i ][ j ] ) ;
            if( g[ i ][ j ] != INT_MAX ){
                edges1[ i ].push_back( { j , g[ i ][ j ] } ) ;
            }
        }
        //printf( "\n" ) ;
    }
    for( int i = 1 ; i <= n ; i++ ){
        dijkstra( i ) ;
    }
    while( q-- ){
        int x , y ;
        scanf( "%d%d" , &x , &y ) ;
        long long ans = 1LL << 62 ;
        for( auto u : edges[ x ] ){
            for( auto v : edges[ y ] ){
                //printf( "line%d->%d %lld\n" , u.first , v.first ,dist[ u.first ][ v.first ] ) ;
                ans = min( ans , w[ x ] + w[ y ] + dist[ u.first ][ v.first ] + t[ u.first ][ x ] + t[ v.first ][ y ] ) ;
            }
        }
        printf( "%lld\n" , ans ) ;
    }
    return 0 ;
}