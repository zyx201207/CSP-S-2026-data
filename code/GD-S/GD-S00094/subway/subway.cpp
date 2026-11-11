#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<pair<int, int>> adj[1000010];
int a[1000010];
int d[1000010];
int c, m, n, D, Q;
int dij(int u, int v) {
	priority_queue<pair<int, int> > q; 
	d[u] = 0;
	q.push({0, u});
	while(!q.empty()) {
		int cur = q.top().second;
		int w = q.top().first;
		q.pop();
		if(d[cur] != w) {
			continue;
		}
		for(auto e : adj[cur]) {
			if(w + e.second < d[e.first]) {
				d[e.first] = w + e.second;
				q.push({w + e.second, e.first});
			}
		}
	} 
	return d[v];
}
int find(int u, int id) {//u ÔÚ id ÏßµÄ±àºÅ 
	return (u - 1) * (m + 1) + id;
} 
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout); 
	cin >> c >> m >> n >> D >> Q;
	int res = 0;
	for(int i = 1; i <= n; i ++) {
		cin >> a[i];
		res += a[i];
	}
	for(int i = 1; i <= m; i ++) {
		int len;
		cin >> len;
		int pre = 0;
		for(int j = 1; j <= len; j ++) {
			int x, w;
			cin >> x >> w;
			res += w;
			adj[find(x, i)].push_back({find(x, m + 1), w});
			adj[find(x, m + 1)].push_back({find(x, i), w});
			if(j == 1) {
				pre = x;
				continue;
			} 
			adj[find(x, i)].push_back({find(pre, i), 0});
			adj[find(pre, i)].push_back({find(x, i), 0});
			pre = x;
		}
	}
	if(n == 2) {
		cout << res << '\n';
		return 0;
	}
	while(Q --) {
		memset(d, 0x3f, sizeof(d));
		int u, v;
		cin >> u >> v;
		cout << dij(find(u, m + 1), find(v, m + 1)) + a[u] + a[v] << '\n';
	}
	return 0;
} 
