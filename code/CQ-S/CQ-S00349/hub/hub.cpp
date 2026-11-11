#include <bits/stdc++.h>
using namespace std;
#define L(i, l, r) for (ll i = (l); i <= (r); i ++)
#define R(i, r, l) for (ll i = (r); i >= (l); i --)
using ll = long long;
namespace Sednorote {
	ll Tid, t;
	ll n, k;
	const ll N = 10;
	ll xx[N + 5], yy[N + 5], dis[N + 5][N + 5];
	void sol() {
		cin >> n >> k;
		memset(dis, 0x3f, sizeof(dis));
		L(i, 1, n) dis[i][i] = 0;
		L(i, 1, n - 1) {
			cin >> xx[i] >> yy[i];
			dis[xx[i]][yy[i]] = 1;
			dis[yy[i]][xx[i]] = 1;
		}
		L(k, 1, n) {
			L(i, 1, n) L(j, 1, n) {
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
		ll ans = 2e18;
		L(i, 0, (1ll << n) - 1) {
			ll ppc = 0;
			L(j, 0, n - 1) {
				ppc += ((i >> j) & 1);
			}
			if (ppc != k) continue;
			ll bs = 0;
			L(j, 1, n - 1) {
				if (((i >> (xx[j] - 1)) & 1) && ((i >> (yy[j] - 1)) & 1)) {
					bs ++;
				}
			}
			if (bs >= k - 2) {
//				cout << "##\n";
				ll nw = 0;
				L(j, 0, n - 1) {
					ll sw = 2e18;
					L(w, 0, n - 1) {
						if ((i >> w) & 1) {
							sw = min(sw, dis[j + 1][w + 1]);
						}
					}
//					if (sw == (ll)2e18) {
//						cout << i << ' ' << j << "&&&\n";
//					}
					nw = max(nw, sw);
				}
				ans = min(ans, nw);
			}
		}
		cout << ans << "\n";
	}
	void main() {
		cin >> Tid >> t;
		while (t--) {
			sol();
		}
	}
}
int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	Sednorote::main();
	return 0;
}

