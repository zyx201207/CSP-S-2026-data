#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int maxn = 5e5 + 5, maxm = 505;

struct node {
	ll sb, wei;
};
struct dnode {
	ll u, d;
	friend bool operator < (dnode x, dnode y) {
		return x.d > y.d;
	} 
};
vector<node> g[maxn];
ll c, n, m, d, q, w[maxn], k[maxm], dis[maxn];
vector<ll> a[maxm], t[maxm];
priority_queue<dnode> pq;

void dij(ll s) {
	for(int i = 1; i <= m; i ++)
		dis[i] = 1e18;
	dis[s] = 0;
	pq.push({s, 0});
	while(!pq.empty()) {
		ll u = pq.top().u, d = pq.top().d;
		pq.pop();
		if(d != dis[u])
			continue;
		for(auto x : g[u]) {
			int lu = x.sb, st = x.wei;
			for(int i = 0; i < k[lu]; i ++) {
				int to = a[lu][i], wt = t[lu][st - 1] + t[lu][i];
				if(dis[to] > dis[u] + wt) {
					dis[to] = dis[u] + wt;
					pq.push({to, dis[to]});
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i ++) {
		cin >> w[i];
	}
	for(int i = 1; i <= n; i ++) {
		cin >> k[i];
		for(int j = 1; j <= k[i]; j ++) {
			int to, tm;
			cin >> to >> tm;
			g[to].push_back({i, j});
			a[i].push_back(to);
			t[i].push_back(tm);
		}
	}
	while(q --) {
		int u, v;
		cin >> u >> v;
		dij(u);
		cout << w[u] + dis[v] + w[v] << '\n';
	}
	return 0;
} 
