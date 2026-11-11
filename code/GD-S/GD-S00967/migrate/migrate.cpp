#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned ll;
using db = double;
using ldb = long db;

const int N = 2e6 + 5;
int c, t, n, mx[N];
ll d, x[N], res, s[N], f[N], g[N], h[N];

bool check(int k) {
	return mx[k - 1] != mx[k];
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> c >> t;
	while (t--) {
		cin >> n >> d;
		res = 0;
		fill(f, f + n + 1, 0);
		fill(g, g + n + 1, 0);
		fill(h, h + n + 1, 0);
		fill(s, s + n + 1, 0);
		fill(mx, mx + n + 1, 0);
		for (int i = 1; i <= n; ++i) cin >> x[i];
		for (int i = 1, j = 1; i <= n; ++i) {
			while (j < n && x[j + 1] - x[i] <= d) ++j;
			mx[i] = j;
		}
		for (int i = 1; i <= n; ++i) {
			++f[i];
			if (mx[i] == i) continue;
			if (mx[i] != mx[i - 1]) f[mx[i]] += f[i];
			else ++f[mx[i]];
		}
		for (int i = n; i; --i) {
			int j = mx[i];
			if (j == i) {
				g[i] = 1;
				continue;
			}
			if (mx[j - 1] != mx[j]) g[i] = g[j];
			else g[i] = 1;
			g[i] += mx[i] - mx[i - 1];
		}
		for (int i = 2; i <= n; ++i)
			if (!check(i))
				g[i] = 1;
		for (int i = n; i > 1; --i) {
			if (mx[i] == i) continue;
			if (mx[i] == mx[i - 1] + 1) {
				if (check(mx[i])) h[i] = h[mx[i]];
			}
			else if (mx[i] == mx[i - 1]) h[i] = g[mx[i]] - 1;
			if (!check(i - 1)) h[i] = 0;
		}
		for (int i = 2; i <= n; ++i)
			if (mx[i] != i && check(i - 1))
				h[i] += max(0, mx[i - 1] - max(mx[i - 2], i));
		for (int i = 1; i <= n; ++i) {
			int j = mx[i];
			if (j - i >= 2) {
				ll p = 0;
				if (mx[i - 1] < j - 1) p = f[i];
				else p = 1;
				res += p * h[j];
			}
		}
		cout << res << '\n';
	}
	return 0;
}
