#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<pair<int, int>> edges[501005];
int c, n, m, dd, q;
int w[500005];
int qx[500005], qy[500005];
int dist[501005], ans[500005];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
signed main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> dd >> q;
	for (int i = 1; i <= m; ++i) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; ++i) {
		int x;
		cin >> x;
		while (x--) {
			int a, b;
			cin >> a >> b;
			edges[i].push_back({n + a, b});
			edges[n + a].push_back({i, b});
		}
	}
	for (int i = 1; i <= q; ++i) {
		cin >> qx[i] >> qy[i];
		ans[i] = 1e18;
	}
	if (12 <= c && c <= 19) {
//		int cnt = 0;
		queue<int> que;
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n + m; ++j) {
//				cnt++;
				dist[j] = 1e18;
			}
			dist[i] = 0;
			que.push(i);
			while (que.size()) {
				int u = que.front();
				que.pop();
//				cnt++;
				for (int j = 0; j < edges[u].size(); ++j) {
//					cnt++;
					if (dist[edges[u][j].first] == 1e18) {
						dist[edges[u][j].first] = dist[u] + edges[u][j].second;
						que.push(edges[u][j].first);
					}
				}
			}
			for (int j = 1; j <= q; ++j) {
	//			cnt++;
				if (dist[n + qx[j]] == 1e18 || dist[n + qy[j]] == 1e18) {
					continue;
				}
				ans[j] = min(ans[j], dist[n + qx[j]] + dist[n + qy[j]]);
			}
		}
		for (int i = 1; i <= q; ++i) {
			cout << ans[i] + w[qx[i]] + w[qy[i]] << '\n';
		}
//		cout << cnt << '\n';
		return 0;
	}
	int cnt = 0;
	for (int i = 1; i <= n; ++i) {
		cnt++;
		for (int j = 1; j <= n + m; ++j) {
//			cnt++;
			dist[j] = 1e18;
		}
		dist[i] = 0;
		pq.push({dist[i], i});
		while (pq.size()) {
//			cnt++;
			int d = pq.top().first;
			int u = pq.top().second;
			pq.pop();
			if (d > dist[u]) {
				continue;
			}
			for (int j = 0; j < edges[u].size(); ++j) {
//				cnt++;
				if (dist[edges[u][j].first] > d + edges[u][j].second) {
					dist[edges[u][j].first] = d + edges[u][j].second;
					pq.push({d + edges[u][j].second, edges[u][j].first});
				}
			}
		}
//		if (i % 100 == 0) {
//			cout << i << '\n';
//		}
		for (int j = 1; j <= q; ++j) {
//			cnt++;
//			if (dist[n + qx[j]] == 1e18 || dist[n + qy[j]] == 1e18) {
//				continue;
//			}
			ans[j] = min(ans[j], dist[n + qx[j]] + dist[n + qy[j]]);
		}
	}
	for (int i = 1; i <= q; ++i) {
		cout << ans[i] + w[qx[i]] + w[qy[i]] << '\n';
	}
//	cout << cnt << '\n';
//	cout << clock() << '\n';
    return 0;
}