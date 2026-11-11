# include<bits/stdc++.h>

# define low(x) (x & - x)
# define int long long

using namespace std;

const int N = 2000005;

int c, T;
int n, k, ans;
int vis[N];
vector<int> to[N];

inline void dfs(int x, int fa, int mask) {
	vis[x] = 1;
	for (int i = 0; i < to[x].size(); i ++) {
		int y = to[x][i];
		if (y == fa || ! (mask & (1 << y - 1)) || vis[y]) continue;
		dfs(y, x, mask);
	}
}

int d[N];

inline void calc(int x, int fa, int dis) {
	vis[x] = 1;
	d[x] = min(d[x], dis);
	for (int i = 0; i < to[x].size(); i ++) {
		int y = to[x][i];
		if (y == fa || vis[y]) continue;
		calc(y, x, dis + 1);
	}
}

signed main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin.tie(0) -> ios :: sync_with_stdio(false);

	cin >> c >> T;
	while (T --) {
		cin >> n >> k;
		ans = n;
		for (int i = 1; i < n; i ++)
			to[i].clear();
		for (int i = 1; i < n; i ++) {
			int u, v;
			cin >> u >> v;
			to[u].push_back(v);
			to[v].push_back(u);
		}
		for (int i = 0; i < (1 << n); i ++) {
			int tot = 0;
			for (int j = 1; j <= n; j ++) {
				if (i & (1 << j - 1))
					tot ++;
				vis[j] = 0;
			}
			if (tot == k) {
				int cnt = 0;
				for (int j = 1; j <= n; j ++)
					if (i & (1 << j - 1) && ! vis[j])
						dfs(j, 0, i), cnt ++;
				if (cnt == 2) {
					for (int j = 1; j <= n; j ++)
						d[j] = n;
					for (int j = 1; j <= n; j ++) {
						for (int t = 1; t <= n; t ++)
							vis[t] = 0;
						if (i & (1 << j - 1))
							calc(j, 0, 0);
					}
					int cur = 0;
					for (int j = 1; j <= n; j ++)
						cur = max(cur, d[j]);
					ans = min(ans, cur);
				}
			}
		}
		cout << ans << "\n";
	}

	return 0;
}