#include <bits/stdc++.h>
#define qwq std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
using ll = long long;

inline int read(){
	int x = 0, f = 1; char h = getchar();
	while(!isdigit(h)){ if(h == '-') f = -f; h = getchar(); }
	while(isdigit(h)){ x = x * 10 + (h ^ 48); h = getchar(); }
	return x * f;
}

const int N = 5e5 + 5e2 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
int c, n, m, d, q, tot;
int siz[N], len[N];
std::vector <int> a[N], b[N];

namespace sub1234{
	const int M = 1.5e3 + 10;
	bool vis[M]; ll dis[M][M];
	std::vector <std::pair <int, int> > e[N];
	inline void Dj(int s){
		for(int i = 1; i <= tot; ++i) dis[s][i] = inf; dis[s][s] = 0;
		std::priority_queue <std::pair <ll, int> , std::vector <std::pair <ll, int> >, std::greater <std::pair <ll, int> > > que; que.push({0ll, s});
		memset(vis, 0, sizeof(vis[0]) * (tot + 5));
		while(!que.empty()){
			int u = que.top().second; que.pop();
			if(vis[u]) continue; vis[u] = 1;
			for(auto &x : e[u]){
				int v = x.first, w = x.second;
				if(dis[s][v] > dis[s][u] + w) dis[s][v] = dis[s][u] + w, que.push({dis[s][v], v});//不是，这里写反了调了一辈子。 
			}
		}
	}
	inline void solve(){
		for(int i = 1, k = m + 1; i <= n; ++i, ++k)
			for(int j = 1; j <= siz[i]; ++j) e[a[i][j]].push_back({k, b[i][j]}), e[k].push_back({a[i][j], b[i][j]});
		tot = n + m;
		for(int i = 1; i <= m; ++i) Dj(i);
		while(q--){
			int u = read(), v = read();
			printf("%lld\n", (u == v ? 0ll : dis[u][v] + len[u] + len[v]));
		}
	}
}

namespace sub56{
	const int M = 5e2 + 5;
	std::vector <int> f[M]; bool vis[N];
	std::vector <int> e[N];
	inline void bfs(int s){
		for(int i = 1; i <= tot; ++i) f[s][i] = INT_MAX; f[s][s + m] = 0;
		memset(vis, 0, sizeof(vis[0]) * (tot + 5));
		std::queue <int> q; q.push(s + m);
		while(!q.empty()){
			int u = q.front(); q.pop();
			for(auto &v : e[u])
				if(f[s][v] > f[s][u] + 1) f[s][v] = f[s][u] + 1, q.push(v);
		}
	}
	inline void solve(){
		for(int i = 1, k = m + 1; i <= n; ++i, ++k)
			for(int j = 1; j <= siz[i]; ++j) e[a[i][j]].push_back(k), e[k].push_back(a[i][j]);
		tot = n + m;
		for(int i = 1; i <= n; ++i) f[i].resize(tot + 2), bfs(i);
		while(q--){
			int u = read(), v = read(); ll re = inf;
			for(int i = 1; i <= n; ++i) re = std::min(re, (ll)(f[i][u] + f[i][v]));
			printf("%lld\n", (u == v ? 0ll : re * b[1][1] + len[u] + len[v]));
		}
	}
}

namespace sub7{
	ll bl[N][3];
	inline void solve(){
		memset(bl, 0x3f, sizeof bl);
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= siz[i]; ++j) bl[a[i][j]][i] =  b[i][j];
		ll min = inf;
		for(int i = 1; i <= m; ++i) min = std::min(min, bl[i][1] + bl[i][2]);//这里最开始写成n了，对拍立大功。
		while(q--){
			int u = read(), v = read();
			if(u == v) printf("0\n");
			else printf("%lld\n", std::min({bl[u][1] + bl[v][1], bl[u][2] + bl[v][2], std::min(bl[u][1] + bl[v][2], bl[u][2] + bl[v][1]) + min}) + len[u] + len[v]);
		}
	}
}

int32_t main(){
	freopen("subway.in", "r", stdin); freopen("subway.out", "w", stdout);
	c = read(), n = read(), m = read(), d = read(), q = read();
	bool flag = 1; int cnt = 0; bool jb = 1;
	for(int i = 1; i <= m; ++i) len[i] = read();
	for(int i = 1; i <= n; ++i){
		jb &= (siz[i] <= 2);
		cnt += (siz[i] = read()), a[i].resize(siz[i] + 2), b[i].resize(siz[i] + 2);
		for(int j = 1; j <= siz[i]; ++j) a[i][j] = read(), b[i][j] = read(), flag &= (b[i][j] == b[1][1]);
	}
	if(n + m <= 1500) sub1234::solve();
	else if(n == 2) sub7::solve();
	else if(flag) sub56::solve();
	return 0;
}
/*
直接O(n^2 logn)跑最短路完了。
我唐了，以为一共只有n个点。
15:38 52pts
T3太难了啊，想了一会又回来了。
16:30 68pts 16:35 [68,84]pts祈祷不会MLE or TLE。
感觉d<=2的部分建出来有点像树，但是经过画图发现并不是。
*/
