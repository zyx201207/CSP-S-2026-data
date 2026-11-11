#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <algorithm>

#define int long long

template<typename T>
inline void Swap(T& a, T& b) {
	T tmp = a;
	a = b;
	b = tmp;
}

int c, lin, n, d, q;
int vcnt;
std::vector<int> w;
std::vector<std::vector<int>> G;

void dijkstra(int s, std::vector<int>& dis) {
	std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
	std::fill(dis.begin(), dis.end(), 1e18);
	dis[s] = 0;
	pq.emplace(0, s);
	while (!pq.empty()) {
		auto tmp = pq.top();
		pq.pop();
		int z, u;
		std::tie(z, u) = tmp;
		if (z > dis[u]) continue;
		for (int v : G[u]) {
			if (dis[v] > dis[u] + 1) {
				dis[v] = dis[u] + 1;
				pq.emplace(dis[v], v);
			}
		}
	}
}

void solve1() {
	G.resize(vcnt + 1);
	int t;
	for (int i = 1, k, u; i <= lin; ++i) {
		std::cin >> k;
		for (int j = 1; j <= k; ++j) {
			std::cin >> u >> t;
			G[u].emplace_back(n + i);
			G[n + i].emplace_back(u);
		}
	}
	std::vector<int> dis(vcnt + 1);
	std::vector<std::pair<std::pair<int, int>, int>> qry;
	std::vector<int> ans(q + 1);;
	for (int i = 1, u, v; i <= q; ++i) {
		std::cin >> u >> v;
		if (u > v) Swap(u, v);
		qry.push_back({{u, v}, i});
	}
	std::sort(qry.begin(), qry.end());
	
	dijkstra(qry.front().first.first, dis);
	int u, v, id;
	ans[qry.front().second] = dis[qry.front().first.second];
	for (int i = 1; i < q; ++i) {
		if (qry[i].first.first != qry[i - 1].first.first) dijkstra(qry[i].first.first, dis);
		ans[qry[i].second] = dis[qry[i].first.second] * t + w[qry[i].first.first] + w[qry[i].first.second];
	}
	
	for (int i = 1; i <= q; ++i) std::cout << ans[i] << '\n';
}
void solve2() {
	std::vector<std::vector<int>> dis(vcnt + 1, std::vector<int>(vcnt + 1, 1e18));
	for (int i = 1, k, u, t; i <= lin; ++i) {
		std::cin >> k;
		for (int j = 1; j <= k; ++j) {
			std::cin >> u >> t;
			dis[u][n + i] = dis[n + i][u] = t;
		}
	}
	
	for (int k = 1; k <= vcnt; ++k)
		for (int i = 1; i <= vcnt; ++i)
			for (int j = 1; j <= vcnt; ++j)
				if (dis[i][j] > dis[i][k] + dis[k][j])
					dis[i][j] = dis[i][k] + dis[k][j];
	
	for (int i = 1, u, v; i <= q; ++i) {
		std::cin >> u >> v;
		std::cout << dis[u][v] + w[u] + w[v] << '\n';
	}
}

signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);

	std::cin >> c >> lin >> n >> d >> q;
	vcnt = lin + n;
	w.resize(n + 1);
	for (int i = 1; i <= n; ++i) std::cin >> w[i];
	
	if (c >= 12 && c <= 19) {
		solve1();
	} else {
		solve2();
	}

	std::cout << std::flush;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

