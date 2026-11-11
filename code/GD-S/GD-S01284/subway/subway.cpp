#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

using u32 = uint32_t;
using i32 = int32_t;
using u64 = uint64_t;
using i64 = int64_t;

struct lstop {
	u32 line, time;
	lstop(u32 x = 0, u32 y = 0) : line(x), time(y) {}
};

class Graph {
private:
	u32 n;
	std::vector<std::vector<u64>> dis;
public:
	Graph(u32 _n) : n(_n), dis(_n, std::vector<u64>(_n, 0x3f3f3f3f3f3f3f3full)) {
		for (u32 i = 0; i < _n; ++i) {
			dis[i][i] = 0;
		}
	}
	void addedge(u32 x, u32 y, u64 w) {
		dis[x][y] = dis[y][x] = std::min(dis[x][y], w);
	}
	void floyd() {
		for (u32 k = 0; k < n; ++k) {
			for (u32 i = 0; i < n; ++i) {
				for (u32 j = 0; j < n; ++j) {
					dis[i][j] = std::min(dis[i][j], dis[i][k] + dis[k][j]);
				}
			}
		}
	}
	u64 getdis(u32 x, u32 y) {
		return dis[x][y];
	}
};

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	u32 c, n, m, d, q;
	std::vector<u32> w;
	std::cin >> c >> n >> m >> d >> q;
	w.resize(m);
	for (u32 i = 0; i < m; ++i) {
		std::cin >> w[i];
	}
	std::vector<std::vector<lstop>> lines(m);
	for (u32 i = 0; i < n; ++i) {
		u32 k;
		std::cin >> k;
		std::vector<u64> st(k), t(k);
		for (u32 j = 0; j < k; ++j) {
			std::cin >> st[j] >> t[j];
			--st[j];
			lines[st[j]].emplace_back(i, t[j]);
		}
	}
	Graph g(n);
	for (u32 i = 0; i < m; ++i) {
		for (u32 j = 0; j < lines[i].size(); ++j) {
			for (u32 k = 0; k < j; ++k) {
				g.addedge(lines[i][j].line, lines[i][k].line, lines[i][j].time + lines[i][k].time);
			}
		}
	}
	g.floyd();
	while (q--) {
		u32 u, v;
		std::cin >> u >> v;
		--u, --v;
		u64 ans = -1ull;
		for (u32 i = 0; i < lines[u].size(); ++i) {
			for (u32 j = 0; j < lines[v].size(); ++j) {
				ans = std::min(ans, static_cast<u64>(w[u]) + w[v] + lines[u][i].time + lines[v][j].time + g.getdis(lines[u][i].line, lines[v][j].line));
			}
		}
		std::cout << ans << '\n';
	}
	std::cout << std::flush;
	return 0;
}
