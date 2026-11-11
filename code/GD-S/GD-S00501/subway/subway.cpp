#include <bits/stdc++.h>
typedef long long LL;
using namespace std;
//#define DEBUG(x, y) (cerr << "x:" << x << ' ' << (y))

constexpr int MAXN = 5e2+10, MAXM = 1e6+10, MAXD = 22, MAXQ = 2e5+10;
constexpr LL INF = 4e18;
int TC;
int n, m, d, q;
LL dis[MAXN][MAXN]; // 最短路！
int w[MAXM];
vector<pair<int, int>> mtn[MAXM]; // 连接的大点及长度 

void init() {
	memset(dis, 0x3f, sizeof(dis));
	for (int i = 1; i<=m; i++) {
		int t = mtn[i].size();
//		DEBUG(i, ' '); DEBUG(t, endl);
		for (int j = 0; j<t; j++)
			for (int k = 0; k<j; k++) {
//				DEBUG(i, endl);
				int u = mtn[i][j].first, v = mtn[i][k].first;
				LL l = mtn[i][j].second + mtn[i][k].second;
				dis[u][v] = min(dis[u][v], l);
				dis[v][u] = dis[u][v];
//				DEBUG(u, ' '); DEBUG(v, ' '); DEBUG(l, endl);
			}
	}
	for (int u = 1; u<=n; u++)
		for (int k = 1; k<=n; k++)
			for (int v = 1; v<=n; v++)
				dis[u][v] = min(dis[u][v], dis[u][k] + dis[k][v]);
	for (int i = 1; i<=n; i++) dis[i][i] = 0;
}

void solve(int u, int v) {
	LL res = 4e18;
	for (pair<int, int> p : mtn[u])
		for (pair<int, int> q : mtn[v]) {
			res = min(res, p.second + q.second + dis[p.first][q.first]);
		}
	cout << res + w[u] + w[v] << '\n';
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
//	freopen("subway7.in", "r", stdin);
//	freopen("myout.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> TC;
	cin >> n >> m >> d >> q;
	for (int i = 1; i<=m; i++) cin >> w[i];
	for (int i = 1; i<=n; i++) {
		int k;
		cin >> k;
		for (int j = 1; j<=k; j++) {
			int nd, l;
			cin >> nd >> l;
			mtn[nd].push_back( { i, l } );
		}
	}
	init();
	while (q--) {
		int x, y;
		cin >> x >> y;
		solve(x, y);
//		DEBUG(dis[x][y], endl);
	}
	return 0;
}

