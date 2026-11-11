#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6+5;
int c, n, m, d, Q, tot, k, a[N], t[N], x, y;
ll dis[N];
bool vis[N];
struct edge {
	int v, w;
}; vector<edge> G[N];
struct node {
	int u; ll w;
	bool operator < (const node &p) const {
		return w > p.w;
	}
}; priority_queue<node> q;
void add(int x, int y, int val) {
	G[x].push_back({y, val});
	G[y].push_back({x, val});
}
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%d %d %d %d %d", &c, &n, &m, &d, &Q), tot = 2*m;
	for(int i=1, w; i<=m; i++)
		scanf("%d", &w), add(i, m+i, w);
	for(int i=1; i<=n; i++) {
		scanf("%d", &k);
		for(int j=1; j<=k; j++)
			scanf("%d %d", &a[j], &t[j]);
		for(int j=1; j<=k; j++) {
			add(++tot, m+a[j], t[j]);
			if(j>1) add(tot, tot-1, 0);
		}
	} while(Q--) {
		while(!q.empty()) q.pop();
		for(int i=1; i<=tot; i++)
			vis[i] = 0, dis[i] = 1e15;
		scanf("%d %d", &x, &y);
		dis[x] = 0, q.push({x, 0});
		while(!q.empty()) {
			int u = q.top().u; q.pop();
			if(vis[u]) continue;
			vis[u] = 1;
			for(int i=0; i<G[u].size(); i++) {
				int v = G[u][i].v, w = G[u][i].w;
				if(dis[v]>dis[u]+w) dis[v] = dis[u]+w,
					q.push({v, dis[v]});
			}
		} printf("%lld\n", dis[y]);
	}
	return 0;
}
