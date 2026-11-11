#include<bits/stdc++.h>
using namespace std;
int n, m, q, w[514527];
struct edge{
	int v, w, nxt;
} te[514527];
int hd[514527], cntu;
void add_edge(int u, int v, int w){
	te[++cntu].nxt = hd[u];
	hd[u] = cntu; te[cntu].v = v; te[cntu].w = w;
}
long long e[505][505], dis[505][505];
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%*d%d%d%*d%d", &n, &m, &q);
	for(int i = 1; i <= m; i++) scanf("%d", &w[i]);
	for(int i = 1; i <= n; i++){
		int k, a, t; scanf("%d", &k);
		while(k--) scanf("%d%d", &a, &t), add_edge(a, i, t);
	}
	memset(e, 0x3f, sizeof e); memset(dis, 0x3f, sizeof dis);
	for(int i = 1; i <= n; i++) e[i][i] = dis[i][i] = 0;
	for(int i = 1; i <= m; i++) for(int j = hd[i]; j; j = te[j].nxt) for(int k = hd[i]; k; k = te[k].nxt)
		e[te[j].v][te[k].v] = min(e[te[j].v][te[k].v], 0ll + te[j].w + te[k].w);
	for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) dis[i][j] = e[i][j];
	for(int k = 1; k <= n; k++) for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++)
		dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
	while(q--){
		int x, y; scanf("%d%d", &x, &y); long long ans = 9e18;
		for(int i = hd[x]; i; i = te[i].nxt) for(int j = hd[y]; j; j = te[j].nxt)
			ans = min(ans, dis[te[i].v][te[j].v] + te[i].w + te[j].w);
		printf("%lld\n", ans + w[x] + w[y]);
	}
	return 0;
}

