#include<bits/stdc++.h>
#define FOR(i , a , b) for(int i = (a) ; i <= (int)(b) ; ++ i)
using namespace std ;
using ll = long long ;
const int N = 5005 ; 
ll x[N] ;
int dist[N][N] , cnt[N][N] ;
signed main(){
	freopen("migrate.in","r",stdin) ; 
	freopen("migrate.out","w",stdout) ; 
	ios::sync_with_stdio(false) , cin.tie(0) ; 
	int c , t ; cin >> c >> t ; 
	while(t --){
		ll ans = 0 ;
		memset(x , 0 , sizeof x) ; 
		ll n , d ; cin >> n >> d ;
		FOR(i , 1 , n) cin >> x[i] ; 
		if(n > 5000){
			cout << 0 << "\n" ; continue ;  
		}
		memset(dist , 0x3f3f3f3f , sizeof dist) ; 
		memset(cnt , 0 , sizeof cnt) ; 
		sort(x + 1 , x + n + 1) ; 
		FOR(i , 1 , n) FOR(j , i + 1 , n){
			if(abs(x[j] - x[i]) <= d) dist[i][j] = 1 /* , dist[j][i] = 1*/ ;  
		}
		FOR(i , 0 , n) dist[i][i] = 0 ; 
		FOR(k , 1 , n){
			FOR(i , 1 , n){
				FOR(j , 1 , n){
					if(k == i || k == j || i == j) continue ; 
					if(dist[i][j] == dist[i][k] + dist[k][j]){
						cnt[i][j] ++ ;
					} 
					else if(dist[i][j] > dist[i][k] + dist[k][j]){
						dist[i][j] = min(dist[i][j] , dist[i][k] + dist[k][j]) , cnt[i][j] = 1 ; 
					} 
				}
			} 
		}
		FOR(i , 1 , n) FOR(j , 1 , n) if(cnt[i][j] == 2) ans ++ ;
		cout << ans << "\n" ; 
	}
	return 0 ; 
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

0 1
7 666666666666666663
-1000000000000000000 -555555555555555558 -111111111111111116 111111111111111105 333333333333333326 555555555555555547 999999999999999989
*/
