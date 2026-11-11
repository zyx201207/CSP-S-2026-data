#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int M = 5e5 + 505;
vector<pii> vt[M];
ll n, m, c, d, q, w[M], ans, dis[M];
bool vis[M];
int main () {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i ++)
		cin >> w[i];
	for (int i = 1; i <= n; i ++) {
		int k;
		cin >> k;
		int u = i + 5e5;
		for (int j = 1; j <= k; j ++) {
			int a, t;
			cin >> a >> t;
			vt[u].push_back({a, t});
			vt[a].push_back({u, t});
		}
	}
	while (q --) {
		int u, v;
		ans = 0;
		memset(dis, 0x3f, sizeof dis);
		memset(vis, false, sizeof vis);
		priority_queue<pii, vector<pii>, greater<pii> > que;
		cin >> u >> v;
		ans += w[u] + w[v];
		dis[u] = 0;
		que.push({0, u});
		while (!que.empty()) {
			int nu = que.top().second;
			que.pop();
			if (vis[nu])
				continue;
			vis[nu] = true;
			for (auto nv : vt[nu]) {
				if (dis[nv.first] > dis[nu] + nv.second) {
					dis[nv.first] = dis[nu] + nv.second;
					que.push({dis[nv.first], nv.first});
				}
			}
		}
		ans += dis[v];
		cout << ans << endl;
	}
	return 0;
}

