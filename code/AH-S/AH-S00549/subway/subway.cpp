#include <bits/stdc++.h>
using namespace std;
const int N = 510;
int c, n, m, d, q, a[N][N], w[N];
int read() {
	int s = 0, f = 1; char ch = getchar();
	while (!isdigit(ch)) { if (ch == '-') f = -1; ch = getchar(); }
	while (isdigit(ch)) { s = s * 10 + ch - '0'; ch = getchar(); }
	return s * f;
}
int dfs(int x, int b, int t, int e) {
	if (b == e) return t;
	t += a[b][b];
	for (int i = 1; i <= m; i++) {
		if (a[x][i] != 0 && i <= e && i != x && i != b) t = min(t, dfs(x, i, t + a[x][i], e));
		if (a[i][b] != 0) t = min(t, dfs(i, b, t, e));
	}	
}
signed main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	c = read(), n = read(), m = read(), d = read(), q = read();
	for (int i = 1; i <= m; i++) w[i] = read();
	for (int i = 1; i <= n; i++) {
		int opt = read();
		for (int j = 1; j <= opt; j++) {
			int x = read(), y = read();
			a[i][x] = y;
		}
	}
	while (q--) {
		int p = read(), q = read();
		int k = dfs(1, p, 1e9, q);
		cout << k + a[p][p] + w[p] + w[q] << endl;
	}
	return 0;
}
