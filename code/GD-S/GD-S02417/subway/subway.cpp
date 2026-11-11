#include<bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10;
const int inf = 1e9;
int c, n, m, d, q, w[N], a[490][N], t[490][N], dp[N];
vector<pair<int, int> > edge[N];

void bfs(int s) {
	queue<int> q;
	q.push(s);
	dp[s] = 0;
	while(!q.empty()) {
		int now = q.front();
		q.pop();
		for(auto v : edge[now]) {
			if(v.second + dp[now] < dp[v.first]) {
				dp[v.first] = v.second + dp[now];
				q.push(v.first);
			}
		}
	}
}

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for(int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		for(int j = 1; j <= k; j++) {
			cin >> a[i][j] >> t[i][j];
		}
		for(int u = 1; u <= k; u++) {
			for(int v = 1; v < u; v++) {
				edge[a[i][u]].push_back({a[i][v], t[i][u] + t[i][v]});
				edge[a[i][v]].push_back({a[i][u], t[i][u] + t[i][v]});
			}
		}
	}
	while(q--) {
		int s, t;
		cin >> s >> t;
		for(int i = 1; i <= m; i++) dp[i] = inf;
		bfs(s);
		cout << dp[t] + w[s] + w[t] << '\n';
	}
	return 0;
}

