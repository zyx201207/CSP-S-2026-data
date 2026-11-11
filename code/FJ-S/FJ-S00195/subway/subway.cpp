#include <bits/stdc++.h> 

using std::cin;
using std::cout;
using std::cerr;

template <typename T>
using U = std::make_unsigned_t<T>;
using ll = long long;
using i128 = __int128_t;
using u128 = __uint128_t;

constexpr int N = 500 + 5, M = 5e5 + 5;

int w[M]; ll f[N][N];
std::vector<int> a[M], t[M];

int read() {
	constexpr int B = 1 << 20;
	static char *p1, *p2, buf[B];
	#define gc() ((p1 == p2 && (p2 = ((p1 = buf) + fread(buf, 1, B, stdin)))), *p1++)
	int c = gc(), s = 0;
	for ( ; !isdigit(c); c = gc());
	for ( ; isdigit(c); s = s * 10 + (c ^ '0'), c = gc());
	return s;
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c = read(), n = read(), m = read(), d = read(), q = read();
	for (int i = 1; i <= m; i++) {
		w[i] = read();
	}	
	for (int i = 1; i <= n; i++) {
		int k = read();
		while (k--) {
			int a_ = read(), t_ = read();
			a[a_].push_back(i);
			t[a_].push_back(t_);
		}
	}
	memset(f, 0x3f, sizeof(f));
	for (int u = 1; u <= n; u++) {
		f[u][u] = 0;
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 0; j < a[i].size(); j++) {
			for (int k = j + 1; k < a[i].size(); k++) {
				ll &g = f[a[i][j]][a[i][k]], &h = f[a[i][k]][a[i][j]];
				h = std::min(h, g = std::min<ll>(g, t[i][j] + t[i][k]));
			}
		}
	}
	for (int k = 1; k <= n; k++) {
		for (int u = 1; u <= n; u++) {
			for (int v = 1; v <= n; v++) {
				f[u][v] = std::min(f[u][v], f[u][k] + f[k][v]);
			}
		}
	}
	while (q--) {
		int x = read(), y = read();
		ll ans = 1e18;
		for (int i = 0; i < a[x].size(); i++) {
			for (int j = 0; j < a[y].size(); j++) {
				ans = std::min(ans, t[x][i] + f[a[x][i]][a[y][j]] + t[y][j]);
			}
		}
		cout << w[x] + ans + w[y] << '\n';
	}
}
