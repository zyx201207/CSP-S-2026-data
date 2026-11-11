#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e6 + 7;
int n, d, a[N], dis[N], cnt[N];
vector<int> g[N];
bool vis[N];
int bfs(int s) {
	for (int i = 1; i <= n; ++i) dis[i] = 1e18 + 7, cnt[i] = 0;
	queue<int> q;
	q.push(s); dis[s] = 0, cnt[s] = 1;
	while(!q.empty()) {
		int u = q.front(); q.pop();
		for (int i = 0; i < g[u].size(); ++i) {
			int v = g[u][i];
			if (dis[v] == dis[u] + 1) cnt[v] += cnt[u];
			if (dis[v] > dis[u] + 1) {
				dis[v] = dis[u] + 1;
				cnt[v] = cnt[u];
				q.push(v);
			}
		}
	}
	int res = 0;
	for (int i = 1; i <= n; ++i) if (cnt[i] == 2) res++;
	return res;
}
int solution1() {// 40 pts
	int ans = 0;
	for (int i = 1; i <= n; ++i) g[i].clear();
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j < i; ++j) {
			if (a[i] - a[j] <= d) g[i].push_back(j), g[j].push_back(i);
		}
	}
	for (int i = 1; i <= n; ++i) ans += bfs(i);
	return ans;
}
signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int c, T; cin >> c >> T;
	while(T--) {
		cin >> n >> d;
		for (int i = 1; i <= n; ++i) cin >> a[i];
		cout << solution1() / 2 << "\n";
	}
	return 0;
}

