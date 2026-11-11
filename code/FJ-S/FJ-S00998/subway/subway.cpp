#include <bits/stdc++.h>
#define int long long
#define ull unsigned long long

using namespace std;

int read() {
	int x = 0, f = 1; char c = getchar();
	while (!isdigit(c)) {
		if (c == '-')
			f = -1; c = getchar();
	} while (isdigit(c))
		x = x * 10 + c - '0', c = getchar();
	return x * f;
}

int c, n, m, d, q, w[500001], k[501], f[501][501];
vector<int > a[501], t[501], sta[500001], tt[500001];

signed main() {
//	system("fc subway.out subway7.ans");
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	memset(f, 0x7f, sizeof(f));
	c = read(), n = read(), m = read(), d = read(), q = read();
	for (int i = 1; i <= m; i++)
		w[i] = read();
	for (int i = 1; i <= n; i++) {
		k[i] = read(), a[i].resize(k[i] + 1), t[i].resize(k[i] + 1); f[i][i] = 0;
		for (int j = 1; j <= k[i]; j++)
			a[i][j] = read(), t[i][j] = read(), sta[a[i][j]].push_back(i), tt[a[i][j]].push_back(t[i][j]);
	} for (int i = 1; i <= m; i++)
		for (int j = 0; j < sta[i].size(); j++)
			for (int k = 0; k < sta[i].size(); k++) if (k != j)
				f[sta[i][j]][sta[i][k]] = min(f[sta[i][j]][sta[i][k]], tt[i][j] + tt[i][k]);
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++) if (k != i)
			for (int j = 1; j <= n; j++) if (k != j && i != j)
				if ((ull)f[i][k] + f[k][j] < f[i][j])
					f[i][j] = f[i][k] + f[k][j];
	while (q--) {
		int x = read(), y = read(), ans = f[0][0];
		for (int i = 0; i < sta[x].size(); i++)
			for (int j = 0; j < sta[y].size(); j++)
				ans = min(ans, tt[x][i] + tt[y][j] + f[sta[x][i]][sta[y][j]]);
		printf("%lld\n", ans + w[x] + w[y]);			
	} return 0;
}
