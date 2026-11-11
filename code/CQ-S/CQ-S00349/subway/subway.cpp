#include <bits/stdc++.h>
using namespace std;
#define L(i, l, r) for (ll i = (l); i <= (r); i ++)
#define R(i, r, l) for (ll i = (r); i >= (l); i --)
using ll = long long;
namespace Sednorote {
	ll Tid, n, m, d, q;
	const ll N = 500 + 5, M = 5e5 + 5;
	ll dis[N][N], w[M], len[N];
	vector<ll> sp[M], tm[M];
	void main() {
		cin >> Tid >> n >> m >> d >> q;
		memset(dis, 0x3f, sizeof(dis));
		L(i, 1, n) dis[i][i] = 0;
		L(i, 1, m) cin >> w[i];
		L(i, 1, n) {
			cin >> len[i];
			L(j, 1, len[i]) {
				ll x, y;
				cin >> x >> y;
				sp[x].push_back(i);
				tm[x].push_back(y);
			}
		}
		L(i, 1, m) {
			ll cnt = sp[i].size();
			L(j, 0, cnt - 1) {
				ll v1 = sp[i][j];
				L(k, j + 1, cnt - 1) {
					ll v2 = sp[i][k];
					dis[v1][v2] = min(dis[v1][v2], tm[i][j] + tm[i][k]);
					dis[v2][v1] = min(dis[v2][v1], tm[i][j] + tm[i][k]);
				}
			}
		}
		L(k, 1, n) {
			L(i, 1, n) L(j, 1, n) {
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
		while (q--) {
			ll x, y;
			cin >> x >> y;
			ll cnt1 = sp[x].size(), cnt2 = sp[y].size();
			ll ans = 2e18;
			L(i, 0, cnt1 - 1) L(j, 0, cnt2 - 1) {
				ans = min(ans, dis[sp[x][i]][sp[y][j]] + tm[x][i] + tm[y][j]);
			}
			cout << ans + w[x] + w[y] << "\n";
		}
	}
}
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	Sednorote::main();
	return 0;
}

