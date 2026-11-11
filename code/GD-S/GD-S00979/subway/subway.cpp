#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5 + 10, M = 5e2 + 10, K = 1e3 + 10;
int cpos, n, m, d, q;
// m 是线路数
// n 是地铁站数 
ll w[N + M];
int k[N];
vector<pair<int, ll> > e[N + M]; 
ll dis1[N + M], dis2[K][K];
bool vis[N + M];
bool vis2[N + M];
int ls[N];
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> cpos >> m >> n >> d >> q;
	for (int i = 1; i <= n; i++) cin >> w[i];
	if (cpos >= 9 && cpos <= 11) {
		vector<int> tmp;
		tmp.push_back(0);
		memset(vis2, false, sizeof vis2);
		for (int i = 1; i <= m; i++) {
			cin >> k[i];
			for (int j = 1; j <= k[i]; j++) {
				int u = n + i, v;
				ll ti;
				cin >> v >> ti;
				// 找有用点，过滤无用点 
				if (!vis2[u]) tmp.push_back(u), vis2[u] = 1, ls[u] = tmp.size() - 1;
				if (!vis2[v]) tmp.push_back(v), vis2[v] = 1, ls[v] = tmp.size() - 1; 
				// 建立 super 结点 
				e[u].push_back({v, ti});
				e[v].push_back({u, ti});  
			}
		}
		for (int i = 1; i < tmp.size(); i++) {
			int x = tmp[i];
			if (x > n) continue;
			memset(dis1, 0x3f, sizeof dis1);
			memset(vis, false, sizeof vis);
			priority_queue<pair<ll, int>, vector<pair<ll, int> >, greater<pair<ll, int> > > q;
			q.push({0, x});
			dis1[x] = w[x];
			while (!q.empty()) {
				int u = q.top().second;
				q.pop();
				if (vis[u]) continue;
				vis[u] = 1;
				for (pair<int, ll> x : e[u]) {
					int v = x.first;
					ll w = x.second;
					if (dis1[v] > dis1[u] + w) 
						dis1[v] = dis1[u] + w, q.push({dis1[v], v});
				}
			}
			for (int j = 1; j < tmp.size(); j++) dis2[i][j] = dis1[tmp[j]] + w[tmp[j]];
			dis2[i][i] = 0;
		}
		while (q--) {
			int x, y;
			cin >> x >> y;
			cout << dis2[ls[x]][ls[y]] << "\n";
		}
		return 0;
	}
	if (cpos >= 12 && cpos <= 15) {
		ll T = 0;
		for (int i = 1; i <= m; i++) {
			cin >> k[i];
			for (int j = 1; j <= k[i]; j++) {
				int u = n + i, v;
				ll ti;
				cin >> v >> ti;
				T = ti;
				// 建立 super 结点 
				e[u].push_back({v, 1});
				e[v].push_back({u, 1});  
				// 建 01 边
				// 因为权值相同 
			} 
		}
		while (q--) {
			int x, y;
			cin >> x >> y;
			memset(vis, false, sizeof vis);
			queue<pair<int, ll> > q;
			q.push({x, 0});
			ll ans = 0;
			while (!q.empty()) {
				int u = q.front().first, cnt = q.front().second;
				q.pop();
				if (u == y) {
					ans = cnt;
					break;
				}
				if (vis[u]) continue;
				vis[u] = 1;
				for (pair<int, ll> x : e[u]) {
					int v = x.first;
					ll w = x.second;
					q.push({v, cnt + w});
				}
			} // 跑 bfs 求边数 
			cout << ans * T + w[x] + w[y] << "\n";
		}
		return 0;
	} if (cpos <= 8) {
		for (int i = 1; i <= m; i++) {
			cin >> k[i];
			for (int j = 1; j <= k[i]; j++) {
				int u = n + i, v;
				ll ti;
				cin >> v >> ti;
				// 建立 super 结点 
				e[u].push_back({v, ti});
				e[v].push_back({u, ti});  
			} 
		}
		while (q--) {
			int x, y;
			cin >> x >> y;
			memset(dis1, 0x3f, sizeof dis1);
			memset(vis, false, sizeof vis);
			priority_queue<pair<ll, int>, vector<pair<ll, int> >, greater<pair<ll, int> > > q;
			q.push({0, x});
			dis1[x] = w[x];
			while (!q.empty()) {
				int u = q.top().second;
				q.pop();
				if (vis[u]) continue;
				vis[u] = 1;
				for (pair<int, ll> x : e[u]) {
					int v = x.first;
					ll w = x.second;
					if (dis1[v] > dis1[u] + w) 
						dis1[v] = dis1[u] + w, q.push({dis1[v], v});
				}
			}
			cout << dis1[y] + w[y] << "\n";
		}
		return 0;
	} 
	vector<int> tmp;
	tmp.push_back(0);
	memset(vis2, false, sizeof vis2);
	for (int i = 1; i <= m; i++) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++) {
			int u = n + i, v;
			ll ti;
			cin >> v >> ti;
			// 找有用点，过滤无用点 
			if (!vis2[u]) tmp.push_back(u), vis2[u] = 1, ls[u] = tmp.size() - 1;
			if (!vis2[v]) tmp.push_back(v), vis2[v] = 1, ls[v] = tmp.size() - 1; 
			// 建立 super 结点 
			e[u].push_back({v, ti});
			e[v].push_back({u, ti});  
		}
	}
	if (tmp.size() >= q) {
		while (q--) {
			int x, y;
			cin >> x >> y;
			memset(dis1, 0x3f, sizeof dis1);
			memset(vis, false, sizeof vis);
			priority_queue<pair<ll, int>, vector<pair<ll, int> >, greater<pair<ll, int> > > q;
			q.push({0, x});
			dis1[x] = w[x];
			while (!q.empty()) {
				int u = q.top().second;
				q.pop();
				if (vis[u]) continue;
				vis[u] = 1;
				for (pair<int, ll> x : e[u]) {
					int v = x.first;
					ll w = x.second;
					if (dis1[v] > dis1[u] + w) 
						dis1[v] = dis1[u] + w, q.push({dis1[v], v});
				}
			}
			cout << dis1[y] + w[y] << "\n";
		}
		return 0;
	}
	for (int i = 1; i < tmp.size(); i++) {
		int x = tmp[i];
		if (x > n) continue;
		memset(dis1, 0x3f, sizeof dis1);
		memset(vis, false, sizeof vis);
		priority_queue<pair<ll, int>, vector<pair<ll, int> >, greater<pair<ll, int> > > q;
		q.push({0, x});
		dis1[x] = w[x];
		while (!q.empty()) {
			int u = q.top().second;
			q.pop();
			if (vis[u]) continue;
			vis[u] = 1;
			for (pair<int, ll> x : e[u]) {
				int v = x.first;
				ll w = x.second;
				if (dis1[v] > dis1[u] + w) 
					dis1[v] = dis1[u] + w, q.push({dis1[v], v});
			}
		}
		for (int j = 1; j < tmp.size(); j++) dis2[i][j] = dis1[tmp[j]] + w[tmp[j]];
		dis2[i][i] = 0;
	}
	while (q--) {
		int x, y;
		cin >> x >> y;
		cout << dis2[ls[x]][ls[y]] << "\n";
	}
	return 0;
}
