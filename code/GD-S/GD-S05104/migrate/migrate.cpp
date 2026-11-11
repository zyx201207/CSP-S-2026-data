#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
const int N = 5005;
int c, t, n;
ll d;
ll x[N], dp[N << 1];
bitset<5005> is_arr[N];
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> c >> t;
	while (t--) {
		cin >> n >> d;
		for (int i {1}; i <= n; ++i) {
			cin >> x[i];
		}
		for (int i {1}; i <=n; ++i) {
			for (int j {1}; j <= n; ++j) {
				dp[i+j] = 0;
				is_arr[i][j] = false;
			}
		}
		ll ans {};
		for (int i {1}; i < n; ++i) {
			for (int j = i + 1; j <= n; ++j) {
				if (labs(x[i] - x[j]) <= d) {
					is_arr[i][j] = true;
				}
			}
		}
		for (int u {1}; u < n; ++u) {
			for(int v = u + 1; v <= n; ++v) {
				for (int k = u + 1; k < v; ++k) {
					if (is_arr[u][v] == false && is_arr[u][k] && is_arr[k][v]) {
						++dp[u+v];
					}
				}
			}
		}
		for (int u {1}; u < n; ++u) {
			for(int v = u + 1; v <= n; ++v) {
				if (dp[u+v] == 2) {
					++ans;
				}
			}
		}
		cout << ans/2 << '\n';
	}
	return 0;
}
