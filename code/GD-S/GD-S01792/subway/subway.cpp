#include <cstdio>
#include <cctype>
#include <cstring>
#include <vector>
using ll = long long;
const int M = 5e5 + 5, N = 505;
int w[M];
ll dis[N][N];
struct ss {
	int a, t;
};
std::vector<ss> path[M], sp[M];
int in() {
	char ch;
	while (!isdigit(ch = getchar()));
	int ret = ch - '0';
	while (isdigit(ch = getchar())) ret = ret * 10 + ch - '0';
	return ret;
}
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c, n, m, d, q;
	c = in(), n = in(), m = in(), d = in(), q = in(), memset(dis, 0x3f, sizeof dis);
	for (int i = 1; i <= m; ++i) w[i] = in(), sp[i].reserve(20);
	for (int i = 0; i < n; ++i) {
		path[i].resize(in()), dis[i][i] = 0;
		for (ss &s : path[i]) s.a = in(), s.t = in(), sp[s.a].push_back({i, s.t});
	}
	for (int i = 0; i < n; ++i) for (const ss &s : path[i]) for (const ss &k : sp[s.a]) dis[i][k.a] = dis[k.a][i] = std::min(dis[i][k.a], s.t + 0ll + k.t);
	for (int k = 0; k < n; ++k) for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) dis[i][j] = std::min(dis[i][j], dis[i][k] + dis[k][j]);
	for (int x, y; q--;) {
		x = in(), y = in();
		ll ans = 0x7f7f7f7f7f7f7f7f;
		for (const ss &a : sp[x]) for (const ss &b : sp[y]) ans = std::min(ans, dis[a.a][b.a] + a.t + b.t);
		printf("%lld\n", ans + w[x] + w[y]);
	} 
}
