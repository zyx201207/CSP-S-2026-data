#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
using ll = long long;
using ull = unsigned long long;

const ll N = 5e3 + 5;
ll c, t, n, d, x[N], p[N][N], cnt[N][N];

void clear() {
	for (ll i = 1; i <= n; i++) {
		for (ll j = 1; j <= n; j++) {
			if (i == j) continue;
			p[i][j] = 1e9, cnt[i][j] = 0;
		}
	}
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> c >> t;
	while (t--) {
		cin >> n >> d;
		for (ll i = 1; i <= n; i++) cin >> x[i];
		clear();
		for (ll i = 1; i <= n; i++) {
			for (ll j = i + 1; j <= n; j++) {
				if (x[j] - x[i] <= d) p[i][j] = 1, cnt[i][j] = 1;
			}
		}
		for (ll k = 1; k <= n; k++) {
			for (ll i = 1; i < k; i++) {
				for (ll j = k + 1; j <= n; j++) {
					if (p[i][k] != 1e9 && p[k][j] != 1e9) {
						if (p[i][k] + p[k][j] == p[i][j]) cnt[i][j] += cnt[i][k] * cnt[k][j];
						else if (p[i][k] + p[k][j] < p[i][j]) {
							p[i][j] = p[i][k] + p[k][j];
							cnt[i][j] = cnt[i][k] * cnt[k][j];
						}
					}
				}
			}
		}
		ll ans = 0;
		for (ll i = 1; i <= n; i++)
			for (ll j = i + 1; j <= n; j++) if (cnt[i][j] == 2) ans++;
		cout << ans << endl;
	}	
	return 0;
}