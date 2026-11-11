/*

#include <bits/stdc++.h>

char buf[1 << 17], *p1, *p2;
#define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 17, stdin), p1 == p2) ? EOF : *p1++)

inline int read() {
	register int ret = 0, ch, sign = 0;

	while (ch = getchar(), isspace(ch)) ;
	isdigit(ch) ? (ret = ch ^ 48) : (sign = ch == '-');
	while (ch = getchar(), isdigit(ch))
		ret = (ret << 3) + (ret << 1) + (ch ^ 48);

	return sign ? -ret : ret;
}

#define N ((int) 1e6)

#define OO (0x3f3f3f3f)

using std::min;
using std::max;

#define chkmin(u, v) ((u) = min(u, v))
#define chkmax(u, v) ((u) = max(u, v))

int n, k;
std::vector<int> es[N + 1];

int fa[N + 1], dep[N + 1], fir[N + 1], sec[N + 1];
void init(int u) {
	fir[u] = sec[u] = dep[u] = dep[fa[u]] + 1;

	for (int v : es[u])
		if (v ^ fa[u]) {
			fa[v] = u, init(v);
			if (fir[v] > fir[u]) sec[u] = fir[u], fir[u] = fir[v];
			else if (fir[v] > sec[u]) sec[u] = fir[v];
		}
}

int f01[N + 1], f02[N + 1], f11[N + 1], f12[N + 1];

int dp12(int u, int dist) {
	if (dist <= m) {
		int ret = f11[u];
		for (int v : es[u])
			chkmin(ret, dp12(v, max(dist + 1, (fir[v] == fir[u] ? sec[u] : fir[u]) - dep[u] + 1)));
		return ret;
	} return OO;
}

void dp(int u) {
	for (int v : es[u])
		if (v ^ fa[u]) dp(v);

	f11[u] = 1, f12[u] = 0;
	for (int v : es[u])
		if (v != fa[u] && fir[v] - dep[u] > m) {
			f11[u] += f11[v];
			chkmax(f12[u], f11[v] - dp12(v, 0));
		}
	f12[u] = f11[u] - f12[u];

	f01[u] = f02[u] = OO;
	for (int v : es[u])
		if (v ^ fa[u])
			chkmin(f01[u], dp12(v, (fir[v] == fir[u] ? sec[u] : fir[u]) - dep[u] + 1));

	int v0 = OO, v1 = OO;
	for (int v : es[u])
		if (v ^ fa[u]) {
			int nv0 = dp12(v,


int check(int m) {
	dp(1);

main()
{
	int _ = (read(), read());
	while (_ --> 0) {
		n = read(), k = read();
		for (int i = 1; i < n; i++) {
			int u = read(), v = read();
			es[u].push_back(v), es[v].push_back(u);
		}

		init(1);

		int l = 0, r = n - 1, mid;
		while (l < r) check(mid = l + r >> 1) ? (r = mid) : (l = mid + 1);

		printf("%d\n", r);

		for (int i = n; i; i--) es[i].clear(), es[i].shrink_to_fit();
	}

	return 0;
}

*/

#include <bits/stdc++.h>

char buf[1 << 17], *p1, *p2;
#define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 17, stdin), p1 == p2) ? EOF : *p1++)

inline int read() {
	register int ret = 0, ch, sign = 0;

	while (ch = getchar(), isspace(ch)) ;
	isdigit(ch) ? (ret = ch ^ 48) : (sign = ch == '-');
	while (ch = getchar(), isdigit(ch))
		ret = (ret << 3) + (ret << 1) + (ch ^ 48);

	return sign ? -ret : ret;
}

#define N ((int) 20)

#define OO (0x3f3f3f3f)

using std::min;
using std::max;

#define chkmin(u, v) ((u) = min(u, v))
#define chkmax(u, v) ((u) = max(u, v))

int n, k;
std::vector<int> es[N + 1];

int fa[N + 1], dep[N + 1], fir[N + 1], sec[N + 1];
void init(int u) {
	fir[u] = sec[u] = dep[u] = dep[fa[u]] + 1;

	for (int v : es[u])
		if (v ^ fa[u]) {
			fa[v] = u, init(v);
			if (fir[v] > fir[u]) sec[u] = fir[u], fir[u] = fir[v];
			else if (fir[v] > sec[u]) sec[u] = fir[v];
		}
}

int lca[N + 1][N + 1];

main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);

	int _ = (read(), read());
	while (_ --> 0) {
		n = read(), k = read();
		for (int i = 1; i < n; i++) {
			int u = read(), v = read();
			es[u].push_back(v), es[v].push_back(u);
		}

		init(1);

		for (int i = n; i; i--)
			for (int j = n; j; j--) {
				int x = i, y = j;
				while (x ^ y) dep[x] > dep[y] ? (x = fa[x]) : (y = fa[y]);
				lca[i][j] = y;
			}

		int ans = n;
		for (int s = (1 << n) - 1; s; s--) {
			if (__builtin_popcount(s) ^ k) continue;

			int cnt = 0;
			for (int i = 0; i < n; i++)
				cnt += (s >> i & 1) && (!fa[i + 1] || (~s >> fa[i + 1] - 1 & 1));
			if (cnt > 2) continue;

			int ret = 0;
			for (int i = 0; i < n; i++)
				if (~s >> i & 1) {
					int dist = n;
					for (int j = 0; j < n; j++)
						if (s >> j & 1)
							chkmin(dist, dep[i + 1] + dep[j + 1] - 2 * dep[lca[i + 1][j + 1]]);
					chkmax(ret, dist);
				}
			chkmin(ans, ret);
		}

		printf("%d\n", ans);

		for (int i = n; i; i--) es[i].clear(), es[i].shrink_to_fit();
	}

	return 0;
}