#include <iostream>
#include <cstring>
using namespace std ;

#define int long long

const int N = 510 ,M = 500010 ;
int c ,n ,m ,d ,q ;
int w[M] ;
int g[N][N] ;
bool st[N] ;

void solve() {
	for (int k = 1 ; k <= n ; k ++ )
		for (int i = 1 ; i <= n ; i ++ )
			for (int j = 1 ; j <= n ; j ++ )
				g[i][j] = min(g[i][j] ,g[i][k] + g[k][j] ) ;
}

signed main() {
	freopen("subway.in" ,"r" ,stdin ) ;
	freopen("subway.out" ,"w" ,stdout ) ;
	
	memset(g ,0x3f ,sizeof g ) ;
	
	scanf("%lld%lld%lld%lld%lld" ,&c ,&n ,&m ,&d ,&q ) ;
	for (int i = 1 ; i <= m ; i ++ )
		scanf("%lld" ,&w[i] ) ;
	
	for (int i = 1 ; i <= n ; i ++ ) {
		int k ;
		scanf("%lld" ,&k ) ;
		while (k -- ) {
			int a ,t1 ,b ,t2 ;
			scanf("%lld%lld%lld%lld" ,&a ,&t1 ,&b ,&t2 ) ;
			g[a][b] = g[b][a] = min(t1 + t2 ,g[a][b] ) ;
		}
	}
	
	solve() ;
	
	while (q -- ) {
		int a ,b ;
		scanf("%lld%lld" ,&a ,&b ) ;
		
		printf("%lld\n" ,g[a][b] ) ;
	}
	
	return 0 ;
}
