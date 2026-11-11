#include <bits/stdc++.h>
using namespace std;

inline long long read(void) {
	long long x = 0, f = 1; char c = getchar();
	while (c > '9' || c < '0') {
		if (c == '-') f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') x = (x << 1) + (x << 3) + c - 48, c = getchar();
	return x * f;
}

long long c, n, m, d, q, w[500005], f[505][505];
vector<pair<long long, long long> > v[500005];

int main(void) {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	c = read(), n = read(), m = read(), d = read(), q = read();
	for (int i = 1; i <= m; i++) w[i] = read();
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) f[i][j] = i == j ? 0 : 100000000000000000;
		long long k = read();
		while (k--) {
			long long a = read(), t = read();
			v[a]. push_back({i, t});
		}
	}
	for (int i = 1; i <= m; i++)
		for (auto j : v[i])
			for (auto k : v[i])
				f[j. first][k. first] = min(f[j. first][k. first], j. second + k. second);
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
	while (q--) {
		long long nx = read(), ny = read(), ans = 1000000000000000000;
		for (auto i : v[nx])
			for (auto j : v[ny])
				ans = min(ans, w[nx] + w[ny] + f[i. first][j. first] + i. second + j. second);
		printf("%lld\n", ans);
	}
	return 0;
}
