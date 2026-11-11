#include "bits/stdc++.h"
#define f(i ,m ,n ,x) for (int i = (m) ,i##end = (n) ; i <= i##end ; i += (x))

const int N = 1077 ;
int dep[N] ,fa[N] ,maxid[N] ,maxod[N] ,maxdep[N] ,n ,k ,v1[N] ,v2[N] ,tmp[N] ,siz[N] ,dp1[N][N] ,dp2[N][N] ,val1[N] ,val2[N] ;
std :: vector < int > adj[N] ;

signed main (void) {
	freopen ("hub.in" ,"r" ,stdin) ;
	freopen ("hub.out" ,"w" ,stdout) ;
	std :: ios_base :: sync_with_stdio (false) ,
	std :: cin.tie (nullptr) ,std :: cout.tie (nullptr) ;
	
	auto Pre1 = [] (auto &&self ,int cur ,int dad) -> void  {
		fa[cur] = dad ,maxdep[cur] = dep[cur] = dep[dad] + 1 ,siz[cur] = 1 ;
		for (auto nex : adj[cur]) {
			if (nex == dad) continue ;
			self (self ,nex ,cur) ,maxdep[cur] = std :: max (maxdep[cur] ,maxdep[nex]) ;
			siz[cur] = 1 ; 
		} maxid[cur] = maxdep[cur] - dep[cur] ;
	} ;
	
	auto Pre2 = [] (auto &&self ,int cur) -> void {
		std :: vector < int > son ,pre ,suf ;
		for (auto nex : adj[cur]) if (nex != fa[cur]) son.emplace_back (nex) ;
		for (auto x : son) pre.emplace_back (maxid[x] + 1) ;
		std :: reverse (son.begin () ,son.end ()) ;
		for (auto x : son) suf.emplace_back (maxid[x] + 1) ;
		std :: reverse (son.begin () ,son.end ()) ;
		int m = son.size () ;
		//assert (pre.size () == m && suf.size () == m) ;
		f (i ,1 ,m - 1 ,1) pre[i] = std :: max (pre[i] ,pre[i - 1]) ;
		f (i ,1 ,m - 1 ,1) suf[i] = std :: max (suf[i] ,suf[i - 1]) ;
		//if (cur == 1) std :: cerr << son[0] << ' ' << son[1] << ' ' << pre[0] << ' ' << pre[1] << ' ' << suf[0] << ' ' << suf[1] << '\n' ;
		f (i ,0 ,m - 1 ,1) {
			int mx = i ? pre[i - 1] : 0 ;
			if (i != m - 1) mx = std :: max (mx ,suf[m - 2 - i]) ;
			maxod[son[i]] = std :: max (mx + 1 ,maxod[cur] + 1) ;
 		} for (auto x : son) self (self ,x) ;
	} ;
	
	auto Solve1 = [] (auto &&self ,int cur ,int d) -> void {
		if (maxid[cur] + 1 > d) v1[cur] = 1 ; 
		if (maxid[cur] + 2 > d) tmp[cur] = 1 ;
		for (auto nex : adj[cur])
		if (nex != fa[cur]) self (self ,nex ,d) ,v1[cur] += v1[nex] ,tmp[cur] += tmp[nex] ;
	} ;
	
	auto Solve2 = [] (auto &&self ,int cur ,int d) -> void {
		if (maxod[cur] + 1 > d) {
			bool flag = !v2[fa[cur]] ;
			for (auto nex : adj[fa[cur]]) if (nex != fa[fa[cur]] && nex != cur) if (tmp[cur]) flag = true ;
			if (!flag) v2[cur] = 1 ; 
			else {
				v2[cur] = std :: max (2 ,v2[fa[cur]] + 1) ;
				for (auto nex : adj[fa[cur]]) if (nex != fa[fa[cur]] && nex != cur) v2[cur] += v1[nex] ;
			}
		} for (auto nex : adj[cur]) if (nex != fa[cur]) self (self ,nex ,d) ;
	} ;
	
	auto Dp1 = [] (auto &&self ,int cur ,int d) -> void {
		dp1[cur][0] = v1[cur] ;
		std :: vector < int > son ,pre ,suf ;
		for (auto nex : adj[cur]) if (nex != fa[cur]) son.emplace_back (nex) ;
		for (auto x : son) pre.emplace_back (maxid[x] + 1) ;
		std :: reverse (son.begin () ,son.end ()) ;
		for (auto x : son) suf.emplace_back (maxid[x] + 1) ;
		std :: reverse (son.begin () ,son.end ()) ;
		int m = son.size () ;
		//assert (pre.size () == m && suf.size () == m) ;
		f (i ,1 ,m - 1 ,1) pre[i] = std :: max (pre[i] ,pre[i - 1]) ;
		f (i ,1 ,m - 1 ,1) suf[i] = std :: max (suf[i] ,suf[i - 1]) ;
		for (auto x : son) self (self ,x ,d) ;
		f (i ,0 ,m - 1 ,1) {
			int mx = i ? pre[i - 1] : 0 ;
			if (i != m - 1) mx = std :: max (mx ,suf[m - 2 - i]) ;
			f (j ,1 ,n ,1) if (mx + j <= d) dp1[cur][j] = std :: min (dp1[cur][j] ,dp1[son[i]][j - 1]) ;
		}
	} ;
	
	auto Dp2 = [] (auto &&self ,int cur ,int d) -> void {
		dp2[cur][0] = v2[fa[cur]] ;
		std :: vector < int > son ,pre ,suf ;
		for (auto nex : adj[fa[cur]]) if (nex != fa[fa[cur]] && nex != cur) son.emplace_back (nex) ;
		for (auto x : son) pre.emplace_back (maxid[x] + 1) ;
		std :: reverse (son.begin () ,son.end ()) ;
		for (auto x : son) suf.emplace_back (maxid[x] + 1) ;
		std :: reverse (son.begin () ,son.end ()) ;
		int m = son.size () ;
		//assert (pre.size () == m && suf.size () == m) ;
		f (i ,1 ,m - 1 ,1) pre[i] = std :: max (pre[i] ,pre[i - 1]) ;
		f (i ,1 ,m - 1 ,1) suf[i] = std :: max (suf[i] ,suf[i - 1]) ;
		f (i ,0 ,m - 1 ,1) {
			int mx = i ? pre[i - 1] : 0 ;
			if (i != m - 1) mx = std :: max (mx ,suf[m - 2 - i]) ;
			mx = std :: max (mx ,maxod[fa[cur]]) ;
			f (j ,1 ,n ,1) if (mx + j <= d) dp2[cur][j] = std :: min (dp2[cur][j] ,dp1[son[i]][j - 1]) ;
		}
		int mx = 0 ; for (auto x : pre) mx = std :: max (mx ,x) ;
		//std :: cerr << cur << ' ' << mx << '\n' ;
		f (j ,1 ,n ,1) if (mx + j <= d) {
			//std :: cerr << j << '\n' ;
			dp2[cur][j] = std :: min (dp2[cur][j] ,dp2[fa[cur]][j - 1]) ;
		}
		for (auto nex : adj[cur]) if (nex != fa[cur]) self (self ,nex ,d) ;
	} ;
	 
	int c ,t ; std :: cin >> c >> t ; while (t --> 0) {
		std :: cin >> n >> k ;
		f (i ,1 ,n ,1) dep[i] = fa[i] = maxid[i] = maxod[i] = maxdep[i] = siz[i] = 0 ;
		f (i ,1 ,n ,1) adj[i].clear () ;
		f (i ,1 ,n - 1 ,1) {
			int u ,v ; std :: cin >> u >> v ;
			adj[u].emplace_back (v) ,adj[v].emplace_back (u) ;
		}
		
		Pre1 (Pre1 ,1 ,0) ,Pre2 (Pre2 ,1) ;
		//f (i ,1 ,n ,1) std :: cerr << "melo " << i << ' ' << maxid[i] << ' ' << maxod[i] << '\n' ;
		
		int l = 0 ,r = n ,ans = 0 ; while (l <= r) {
			int mid = l + r >> 1 ;
			f (i ,1 ,n ,1) v1[i] = v2[i] = tmp[i] = 0 ;
			Solve1 (Solve1 ,1 ,mid) ,Solve2 (Solve2 ,1 ,mid) ;
			//f (i ,1 ,n ,1) std :: cerr << "melo " << i << ' ' << tmp[i] << ' ' << v2[i] << '\n' ;
			f (i ,1 ,n ,1) f (j ,1 ,n ,1) dp1[i][j] = dp2[i][j] = n + 1 ;
			Dp1 (Dp1 ,1 ,mid) ,Dp2 (Dp2 ,1 ,mid) ;
			bool flag (false) ;
			f (i ,1 ,n ,1) val1[i] = val2[i] = n + 1 ;
			f (i ,1 ,n ,1) f (j ,0 ,n ,1) val1[i] = std :: min (val1[i] ,dp1[i][j]) ,
			val2[i] = std :: min (val2[i] ,dp2[i][j]) ;
			f (i ,1 ,n ,1) {
				int a = val1[i] ,b = val2[i] ;
				if (a == n + 1 || b == n + 1) continue ;
				if (!a) a = 1 ; if (!b) b = 1 ;
				if (a + b <= k) flag = true ;
			}
			
			if (flag) r = (ans = mid) - 1 ;
			else l = mid + 1 ;
		} std :: cout << ans << '\n' ;
	}
}
