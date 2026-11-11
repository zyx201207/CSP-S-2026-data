#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<pair<int, int> > G[500005];
signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	vector<int> w(m+1);
	for (int i=1;i<=m;i++) cin >> w[i];
	vector<vector<pair<int, int> > > a(n+1);
	int aa, tt;
	vector<int> k(n+1);
	for (int i=1;i<=n;i++) {
		cin >> k[i];
		for (int j=1;j<=k[i];j++) {
			cin >> aa >> tt;
			for (auto x:a[i]) {
				G[x.first].push_back({aa, tt+x.second});
				G[aa].push_back({x.first, tt+x.second});
			}
			a[i].push_back({aa, tt});
		}
	}
	int x, y;
	map<pair<int, int>, int> mp;
	while (q--) {
		cin >> x >> y;
		if (mp.count({min(x, y), max(x, y)})) {
			cout << mp[{min(x, y), max(x, y)}]+w[x]+w[y] << endl;
			continue;
		}
		vector<int> dist(m+1, 1e18);
		vector<bool> vis(m+1, 0);
		dist[x]=0;
		priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
		pq.push({0, x});
		while (!pq.empty()) {
			int dis=pq.top().first, now=pq.top().second;
			pq.pop();
			for (auto nxt:G[now]) {
				if (vis[nxt.first]) continue;
				if (dis+nxt.second<dist[nxt.first]) {
					pq.push({dis+nxt.second, nxt.first});
					dist[nxt.first]=dis+nxt.second;
					vis[nxt.first]=1;
				} 
			}
		}
		cout << dist[y]+w[x]+w[y] << endl;
		for (int i=1;i<=m;i++) mp[{min(x, i), max(x, i)}]=dist[i];
	}
	return 0;
} 
