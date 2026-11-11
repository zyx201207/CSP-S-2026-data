#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
const int MAXN = 505;
const int MAXM = 500005;
LL sta[MAXM];
LL k[MAXN];
LL to[MAXN];
struct Edge {
	int v;
	LL w;
};
vector<Edge> edge[MAXM];
LL test, n, m, d, q;
LL dis[MAXM];
bool vis[MAXN];
map<pair<int, int>, LL> mp;
int s, t;

void dijkstra() {
	for (int i = 1; i <= m; i++) {
		dis[i] = 1e18;
		vis[i] = false;
	} dis[s] = 0;
	
	priority_queue<pair<LL, int>, vector<pair<LL, int> >, greater<pair<LL, int> > > q;
	q.push({0, s});
	while (!q.empty()) {
		LL d = q.top().first;
		int u = q.top().second;
		q.pop();
		vis[u] = true;
		for (Edge e : edge[u]) {
			int v = e.v;
			LL w = e.w;
			LL get = (v == t ? 0LL : mp[{v, v}]);
			if (dis[v] > dis[u] + get + w) {
				dis[v] = dis[u] + get + w;
//				cerr << u << ' ' << v << " -> " << get << '&' << w << endl;
				if (!vis[v]) {
					q.push({dis[v], v});
				}
			}
		}
	} return ;
}

LL b;

void dfs(int u, LL step) {
	if (u == t) {
		dis[t] = min(dis[t], step);
		return ;
	}
	
	for (auto _ : edge[u]) {
		int v = _.v;
		if (vis[v]) continue;
		vis[v] = true;
		dfs(v, step + 1);
	} return ;
}

void solve() {
	cin >> s >> t;
	if (test >= 12 && test <= 19) {
		vis[s] = true;
		dfs(s, 0);
		dis[t] = 1e18;
		cout << sta[s] + sta[t] + dis[t] * b << endl;
		return ;
	}
	
	LL ans = sta[s] + mp[{s, s}] + sta[t];
//	cout << mp[{s, s}] << endl;
//	cout << sta[s] + to[s] + sta[t] << endl;
	dijkstra();
	ans += dis[t];
	cout << ans << endl;
	return ;
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> test >> n >> m >> d >> q;
//	cout << test << n << m << d << q << endl;
	for (int i = 1; i <= m; i++) {
		cin >> sta[i];
	}
	
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++) {
			int v;
			LL t;
			cin >> v >> t;
			b = t;
			edge[i].push_back({v, t});
			edge[v].push_back({i, t});
			if (test < 12 || test > 19) mp[{i, v}] = mp[{v, i}] = t;
		}
	}
	
	while (q--) {
		solve();
	}

	return 0;
}

/*

0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3



*/

