#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

inline long long read(){
	long long x = 0, f = 1;
	char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-') f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') x = (x << 3) + (x << 1) + c - '0', c = getchar();
	return x * f;
}

inline void write(long long x) {
	if (x < 0) putchar('-'), x = -x;
	if (x < 10) putchar(x + 48);
	else write(x / 10), putchar((x % 10) + 48);
}

long long c, n, m, d, q, xi, yi, a[500005], t[500005], w[500005], k[500005], maxki, f[1005][1005];
long long sum, ans;

struct edge{
	long long y, t;
};
vector<edge> g[100005];

int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	c = read(), n = read(), m = read(), d = read(), q = read();
	memset(f, 0x3f, sizeof f);
	for (int i = 1; i <= m; i++) w[i] = read();
	for (int i = 1; i <= n; i++) {
		k[i] = read();
		maxki = max(maxki, k[i]);
		for (int j = 1; j <= k[i]; j++){
			cin >> a[j] >> t[j];
			if (j > 1) {
				g[a[j]].push_back({a[j - 1], t[j] + t[j - 1]});
				g[a[j - 1]].push_back({a[j], t[j] + t[j - 1]});
				f[a[j - 1]][a[j]] = f[a[j]][a[j - 1]] = t[j] + t[j - 1];
			}
		}
	}
	if (maxki <= 2) {
		for (int k = 1; k <= m; k++)
		for (int i = 1; i <= m; i++)
		for (int j = 1; j <= m; j++) f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
		for (int i = 1; i <= q; i++) {
			xi = read(), yi = read();
			write(w[xi] + w[yi] + f[xi][yi]);
			putchar('\n');
		}

	}
	return 0;
}