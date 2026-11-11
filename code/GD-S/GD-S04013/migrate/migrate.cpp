#include<bits/stdc++.h>
using namespace std ;
long long c , t , n , d , x[5005] , dist[5005][5005] , f[5005][5005] ;
int main(){
	freopen( "migrate.in" , "r" , stdin ) ;
	freopen( "migrate.out" , "w" , stdout ) ;
	cin >> c >> t ;
	while( t-- ){
		cin >> n >> d ;
		for( int i = 1 ; i <= n ; i++ ){
			cin >> x[i] ;
		}
		memset( dist , 0 , sizeof(dist) ) ;
		memset( f , 0 , sizeof(dist) ) ;
		for( int i = 1 ; i <= n ; i++ ){
			for( int j = i + 1 ; j <= n ; j++ ){
				if( x[j] - x[i] <= d ){
					dist[i][j] = x[j] - x[i] ;
					dist[j][i] = dist[i][j] ;
				}
			}
		}
		long long ans = 0 ;
		for( int i = 1 ; i <= n ; i++ ){
			for( int j = 1 ; j <= n ; j++ ){
				for( int x = 1 ; x <= n ; x++ ){
					if( dist[i][j] == dist[i][x] + dist[x][j] ){
						if( f[i][j] == 0 ){
							f[i][j] = 1 ;
							ans++ ;
						}else if( f[i][j] == 1 ){
							f[i][j] = 2 ;
							ans-- ;
						}
					}
					dist[i][j] = min( dist[i][j] , dist[i][x] + dist[x][j] ) ;
					dist[j][i] = dist[i][j] ;
				}
			}
		}
		cout << ans << endl ;
	}
	return 0 ;
}
