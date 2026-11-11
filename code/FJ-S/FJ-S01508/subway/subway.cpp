#include <bits/stdc++.h>
#define int long long
using namespace std;
const int Max1 = 1e3 + 9;
const int Max2 = 5e5 + 9;
struct Edge { int to, val; };
struct Node { int id, val; };
struct Que { int id, u, v, ans; } que[Max2];
struct Cmp {
      bool operator()(const Node& x, const Node& y) 
	  { return x.val > y.val; }
};
int c, n, m, d, q;
int w[Max2], a[Max2], t[Max2], num[Max2], f[Max2];
bool vis[Max2];
vector <Edge> e[Max2];
priority_queue <Node, vector<Node>, Cmp> nd;
bool cmp1(Que x, Que y) { return x.u < y.u; }
bool cmp2(Que x, Que y) { return x.id < y.id; }
signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++) cin >> w[i];
	for(int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		memset(a, 0, sizeof(a));
		memset(t, 0, sizeof(t));
		for(int j = 1; j <= k; j++) cin >> a[j] >> t[j];
		for(int j = 1; j <= k; j++) {
			for(int o = j+1; o <= k; o++) {
				e[a[j]].push_back({a[o], t[j]+t[o]});
				e[a[o]].push_back({a[j], t[j]+t[o]});
				num[a[j]]++, num[a[o]]++;
			}
		}
	}
	for(int i = 1; i <= q; i++) {
		cin >> que[i].u >> que[i].v;
		que[i].id = i;
	}
	sort(que + 1, que + q + 1, cmp1);
	for(int i = 1; i <= q; i++) {
		int u = que[i].u, v = que[i].v;
		if(u == que[i-1].u) {
			que[i].ans = f[v] + w[u] + w[v];
			continue;
		}
		memset(f, 0x3f3f3f3f, sizeof(f));
		memset(vis, 0, sizeof(vis));
		nd.push({u,0});
		f[u] = 0;
		while(!nd.empty()) {
			Node p = nd.top();
			nd.pop();
			if(vis[p.id]) continue;
			vis[p.id] = 1;
			for(int j = 0; j < num[p.id]; j++) {
				if(!vis[e[p.id][j].to]) {
					if(f[p.id] + e[p.id][j].val <= f[e[p.id][j].to]) {
						f[e[p.id][j].to] = f[p.id] + e[p.id][j].val;
						nd.push({e[p.id][j].to, f[e[p.id][j].to]});
					}
				}
			}
		}
		que[i].ans = f[v] + w[u] + w[v];
	}
	sort(que + 1, que + q + 1, cmp2);
	for(int i = 1; i <= q; i++) cout << que[i].ans << "\n";
	return 0;
}
