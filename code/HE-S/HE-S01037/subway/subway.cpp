#include "bits/stdc++.h"
#define int long long 
#define fi first 
#define se second 
#define f(i ,m ,n ,x) for (int i = (m) ,i##end = (n) ; i <= i##end ; i += (x))

const int N = 1e6 + 77 ,M = 777 ,inf = 1e18 ;
int c ,n ,m ,q ,DDD ,w[N] ,d[M][M] ;
std :: vector < std :: pair < int ,int > > sub[N] ; 

signed main (void) {
	//std :: cerr << system ("fc subway.out subway6.ans") << '\n' ;
	freopen ("subway.in" ,"r" ,stdin) ;
	freopen ("subway.out" ,"w" ,stdout) ;
	std :: ios_base :: sync_with_stdio (false) ,
	std :: cin.tie (nullptr) ,std :: cout.tie (nullptr) ;
	
	std :: cin >> c >> n >> m >> DDD >> q ;
	f (i ,1 ,m ,1) std :: cin >> w[i] ;
	f (i ,1 ,n ,1) {
		int k ; std :: cin >> k ;
		f (j ,1 ,k ,1) {
			int a ,t ; std :: cin >> a >> t ;
			sub[a].emplace_back (i ,t) ;
		}
	}
	
	f (i ,1 ,n ,1) f (j ,1 ,n ,1) d[i][j] = inf ;
	f (i ,1 ,n ,1) d[i][i] = 0 ;
	f (i ,1 ,m ,1) {
		int len = sub[i].size () ;
		f (j ,0 ,len - 1 ,1) f (k ,j + 1 ,len - 1 ,1) {
			auto &pr1 = sub[i][j] ,pr2 = sub[i][k] ;
			int i1 = pr1.fi ,i2 = pr2.fi ,t1 = pr1.se ,t2 = pr2.se ;
			d[i1][i2] = std :: min (d[i1][i2] ,t1 + t2) ;
			d[i2][i1] = std :: min (d[i2][i1] ,t1 + t2) ;
		}
	}
	
	//f (i ,1 ,n ,1) f (j ,1 ,n ,1) dis[i][j] = d[i][j] ;
	f (k ,1 ,n ,1) f (i ,1 ,n ,1) f (j ,1 ,n ,1) {
		if (d[i][k] == inf || d[k][j] == inf) continue ;
		d[i][j] = std :: min (d[i][j] ,d[i][k] + d[k][j]) ;
	}
	
	while (q --> 0) {
		int ans = inf ; int x ,y ; std :: cin >> x >> y ;
		for (const auto &pr1 : sub[x]) for (const auto &pr2 : sub[y])
			ans = std :: min (ans ,w[x] + w[y] + pr1.se + pr2.se + d[pr1.fi][pr2.fi]) ;
		std :: cout << ans << '\n' ;
	}
	
//	auto Dij = [] (int s) {
//		f (i ,1 ,n ,1) dis[s][i] = inf ;
//		dis[s][s] = 0 ; for (;;) {
//			int cur = 0 ,min = inf + 1 ;
//			f (i ,1 ,n ,1) {
//				if (vis[i]) continue ;
//			}
//		}
//	}
}
