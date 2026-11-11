#include <bits/stdc++.h>
#define int long long
#define pii std::pair <int, int>

int read() {
	int ret = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	while (ch >= '0' && ch <= '9') ret = ret * 10 + ch - '0', ch = getchar();
	return ret;
}

void write(int val) {
	if (val) write(val / 10), putchar(val % 10 + '0');
}

int c, N, M, D, Q, w[500010], k, a, t, u, v;
std::vector <pii> G[510];
std::vector <pii> stn[500010];
int d[510][510];
std::priority_queue <pii, std::vector <pii>, std::greater <pii> > que;

/*
d[i][j] 从第 i 条线换乘到第 j 条线的最短路 
*/

signed main() {
	freopen("subway.in", "r", stdin), freopen("subway.out", "w", stdout);
	c = read(), N = read(), M = read(), D = read(), Q = read();
	for (int i = 1; i <= M; i ++) w[i] = read();
	for (int i = 1; i <= N; i ++) {
		k = read();
		for (int j = 1; j <= k; j ++) a = read(), t = read(), stn[a].push_back({i, t});
	}
	
	for (int i = 1; i <= M; i ++)
		for (int j = 0; j < stn[i].size() - 1; j ++)
			for (int k = j + 1; k < stn[i].size(); k ++) {
				G[stn[i][j].first].push_back(
					std::make_pair(stn[i][k].first, stn[i][j].second + stn[i][k].second));
				G[stn[i][k].first].push_back(
					std::make_pair(stn[i][j].first, stn[i][j].second + stn[i][k].second));
			}
	
	for (int i = 1; i <= N; i ++) for (int j = 1; j <= N; j ++) d[i][j] = 0x3f3f3f3f3f3f3f3f;
	for (int i = 1; i <= N; i ++) {
		d[i][i] = 0, que.push({0, i});
		while (!que.empty()) {
			auto [val, now] = que.top();
			que.pop();
			
			if (val != d[i][now]) continue;
			for (auto [to, v] : G[now]) 
				if (val + v <= d[i][to]) 
					d[i][to] = val + v, que.push({d[i][to], to});
		}
	}
	
	while (Q --) {
		int ans = 0x3f3f3f3f3f3f3f3f;
		u = read(), v = read();
		for (auto [i, t1] : stn[u])
			for (auto [j, t2] : stn[v]) {
				ans = std::min(ans, t1 + t2 + d[i][j]);
			}
			
//		std::cout << ans + w[u] + w[v] << "\n";
		write(ans + w[u] + w[v]), puts("");
	}
	
	return 0;
}
