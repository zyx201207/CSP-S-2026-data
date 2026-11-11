#include<bits/stdc++.h>
using namespace std;
#define int long long
struct code{
	int n, d, ans, x[2114514], nxt[2114514], val[4114514], siz[4114514], tmp[2114514];
	struct edge{
		int v, nxt;
	} e[4114514];
	int hd[4114514], cntu;
	void add_edge(int u, int v){
		e[++cntu].nxt = hd[u];
		hd[u] = cntu; e[cntu].v = v;
	}
	void dfs(int u){
		for(int v = hd[u]; v; v = e[v].nxt) dfs(e[v].v), siz[u] += siz[e[v].v];
		ans += siz[u] * val[u];
	}
	void operator()(){
		scanf("%lld%lld", &n, &d); cntu = ans = 0;
		for(int i = 1; i <= n; i++) scanf("%lld", &x[i]), tmp[i] = nxt[i] = 0;
		for(int i = 0; i <= (n << 1); i++) hd[i] = siz[i] = val[i] = 0;
		for(int i = n, nx = n; i; i--){
			while(x[nx] - x[i] > d) nx--;
			nxt[i] = nx;
		}
		tmp[n + 1] = nxt[n + 1] = n + 1;
		for(int i = 1; i <= n; i++) if(nxt[i] == i) nxt[i] = n + 1;
		for(int i = 1; i <= n; i++) if(nxt[i] <= n) siz[nxt[i]]++;
		for(int j = n; j; j--){
			if(nxt[j] <= n && nxt[j - 1] == nxt[j] - 1) tmp[j] = tmp[nxt[j]]; else tmp[j] = j;
			int v = 0, w = 0;
			if(nxt[j] <= n){
				v = nxt[j] + n;
				if(nxt[j - 1] <= n) w = max(0ll, nxt[j] - max(j, nxt[j - 1]));
				else w = max(0ll, nxt[j] - j);
			}
			if(nxt[j - 1] == nxt[j]) v = 0;
			add_edge(v, j + n); val[j + n] = w;
			// if(v) printf("%d %d\n", v, j + n);
			v = 0, w = 0;
			if(x[j - 1] > x[j] - d){
				if(j > 2 && nxt[j - 2] <= n) w = max(0ll, nxt[j - 1] - max(j, nxt[j - 2]));
				else w = max(0ll, nxt[j - 1] - j);
				int tj = tmp[j]; // if(nxt[tj] > n) printf("%d %d\n", j, w);
				if(nxt[tj] <= n){
					v = nxt[tj];
					if(nxt[tj - 1] == nxt[tj])
						if(nxt[tj - 2] > n || nxt[tj - 2] < nxt[tj]) v += n; else v = 0;
					else;
				}
			}else if(nxt[j] <= n) v = nxt[j];
			add_edge(v, j); val[j] = w;
			// if(v > n) printf("%d %d\n", v, j);
		}
		dfs(0);
		printf("%lld\n", ans);
	}
} solve;
signed main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int _; scanf("%*d%lld", &_); while(_--) solve();
	return 0;
}

