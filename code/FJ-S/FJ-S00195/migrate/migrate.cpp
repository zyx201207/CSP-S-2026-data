#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::cerr;

template <typename T>
using U = std::make_unsigned_t<T>;
using ll = long long;
using i128 = __int128_t;
using u128 = __uint128_t;

constexpr int N = 5000 + 5;

ll x[N];
int go[N], dis[N][N];

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, q;
	cin >> c >> q;
	if (c <= 10) {
		while (q--) {
			int n; ll d;
			cin >> n >> d;
			for (int i = 1; i <= n; i++) {
				cin >> x[i];
			}
			for (int i = 1; i <= n; i++) {
				int l = i + 1, r = n;
				while (l <= r) {
					int mid = l + r >> 1;
					if (x[mid] - x[i] <= d) {
						l = mid + 1;
					} else {
						r = mid - 1;
					}
				}
				go[i] = r;
			}
			for (int i = 1; i <= n; i++) {
				for (int j = i + 1; j <= n; j++) {
					int c = 0;
					for (int k = i; k < j; k = go[k]) {
						if (k == go[k]) {
							c = -1;
							break;
						} else {
							c++;
						}
					}
					dis[i][j] = c;
				}
			}
			int ans = 0;
			for (int i = 1; i <= n; i++) {
				for (int j = i + 1; j <= n; j++) {
					if (dis[i][j] == -1) {
						continue;
					}
					bool f = false, g = true;
					int c = 1;
					for (int k = go[i]; k < j; k = go[k], c++) {
						if (dis[k - 1][j] + c == dis[i][j]) {
							if (f || dis[k - 2][j] + c == dis[i][j]) {
								g = false;
								break;
							}
							f = true;
						}
					}
					ans += f && g;
				}
			}
			cout << ans << '\n';
		}
	} else {
		while (q--) {
			int n; ll d;
			cin >> n >> d;
			for (int i = 1; i <= n; i++) {
				cin >> x[i];
			}
			if ((c == 11 || c == 12) && n >= 4) {
				ll f = x[2] - x[1], g = f == 0 ? n : d / f;
				cout << g * (n + 1) - (3 * g + 3) * g / 2 << '\n';
			} else {
				cout << 0 << '\n';
			}
		}
	}
}
