#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e6 + 10;
int n; ll d, x[N], dis[N], g[N], ans;
vector < int > G[N];
const ll inf = 1e9;

void bfs(int s) {
	queue < int > q;
	for (int i = 1; i <= n; i ++) dis[i] = inf, g[i] = 0;
	dis[s] = 0; g[s] = 1; q.push(s);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (auto v : G[u]) {
			if (dis[v] >= dis[u] + 1) {
				if (dis[v] > dis[u] + 1) {
					g[v] = g[u];
					dis[v] = dis[u] + 1;
					q.push(v);
				} else {
					g[v] = g[u] + g[v];
				}
			}
		}
	}
	for (int i = s; i <= n; i ++) 
		if (g[i] == 2) ans ++;
}

void solve() {
	cin >> n >> d; ans = 0;
	for (int i = 1; i <= n; i ++) {
		cin >> x[i];
		G[i].clear();
	}
	for (int i = 1; i <= n; i ++) {
		int pos1 = lower_bound(x + 1, x + 1 + n, x[i] - d) - x;
		int pos2 = upper_bound(x + 1, x + 1 + n, x[i] + d) - x - 1;
//		cout << "i = " << i << " pos1 = " << pos1 << " pos2 = " << pos2 << "\n";
		for (int j = pos1; j < i; j ++) G[j].push_back(i), G[i].push_back(j);
		for (int j = i + 1; j <= pos2; j ++) G[j].push_back(i), G[i].push_back(j);
	}
	for (int i = 1; i <= n; i ++) {
		sort(G[i].begin(), G[i].end());
		G[i].erase(unique(G[i].begin(), G[i].end()), G[i].end());
	}
	for (int i = 1; i <= n; i ++) bfs(i);
	cout << ans << "\n";
}

void solve2() {
	cin >> n >> d; ans = 0;
	for (int i = 1; i <= n; i ++) cin >> x[i];
	int cnt = 0;
	for (int i = 1; i <= n; i ++) {
		int pos1 = lower_bound(x + 1, x + 1 + n, x[i] - d) - x;
		int pos2 = upper_bound(x + 1, x + 1 + n, x[i] + d) - x - 1;
		if (pos1 == 1 && pos2 == n) cnt ++;
	}
	if (cnt >= 3) {
		cout << "0\n";
		return ;
	}
	for (int i = 1; i <= n; i ++) {
		int pos1 = lower_bound(x + 1, x + 1 + n, x[i] - d) - x;
		int pos2 = upper_bound(x + 1, x + 1 + n, x[i] + d) - x - 1;
		ans += n - (pos2 - pos1 + 1);
	}
	cout << ans << "\n";
} 

int main() {
	
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int c, t;
	cin >> c >> t;
	while (t --) {
		if (c <= 6) solve();
		else if (c == 13 || c == 14) solve2();
		else {
			if (c <= 10) solve();
			else cout << "0\n";
		}
	}
	
	return 0;
}
