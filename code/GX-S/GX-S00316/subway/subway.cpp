#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 507, maxm = 500007;
const ll ee = 1e18;
int n, m, d, q, cid, w[maxm];
int c[maxm], to[maxm][27], val[maxm][27];
ll G[maxn][maxn];
void tmin(ll &a, ll b) {
	a = min(a, b);
}
int main(void) {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);

	cin >> cid >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) cin >> w[i];
	for (int i = 1, k, a, t; i <= n; i++) {
		cin >> k;
		for (int j = 1; j <= k; j++) {
			cin >> a >> t;
			to[a][++c[a]] = i;
			val[a][c[a]] = t;
		}
	}
	memset(G, 0x3f, sizeof(G));
	for (int i = 1; i <= n; i++) G[i][i] = 0;
	for (int i = 1, C; i <= m; i++) {
		C = c[i];
		for (int x = 1; x <= C; x++) {
			for (int y = x + 1; y <= C; y++) {
				tmin(G[to[i][x]][to[i][y]], val[i][x] + val[i][y]);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			G[i][j] = G[j][i] = min(G[i][j], G[j][i]);
		}
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				tmin(G[i][j], G[i][k] + G[k][j]);
			}
		}
	}
	long long res;
	for (int i = 1, x, y; i <= q; i++) {
		cin >> x >> y;
		res = ee;
		for (int u = 1; u <= c[x]; u++) {
			for (int v = 1; v <= c[y]; v++) {
				tmin(res, G[to[x][u]][to[y][v]] + val[x][u] + val[y][v]);
			}
		}
		res += w[x] + w[y];
		cout << res << "\n";
	}

	return 0;
}