#include<bits/stdc++.h>
#define FOR(i , a , b) for(int i = (a) ; i <= (int)(b) ; ++ i)
using namespace std ;
using ll = long long ;
const int N = 1010 ; 
ll w[N] , a[N] ; 
ll g[N][N] ; 
signed main(){
	freopen("subway.in","r",stdin) ; 
	freopen("subway.out","w",stdout) ; 
	ios::sync_with_stdio(false) , cin.tie(0) ; 
	int c , n , m , d , q ; cin >> c >> n >> m >> d >> q ;
	memset(g , 0x3f , sizeof g) ;
	FOR(i , 1 , m) cin >> w[i] ;
	FOR(i , 1 , n){
		int k ; cin >> k ; 
		FOR(j , 1 , k){
			ll t ; cin >> a[j] >> t ;
			g[m + i][a[j]] = t , g[a[j]][m + i] = t ;  
		}
	}
//	FOR(i , 1 , 2 * m) g[i][i] = 0 ; 
	FOR(k , 1 , m + n){
		FOR(i , 1 , m + n){
			FOR(j , 1 , m + n){
				g[i][j] = min(g[i][j] , g[i][k] + g[k][j]) ;
			}
		}
	}
//	FOR(i , 1 , 2 * m){
//		FOR(j , 1 , 2 * m){
//			cout << g[i][j] << " " ;
//		}
//		cout << "\n" ; 
//	} 
	FOR(i , 1 , q){
		int x , y ; cin >> x >> y ;
		ll ans = w[x] + w[y] + g[x][y] ; 
		cout << ans << "\n" ; 
	}
	return 0 ; 
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

1 ~ n 表示站厅
n + 1 ~ 2n + 1 表示站台

0 8 9 11 12 5 5 5 5 5
8 0 7 9 10 3 3 3 3 3
9 7 0 10 11 4 4 4 4 4
11 9 10 0 13 6 6 6 6 6
12 10 11 13 0 7 7 7 7 7
5 3 4 6 7 0 0 0 0 0
5 3 4 6 7 0 0 0 0 0
5 3 4 6 7 0 0 0 0 0
5 3 4 6 7 0 0 0 0 0
5 3 4 6 7 0 0 0 0 0
*/
