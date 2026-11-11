#include <bits/stdc++.h>
using namespace std ;
int m , w[500005] , d , c , n , q , b[2505][2505] ;
int main()
{
	freopen("subway.in" , "r" , stdin) ;
	freopen("subway.out" , "w" , stdout) ;
	cin >> c >> n >> m >> d >> q ;
	memset(b , 0x3f , sizeof(b)) ;
	for (int i = 1 ; i <= m ; i++) cin >> w[i] ;
	for (int i = 1 ; i <= n ; i++) {
		int k ;
		cin >> k ;
		for (int j = 1 ; j <= k ; j++){
			int x , t ;
			cin >> x >> t ;
			b[m + i][x] = t ;
			b[x][m + i] = t ;
		}
	}
	for (int k = m + 1 ; k <= m + n ; k++){
		for (int i = 1 ; i <= m ; i++) {
			for (int j = 1 ; j <= m ; j++){
				b[i][j] = min(b[i][j] , b[i][k] + b[k][j]) ;
				b[j][i] = b[i][j] ;
			}
		}
	}
	for (int k = 1 ; k <= m ; k++){
		for (int i = 1 ; i <= m ; i++) {
			for (int j = 1 ; j <= m ; j++){
				b[i][j] = min(b[i][j] , b[i][k] + b[k][j]) ;
				b[j][i] = b[i][j] ;
			}
		}
	}
	while(q--){
		int s , end1 ;
		cin >> s >> end1 ;
		int ans = b[s][end1] + w[s] + w[end1] ;
		cout << ans << endl ;
	}
	return 0 ;
}
