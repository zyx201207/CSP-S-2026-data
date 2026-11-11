#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int n, m, c, d, q;
const int N = 505, M = 5e5 + 10, inf = 1e18;
int dis[N][N];
typedef pair <int, int> pii;
pii sta[M][21];
int cnt[M];
int w[M];
signed main(void) {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i ++) cin >> w[i];
	for (int i = 1; i <= n; i ++) {
		int k;
		cin >> k;
		for (int j = 1; j <= k; j ++) {
			int a, t;
			cin >> a >> t;
			sta[a][++ cnt[a]] = make_pair(i, t);
		}
	}
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= n; j ++) if(i != j) dis[i][j] = inf;
		dis[i][i] = 0;
	}
	for (int i = 1; i <= m; i ++) {
		for (int j = 1; j <= cnt[i]; j ++) {
			for (int k = j + 1; k <= cnt[i]; k ++) {
				int tr1 = sta[i][j].first, t1 = sta[i][j].second;
				int tr2 = sta[i][k].first, t2 = sta[i][k].second;
				dis[tr1][tr2] = min(dis[tr1][tr2], t1 + t2);
				dis[tr2][tr1] = min(dis[tr2][tr1], t1 + t2);
			}
		}
	}
	for (int k = 1; k <= n; k ++) {
		for (int i = 1; i <= n; i ++) {
			for (int j = 1; j <= n; j ++) {
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
	while (q --) {
		int x, y;
		cin >> x >> y;
		int ans = inf;
		for (int i = 1; i <= cnt[x]; i ++) {
			for (int j = 1; j <= cnt[y]; j ++) {
				int tr1 = sta[x][i].first, t1 = sta[x][i].second;
				int tr2 = sta[y][j].first, t2 = sta[y][j].second;
				ans = min(ans, t1 + t2 + dis[tr1][tr2]);
			}
		}
		cout << ans + w[x] + w[y] << endl;
	}
	return 0;
}