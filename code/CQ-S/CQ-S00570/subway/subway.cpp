#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double lf;
const int N = 510, M = 500100;
int c, n, m, d, q;
ll w[M];
vector<ll> a[N], t[N];
vector<pair<int, ll>> tmp[M];
ll dis[N][N];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) cin >> w[i];
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		for (int j = 1; j <= k; j++) {
			int a2;
			ll t2;
			cin >> a2 >> t2;
			a[i].push_back(a2), t[i].push_back(t2);
			tmp[a2].push_back({i, t2});
		}
	}
	memset(dis, 0x3f, sizeof(dis));
	for (int i = 1; i <= n; i++) dis[i][i] = 0;
	for (int i = 1; i <= m; i++) {
		for (auto j : tmp[i]) {
			for (auto k : tmp[i]) {
				dis[j.first][k.first] = min(dis[j.first][k.first], j.second + k.second);
			}
		}
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
	while (q--) {
		int x, y;
		cin >> x >> y;
		ll ans = 1e18;
		for (auto i : tmp[x]) {
			for (auto j : tmp[y]) {
				ans = min(ans, w[x] + w[y] + i.second + j.second + dis[i.first][j.first]);
			}
		}
		cout << ans << '\n';
	}
	return 0;
}