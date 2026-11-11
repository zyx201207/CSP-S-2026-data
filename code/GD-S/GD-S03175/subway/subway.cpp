#include <bits/stdc++.h>
#define enl putchar('\n')
#define ys puts("YES")
#define md int mid=l+r>>1
#define len(l, r) ((r)-(l)+1)
#define fst first
#define snd second
using ll=long long;
using ull=unsigned long long;
using pii=std::pair<ll, int>;
using namespace std;
const int MAX=5.1e5+10, MAXM=5e2+10, MOD=1e9+7;
const ll INF=1e18;
int cid, tc=1;
int n, m, D, Q;
ll W[MAX];
vector<pii> G[MAX];
vector<vector<ll>> dis;
bool vis[MAX];
void dijkstra(int rt) {
	fill(vis+1, vis+n+m+1, false);
	priority_queue<pii, vector<pii>, greater<pii>> q;
	dis[rt][rt+m]=0;
	q.push({0, rt+m});
	while (q.size()) {
		auto [d, u]=q.top();
		q.pop();
		if (vis[u]) continue;
		vis[u]=true;
		for (auto [w, v]:G[u]) {
			if (d+w<dis[rt][v]) {
				dis[rt][v]=d+w;
				q.push({dis[rt][v], v});
			}
		}
	}
}
ll ans;
void INIT() {
	dis.resize(n+1, vector<ll>(m+n+1, INF));
}
void EXE() {
	for (int i=1;i<=m;i++) scanf("%lld", &W[i]);
	for (int t=1;t<=n;t++) {
		int u, siz;
		ll w;
		scanf("%d", &siz);
		for (int i=1;i<=siz;i++) {
			scanf("%d %lld", &u, &w);
			G[u].emplace_back(pii{w, t+m});
			G[t+m].emplace_back(pii{w, u});
		}
	}
	for (int t=1;t<=n;t++) dijkstra(t);
	int u, v;
	while (Q--) {
		ans=INF;
		scanf("%d %d", &u, &v);
		for (auto [w, sbw]:G[u]) ans=min(ans, W[u]+w+dis[sbw-m][v]+W[v]);
		printf("%lld\n", ans);
	}
}
void CLEAR() {
}
signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	// scanf("%d", &tc);
	while (tc--) {
		scanf("%d %d %d %d %d", &cid, &n, &m, &D, &Q);
		INIT();
		EXE();
		CLEAR();
	}
	return 0;
}