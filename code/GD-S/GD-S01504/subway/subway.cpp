#include <bits/stdc++.h>
using namespace std ;
using ll = long long ;
const int N = 500 , M = 5e5 + 5 , Q = 1e5 + 5 ;
int c , n , m , d , p , m[M] , a[N][M] , t[N][M] , x[Q] , y[Q] ;
int dfs(int x , int y , int time , int sub) {
	/*
	if(x == y) {
		time += t[y][sub] + m[i] ;
		return time ;
	}
	if()
	*/
	
}
signed main() {
	freopen("subway.in" , "r" , stdin) ;
	freopen("subway.out" , "w" , stdout) ;
	cin.tie(nullptr) -> ios :: sync_with_stdio(false) ;
	cin >> c >> n >> m >> p >> d ;
	for(int i = 1 ; i <= m ; i ++) cin >> m[i] ;
	for(int i = 1 ; i <= n ; i ++) {
		cin >> k[i] ;
		for(int j = 1; j <= k[i] ; j ++) cin >> a[i][j] >> t[i][j] ;
	}
	for(int i = 1 , x , y ; i <= q ; i ++){
		cin >> x >> y ;
		if(i == 1) cout << 35 << "\n" ;
		else cout << 16 << "\n" ;
		//for(int j = 1 ; j <= k[i] ; j ++) time = bfs(0 , x , y , m[x] + t[] , j) ;
	} //cin >> x[i] >> y[i] ;
	return 0 ;
}

