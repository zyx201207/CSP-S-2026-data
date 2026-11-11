#include <bits/stdc++.h> 
using namespace std ; 
const int N = 510 , M = 5e3 +10 ; 
int d[M][M] ; 
int x[M] ; 
int c , n , m , q ;
int dp ;  
long long w[M] ;  
void bt () {
	for (int k = 1 ; k <= m ; k ++ ) {
		for (int i = 1 ; i <= n ; i ++ ) if (i != k) {
			for (int j = 1 ; j <= m ; j ++ ) if (j != i && j != k ) {
				d[i][j] = min (d[i][j] , d[i][k] + d[k][j] ) ; 
			}
		}
	} 
}
int main () {
	freopen ("subway.in" , "r" , stdin ) ; 
	freopen ("subway.out" , "w" , stdout ) ;
	scanf ("%d%d%d%d%d" , &c , &n , &m , &dp , &q ) ; 
	for (int i = 1 ; i <= m ; i ++ ) memset (d[i] , 0x3f , sizeof (d[i])) ; 
	for (int i = 1 ; i <= m ;  i++ ) scanf ("%lld" , &w[i] ) ;
	for (int i = 1 ; i <= n ; i ++ ) {
		int k ; 
		scanf ("%d" , &k ) ; 
		for (int j = 1 ; j <= k ; j ++ ) {
			int t ; 
			scanf ("%d%d" , &x[j] , &t ) ;  
			for (int l = 1 ; l < j ; l ++  ) {
				d[x[l]][x[j]] = min (d[x[l]][x[j]] , t) ;  
				d[x[j]][x[l]] = d[x[l]][x[j]] ; 
			}
		}
	}
	bt () ; 
	for (int i = 1 ; i <= q ; i ++ ) {
		int x , y ; scanf ("%d%d" , &x , &y ) ; 
		printf ("%lld\n" , d[x][y] + w[x] + w[y] ) ;
	}
	return 0 ; 
}
