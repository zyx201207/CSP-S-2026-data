#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e4 + 505;
int n, m, D, q;
vector<pair<int, int>> e[N];
int w[N], d[505][N], vis[505][N];
namespace subtask1to11 {
	void dijkstra(int s) { 
		memset(d[s - m], 0x3F, sizeof(d[s - m]));
		memset(vis[s - m], 0, sizeof(vis[s - m]));
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
		d[s - m][s] = 0; q.push({0, s});
		while(!q.empty()) {
			int u = q.top().second; q.pop();
			if(vis[s - m][u]) continue;
			vis[s - m][u] = 1;
			for(auto x : e[u])
				if(d[s - m][u] + x.second < d[s - m][x.first])
					d[s - m][x.first] = d[s - m][u] + x.second, q.push({d[s - m][x.first], x.first});
		}
	}
	signed main() {
		cin >> n >> m >> D >> q;
		for(int i = 1; i <= m; i++) cin >> w[i];
		for(int i = 1; i <= n; i++) {
			int k; cin >> k;
			for(int j = 1; j <= k; j++) {
				int a, t; cin >> a >> t;
				e[m + i].push_back({a, t});
				e[a].push_back({m + i, t});
			}
		}
		for(int i = 1; i <= n; i++) dijkstra(i + m);
		while(q--) {
			int x, y; cin >> x >> y;
			int res = 1e18;
			for(auto k : e[x]) res = min(res, d[k.first - m][y] + k.second);
			for(auto k : e[y]) res = min(res, d[k.first - m][x] + k.second);
			cout << res + w[x] + w[y] << "\n";
		}
		return 0;
	}
}
namespace subtask12to15 {
	void dijkstra(int s) { 
		memset(d[s - m], 0x3F, sizeof(d[s - m]));
		memset(vis[s - m], 0, sizeof(vis[s - m]));
		queue<int> q;
		d[s - m][s] = 0; q.push(s);
		while(!q.empty()) {
			int u = q.front(); q.pop();
			if(vis[s - m][u]) continue;
			vis[s - m][u] = 1;
			for(auto x : e[u])
				if(d[s - m][u] + x.second < d[s - m][x.first])
					d[s - m][x.first] = d[s - m][u] + x.second, q.push(x.first);
		}
	}
	signed main() {
		cin >> n >> m >> D >> q;
		for(int i = 1; i <= m; i++) cin >> w[i];
		for(int i = 1; i <= n; i++) {
			int k; cin >> k;
			for(int j = 1; j <= k; j++) {
				int a, t; cin >> a >> t;
				e[m + i].push_back({a, t});
				e[a].push_back({m + i, t});
			}
		}
		for(int i = 1; i <= n; i++) dijkstra(i + m);
		while(q--) {
			int x, y; cin >> x >> y;
			int res = 1e18;
			for(auto k : e[x]) res = min(res, d[k.first - m][y] + k.second);
			for(auto k : e[y]) res = min(res, d[k.first - m][x] + k.second);
			cout << res + w[x] + w[y] << "\n";
		}
		return 0;
	}
}
namespace subtask20to21 {
	const int N = 5e5 + 505;
	int n, m, D, q;
	vector<pair<int, int>> e[N];
	int w[N], d[5][N], vis[5][N];
	void dijkstra(int s) { 
		memset(d[s - m], 0x3F, sizeof(d[s - m]));
		memset(vis[s - m], 0, sizeof(vis[s - m]));
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
		d[s - m][s] = 0; q.push({0, s});
		while(!q.empty()) {
			int u = q.top().second; q.pop();
			if(vis[s - m][u]) continue;
			vis[s - m][u] = 1;
			for(auto x : e[u])
				if(d[s - m][u] + x.second < d[s - m][x.first])
					d[s - m][x.first] = d[s - m][u] + x.second, q.push({d[s - m][x.first], x.first});
		}
	}
	signed main() {
		cin >> n >> m >> D >> q;
		for(int i = 1; i <= m; i++) cin >> w[i];
		for(int i = 1; i <= n; i++) {
			int k; cin >> k;
			for(int j = 1; j <= k; j++) {
				int a, t; cin >> a >> t;
				e[m + i].push_back({a, t});
				e[a].push_back({m + i, t});
			}
		}
		for(int i = 1; i <= n; i++) dijkstra(i + m);
		while(q--) {
			int x, y; cin >> x >> y;
			int res = 1e18;
			for(auto k : e[x]) res = min(res, d[k.first - m][y] + k.second);
			for(auto k : e[y]) res = min(res, d[k.first - m][x] + k.second);
			cout << res + w[x] + w[y] << "\n";
		}
		return 0;
	}
}
signed main() {
	cin.tie(0)->sync_with_stdio(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c; cin >> c;
	if(c >= 1 && c <= 11) subtask1to11::main();
	else if(c >= 12 && c <= 15) subtask12to15::main();
	else if(c == 20 || c == 21) subtask20to21::main();
	return 0;
}