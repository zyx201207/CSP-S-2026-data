#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define mems(x, v) memset((x), (v), sizeof (x))
#define mcpy(x, y) memcpy((x), (y), sizeof (x))
using namespace std;
typedef pair <int, int> pii;
typedef long long ll;
typedef unsigned long long ull;
typedef long double wisdom;

char buf[1 << 21], *p1 = buf, *p2 = buf;
#define getchar() p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2) ? EOF : *p1++;
inline int read() {char op = getchar(); int x = 0; while (op < 48 || op > 57) op = getchar(); while (48 <= op && op <= 57) x = (x << 1) + (x << 3) + (op ^ 48), op = getchar(); return x;}

const int N = 5e5 + 5;
int w[N]; ll G[505][505], val[N]; vector <pii> Ve[505], nd[N];
int main() {
	freopen("subway.in", "r", stdin); freopen("subway.out", "w", stdout);
	read(); int n = read(), m = read(), d = read(), q = read();
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) G[i][j] = (i == j ? 0 : (ll)1e18);
	for (int i = 1; i <= m; i++) w[i] = read();
	for (int i = 1; i <= n; i++) {
		int k = read(); Ve[i].resize(k);
		for (int j = 0; j < k; j++) Ve[i][j].first = read(), Ve[i][j].second = read(), nd[Ve[i][j].first].push_back({i, Ve[i][j].second});
	}
	mems(val, 0x3f);
	for (int i = 1; i <= n; i++) {
		for (auto [x, t] : Ve[i]) val[x] = t;
		for (int j = i + 1; j <= n; j++) {
			ll mn = 1e18; for (auto [x, t] : Ve[j]) if (~val[x]) mn = min(mn, val[x] + t);
			if (mn < 1e17) G[i][j] = G[j][i] = mn;
		}
		for (auto [x, t] : Ve[i]) val[x] = 1e18;
	}
	for (int k = 1; k <= n; k++) for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
	while (q--) {
		int S = read(), T = read(); ll ans = 1e18;
		for (auto [i, t1] : nd[S]) for (auto [j, t2] : nd[T]) ans = min(ans, G[i][j] + t1 + t2);
		printf("%lld\n", w[S] + w[T] + ans);
	}
	return 0;
}