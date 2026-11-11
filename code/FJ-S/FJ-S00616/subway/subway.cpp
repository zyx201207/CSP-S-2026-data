#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

char buf[1 << 20], *p1 = buf, *p2 = buf;

#define gc() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 20, stdin), p1 == p2) ? EOF : *p1++)

inline 
int read() {
	int x = 0; char c = gc();
	for (; isspace(c); c = gc());
	for (; isdigit(c); x = x * 10 + c - '0', c = gc());
	return x;
}

#undef gc

const int MAXN = 5e5 + 10;
const int MAXM = 5e2 + 10;

int n, m, q, w[MAXN]; ll f[MAXM][MAXM];

basic_string<int> g[MAXN], t[MAXN];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	read(), n = read(), m = read(), read(), q = read();
	for (int i = 1; i <= m; i++) w[i] = read();
	for (int i = 1; i <= n; i++) {
		int k = read();
		for (; k--; ) {
			int u = read(), x = read();
			g[u] += i, t[u] += x;
		}
	}
	memset(f, 0x3f, sizeof f);
	for (int i = 1; i <= n; i++) f[i][i] = 0;
	for (int i = 1; i <= m; i++) {
		int l = g[i].size();
		for (int j = 1; j < l; j++) {
			for (int k = 0; k < j; k++) {
				int u = g[i][j], v = g[i][k];
				int val = t[i][j] + t[i][k];
				f[u][v] = min<ll>(f[u][v], val);
				f[v][u] = min<ll>(f[v][u], val);
			}
		}
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
			}
		}
	}
	for (; q--; ) {
		int u = read(), v = read(); ll ans = 1e18;
		int lu = g[u].size(), lv = g[v].size();
		for (int i = 0; i < lu; i++) {
			for (int j = 0; j < lv; j++) {
				ans = min(ans, t[u][i] + t[v][j] + f[g[u][i]][g[v][j]]);
			}
		}
		printf("%lld\n", ans + w[u] + w[v]);
	}
}
