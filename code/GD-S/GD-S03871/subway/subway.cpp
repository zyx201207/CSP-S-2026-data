#include<bits/stdc++.h>
#define pii pair<int, int>
#define fi first
#define se second
#define int long long
using namespace std;
constexpr int MAXN = 5e5 + 9, INF = 0x3f3f3f3f3f3f3f3f;
int c, n, m, d, q;
int w[MAXN], dis[509][509];
vector<pii> ve[MAXN];
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++) cin >> w[i];
	for(int i = 1, k; i <= n; i++) {
		cin >> k;
		for(int j = 1, a, b; j <= k; j++) {
			cin >> a >> b;
			ve[a].push_back({i, b});
		}
	}
	memset(dis, 0x3f, sizeof(dis));
	for(int i = 1; i <= n; i++) dis[i][i] = 0;
	for(int i = 1; i <= m; i++) {
		int l = ve[i].size();
		for(int j = 0; j < l; j++) {
			for(int k = j + 1; k < l; k++) {
				auto u = ve[i][j], v = ve[i][k];
				dis[u.fi][v.fi] = dis[v.fi][u.fi] = min(dis[u.fi][v.fi], u.se + v.se);
			}
		}
	}
	for(int k = 1; k <= n; k++)
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
				
	for(int i = 1, x, y; i <= q; i++) {
		cin >> x >> y;
		int ans = INF;
		int l = ve[x].size(), r = ve[y].size();
		for(int j = 0; j < l; j++) {
			for(int k = 0; k < r; k++) {
				auto u = ve[x][j], v = ve[y][k];
				ans = min(ans, dis[u.fi][v.fi] + u.se + v.se);
			}
		}
		ans += w[x] + w[y];
		cout << ans << '\n';
	}
	return 0;
}

