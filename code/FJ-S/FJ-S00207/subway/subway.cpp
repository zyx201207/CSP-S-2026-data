#include <bits/stdc++.h>
#define Write ios::sync_with_stdio(0);
#define by cin.tie(0);
#define Na1L0n9 cout.tie(0);
typedef long long ll;
typedef unsigned long long ull;
const int N = 500;
const int M = 5e5 + 10;
const int MOD = 998244353;
const ll INF = 1e18;
using namespace std;
ll c, n, m, d, q, w[M], s[N], dis[N][N];
vector <ll> a[N], t[N];
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	Write by Na1L0n9
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) cin >> w[i];
	for (int i = 1; i <= n; i++) {
		cin >> s[i]; a[i].push_back(114514), t[i].push_back(114514);
		for (ll j = 1, x, y; j <= s[i]; j++) cin >> x >> y, a[i].push_back(x), t[i].push_back(y); 
	}
	for (int i = 1; i <= m; i++) for (int j = 1; j <= m; j++) dis[i][j] = INF;
	for (int i = 1; i <= m; i++) dis[i][i] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= s[i]; j++) {
			for (int k = 1; k <= s[i]; k++) {
//				if (k == j) continue;
//				g[j].push_back({k, t[j] + t[k]});
				dis[a[i][j]][a[i][k]] = dis[a[i][k]][a[i][j]] = min(dis[a[i][k]][a[i][j]], t[i][j] + t[i][k]);
			}
		}
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= m; j++) {
			for (int k = 1; k <= m; k++) {
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[j][k]);
			}
		}
	}
	while (q--) {
		ll x, y;
		cin >> x >> y;
		cout << dis[x][y] + w[x] + w[y] << "\n";
	}
	return 0;
}

