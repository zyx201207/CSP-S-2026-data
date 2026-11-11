#include <bits/stdc++.h>
using namespace std;

#define DEBUG
#define LOCAL

typedef long long int ll;
#define int ll
typedef pair<int, int> PII;

const int N = 5e5 + 10, M = 2e5 + 10, INF = 4e18, mod = 1e9 + 7;
int n, m, k, cnt, ans;
int w[N], dfn[N * 25], low[N * 25], bel[N * 25], scc_cnt, timer = 0;
bool in_stack[N * 25];

vector<int> points[N];
int where_line[N * 25];

vector<int> g[N * 25];
int dist[600][600];
map<PII, int> station_idx; 
stack<int> st;

inline void Tarjan(int u) {
	dfn[u] = low[u] = ++ timer;
	st.push(u);
	in_stack[u] = 1;
	
	for (int v : g[u]) {
		if (!dfn[v]) {
			Tarjan(v);
			low[u] = min(low[u], low[v]);
		} else if (in_stack[v]) {
			low[u] = min(low[u], dfn[v]);
		}
	}

	if (low[u] == dfn[u]) {
		++ scc_cnt;
		while (1) {
			int x = st.top();
			st.pop();
			in_stack[x] = 0;
			bel[x] = scc_cnt;
			if (x == u) break;
		}
	}
}

inline void solve() {
	int test_case;
	int d, q;
	cin >> test_case >> n >> m >> d >> q;
	
	for (int i = 1; i <= m; i ++) {
		cin >> w[i];
	}
	
	vector<vector<int>> a(n + 1), t(n + 1);
	int cnt = m;
	
	for (int i = 1; i <= n; i ++) {
		int k;
		cin >> k;
		a[i].resize(k + 5), t[i].resize(k + 5);
		for (int j = 1; j <= k; j ++) {
			cin >> a[i][j] >> t[i][j];
			cnt ++;
			where_line[cnt] = i;
			station_idx[{i, a[i][j]}] = j;
			if (j != 1) {
				g[cnt - 1].push_back(cnt);
			} else {
				g[cnt + k - 1].push_back(cnt);
			}
			
			points[a[i][j]].push_back(cnt); 
		}
	}
	
	for (int i = m + 1; i <= cnt; i ++) {
		if (!dfn[i]) Tarjan(i);
	}
	
	for (int i = 1; i <= scc_cnt; i ++) {
		for (int j = 1; j <= scc_cnt; j ++) {
			dist[i][j] = INF;
			if (i == j) dist[i][j] = 0;
		}
	}	
	
	for (int i = 1; i <= m; i ++) {
		for (int j : points[i]) {
			for (int k : points[i]) {
				if (bel[j] == bel[k]) continue;
				dist[bel[j]][bel[k]] = dist[bel[k]][bel[j]] = min(dist[bel[j]][bel[k]], t[where_line[j]][station_idx[{where_line[j], i}]] + t[where_line[k]][station_idx[{where_line[k], i}]]);
			}
		}
	}
	
	for (int i = 1; i <= scc_cnt; i ++) {
		for (int j = 1; j <= scc_cnt; j ++) {
			for (int k = 1; k <= scc_cnt; k ++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	
	while (q --) {
		int st, ed;
		cin >> st >> ed;
		
		int ans = w[st] + w[ed];
		
		int res = INF;
		for (int i : points[st]) {
			for (int j : points[ed]) {
				res = min(res, t[where_line[i]][station_idx[{where_line[i], st}]] + t[where_line[j]][station_idx[{where_line[j], ed}]] + dist[bel[i]][bel[j]]);
			}
		}
		
		cout << ans + res << "\n";
	}
}
#undef int
int main(int argc, const char* argv[]) {
#define int ll
#ifdef LOCAL
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int t = 1;
//	cin >> t;

	while (t --) {
		solve();

	}

	return 0;
}

