#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e2 + 10;
const int M = 1e5 + 10;
int c, n, m, d, q;
struct load {
	int a, t;
};
int w[N];
vector<load> g[N];
vector<int> lp[N];
int xx, yy;
int step[N];
bool vis[N];
int ans = LLONG_MAX;
int shz(int i, int u) {
	for (load wy : g[i]) {
		if (wy.a == u) return wy.t;
	}
}
void bfs() {
	queue<int> q;
	q.push(xx);
	for (int i = 0; i < n + 10; i++) {
		vis[i] = 0,step[i] = 0;
	}
//	step[xx] = g[xx][xx].t;
	vis[xx] = 1;
	while(q.size()) {
		int u = q.front();
		q.pop();
		for (int i : lp[u]) {
			int jinru = shz(i, u);
			for (load wy : g[i]) {
				int v = wy.a;
				int nstep = step[u] + jinru + wy.t;
				if (vis[v] && nstep >= step[v]) continue;
				vis[v] = 1;
				step[v] = nstep;
				if (v == yy) {
					ans = min(ans, nstep);
					continue;
				}
				q.push(v);
			}
		}
	}
}
signed main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld", &c, &n, &m, &d, &q);
	for (int i = 1; i <= m; i++) {
		scanf("%lld", &w[i]);
	}
	for (int i = 1; i <= n; i++) {
		int k;
		scanf("%lld", &k);
		for (int j = 1; j <= k; j++) {
			int a, t;
			scanf("%lld%lld", &a, &t);
			lp[a].push_back(i);
			load nw = {a, t};
			g[i].push_back(nw);
		}
	}
	for (int i = 1; i <= q; i++) {
		scanf("%lld%lld", &xx, &yy);
		ans = LLONG_MAX;
		bfs();
		printf("%lld\n", ans + w[xx] + w[yy]);
	}
	return 0;
}
