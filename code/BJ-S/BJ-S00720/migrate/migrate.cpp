#include<bits/stdc++.h>
using namespace std ;
const int N = 2e6 + 10 ;
int C , T , n , d , a[ N ] ;
namespace solve1{
    int cnt[ N ] , mn[ N ] ;
    inline void dfs1( int i , int step ){
        mn[ i ] = min( mn[ i ] , step ) ;
        for( int j = i + 1 ; j <= n && a[ i ] + d >= a[ j ] ; j++ ){
            dfs1( j , step + 1 ) ;
        }
    }
    inline void dfs2( int i , int step ){
        if( step == mn[ i ] ){
            cnt[ i ]++ ;
        }
        for( int j = i + 1 ; j <= n && a[ i ] + d >= a[ j ] ; j++ ){
            dfs2( j , step + 1 ) ;
        }
    }
    inline void work(){
        int res = 0 ;
        for( int i = 1 ; i <= n ; i++ ){
            for( int j = 1 ; j <= n ; j++ ){
                cnt[ j ] = 0 ;
                mn[ j ] = 1e9 ;
            }
            dfs1( i , 0 ) ;
            dfs2( i , 0 ) ;
            for( int j = i + 1 ; j <= n ; j++ ){
                if( cnt[ j ] == 2 ){
                    res++ ;
                }
            }
            /*for( int j = 1 ; j <= n ; j++ ){
                printf( "%d " , mn[ j ] ) ;
            }
            printf( "\n" ) ;*/
        }
        printf( "%d\n" , res ) ;
    }
}
int main(){
    freopen( "migrate.in" , "r" , stdin ) ;
    freopen( "migrate.out" , "w" , stdout ) ;
    scanf( "%d%d" , &C , &T ) ;
    while( T-- ){
        scanf( "%d%d" , &n , &d ) ;
        for( int i = 1 ; i <= n ; i++ ){
            scanf( "%d" , &a[ i ] ) ;
        }
        if( n <= 9 ){
            solve1::work() ;
        }
    }
    return 0 ;
}