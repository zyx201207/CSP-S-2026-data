//GZ-S00098，刘信果，贵阳市第一中学
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int M = 5e5+5, N = 505, inf = 0x3f3f3f3f3f3f3f3f;
int c, n, m, d, q, w[M], dis[N][N], len[N];
vector<pair<int, int>> t[N], boss[M];

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; ++i)
		cin >> w[i];
	for (int i = 1; i <= n; ++i) {
		cin >> len[i];
		t[i].resize(len[i]+1);
		for (int j = 1; j <= len[i]; ++j) {
			cin >> t[i][j].first >> t[i][j].second;
			boss[t[i][j].first].push_back({i, t[i][j].second});
		}
		sort(t[i].begin()+1, t[i].end());
	}
	memset(dis, 0x3f, sizeof dis);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j) {
			if (i == j) dis[i][j] = 0;
			else {
				int I = 1, J = 1;
				while (I <= len[i] && J <= len[j]) {
					if (t[i][I].first == t[j][J].first)
						dis[i][j] = min(dis[i][j], t[i][I].second+t[j][J].second);
					if (t[i][I].first < t[j][J].first)
						I++;
					else
						J++;
				}
			}
		}
	for (int k = 1; k <= n; ++k)
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				dis[i][j] = min(dis[i][j], dis[i][k]+dis[k][j]);
	while (q--) {
		int s, t; cin >> s >> t;
		int ans = inf;
		for (int i = 0; i < boss[s].size(); ++i)
			for (int j = 0; j < boss[t].size(); ++j) {
				int fs = boss[s][i].first, ds = boss[s][i].second;
				int ft = boss[t][j].first, dt = boss[t][j].second;
				ans = min(ans, ds+dt+dis[fs][ft]);
			}
		cout << ans+w[s]+w[t] << endl;
	}
	return 0;
}
