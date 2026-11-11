#include <bits/stdc++.h>
#define qwq std::ios::sync_with_stdio(false); std::cin.tie(nullptr);

inline int read(){
	int x = 0, f = 1; char h = getchar();
	while(!isdigit(h)){ if(h == '-') f = -f; h = getchar(); }
	while(isdigit(h)){ x = x * 10 + (h ^ 48); h = getchar(); }
	return x * f;
}

const int N = 1e6 + 10, inf = 0x3f3f3f3f;
int n, k, max, ans, dep[N], fa[N][24];
std::vector <int> vct, e[N];

inline int get(int x){
	int re = 0;
	for(; x; x >>= 1) re += (x & 1);
	return re;
}

void dfs(int u, int p){
	fa[u][0] = p, dep[u] = dep[p] + 1;
	for(int i = 0; fa[u][i]; ++i) fa[u][i + 1] = fa[fa[u][i]][i];
	for(auto &v : e[u]) if(v ^ p) dfs(v, u);
}
inline int Lca(int u, int v){
	if(dep[u] < dep[v]) std::swap(u, v);
	for(int i = max; ~i; --i) if(dep[fa[u][i]] >= dep[v]) u = fa[u][i];
	if(u == v) return u;
	for(int i = max; ~i; --i) if(fa[u][i] ^ fa[v][i]) u = fa[u][i], v = fa[v][i];
	return fa[u][0];
}

inline int dis(int u, int v){ return dep[u] + dep[v] - dep[Lca(u, v)] * 2; }

int ba[N];
int find(int x){ return ba[x] == x ? x : ba[x] = find(ba[x]); }
inline void merge(int x, int y){ x = find(x), y = find(y); if(x ^ y) ba[x] = y; }

int32_t main(){
	freopen("hub.in", "r", stdin); freopen("hub.out", "w", stdout);
	int c = read(), T = read();
	while(T--){
		n = read(), k = read(), ans = inf;
		max = (int)(log2(n)) + 1;
		for(int i = 1; i <= n; ++i) e[i].clear();
		for(int i = 1; i < n; ++i){
			int u = read(), v = read();
			e[u].push_back(v), e[v].push_back(u);
		}
		dfs(1, 0);
		for(int S = 0; S < (1 << n); ++S){
			if(get(S) != k) continue;
			vct.clear();
			for(int i = 1; i <= n; ++i) if((S >> (i - 1)) & 1) vct.push_back(i);
			int cnt = 0;
			for(auto &x : vct) ba[x] = x;
			for(auto &x : vct) for(auto &y : vct) if(fa[x][0] == y || fa[y][0] == x) merge(x, y);
			for(auto &x : vct) if(ba[x] == x) ++cnt;
			if(cnt > 2) continue;
			int tmp = 0;
			for(int i = 1, xx; i <= n; ++i){
				xx = inf;
				for(auto &x : vct) xx = std::min(xx, dis(i, x));
				tmp = std::max(tmp, xx);
			}
			ans = std::min(ans, tmp);
		}
		printf("%d\n", ans);
	}
	return 0;
}
/*
感觉这个题挺套路的，但是放T4一看就不是什么好东西。
最后16分钟，能不能极限码出来？展示手速。
*/
