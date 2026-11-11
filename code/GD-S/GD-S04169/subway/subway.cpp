#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 500005;
const ll INF = 1e18;
int w[N], a[N][20], b[N][20], cnt[N];
ll dis[505][505];
int read(int x = 0) {
	char c = getchar();
	while (!isdigit(c))
		c = getchar();
	while (isdigit(c))
		x = x * 10 + c - '0',
		c = getchar();
	return x;
}
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int id = read(), n = read(), m = read(), d = read(), q = read(), x, y, z;
	for (int i = 1; i <= m; i++) w[i] = read();
	for (int i = 1; i <= n; i++) {
		x = read();
		while (x--)
			y = read(), z = read(),
			a[y][cnt[y]] = i, b[y][cnt[y]] = z, ++cnt[y];
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (i != j) dis[i][j] = INF;
	for (int i = 1; i <= m; i++)
		for (int j = 0; j < cnt[i]; j++)
			for (int k = j + 1; k < cnt[i]; k++)
				dis[a[i][j]][a[i][k]] = dis[a[i][k]][a[i][j]] = min(dis[a[i][j]][a[i][k]], 1ll * b[i][j] + b[i][k]);
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (i != j) dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
	while (q--) {
		x = read(), y = read();
		ll ans = INF;
		for (int i = 0; i < cnt[x]; i++)
			for (int j = 0; j < cnt[y]; j++)
				ans = min(ans, dis[a[x][i]][a[y][j]] + b[x][i] + b[y][j]);
		printf("%lld\n", ans + w[x] + w[y]);
	}
	return 0;
}
