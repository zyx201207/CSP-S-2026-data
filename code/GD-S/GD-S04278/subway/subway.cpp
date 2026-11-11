#include <bits/stdc++.h>
using namespace std;

const int maxn = 550, maxm = 1e3 + 10, INF = 1e9;

int c, n, m, d, q;
int w[maxm], k[maxn];
int a[maxn][maxm], t[maxn][maxm];

vector <bool> vis;

struct Edge{
	int to, v;
};

vector <Edge> G[maxm];

int x, y;

int dfs(int now, int waste) {
	for (int i = 0; i < G[now].size(); i++) {
		int l = G[now][i].to;
		
		for (int j = 1; j <= k[l]; j++) {
			if (a[l][j] == y) {
				return waste + t[l][j];
			}
		}
	}
	
	vis[now] = true;
	
	int minn = INF;
	for (int i = 0; i < G[now].size(); i++) {
		if (vis[G[now][i].to]) continue;
		
		minn = min(minn, dfs(G[now][i].to, waste + G[now][i].v));
	}
	
	vis[now] = false;
	
	return minn;
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> c >> n >> m >> d >> q;
	
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		
		for (int j = 1; j <= k[i]; j++) {
			cin >> a[i][j] >> t[i][j];
		}
	}
		
	for (int i = 1; i <= n; i++) {
		for (int ii = i + 1; ii <= n; ii++) {
			for (int j = 1; j <= k[i]; j++) {
				for (int jj = 1; jj <= k[ii]; jj++) {
					if (a[i][j] == a[ii][jj]) {
						G[i].push_back({ii, t[i][j] + t[ii][jj]});
						G[ii].push_back({i, t[i][j] + t[ii][jj]});
					}
				}
			}
		}
	}
	
	while (q--) {
		cin >> x >> y;
		
		int ans = INF;
		for (int i = 1; i <= n; i++) {
			bool flag = false;
			int p;
			
			for (int j = 1; j <= k[i]; j++) {
				if (a[i][j] == x) {
					flag = true;
					p = j;
					
					break;
				}
			}
			
			if (!flag) continue;
			
			for (int j = 1; j <= n; j++) vis[j] = false;
			
			int res = dfs(i, w[x] + t[i][p]) + w[y];
			ans = min(ans, res);
		}
		
		cout << ans << '\n';
	}
	
	return 0;
}
