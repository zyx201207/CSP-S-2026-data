// 对每个地铁站，更新其直接连接的线路之间的distance O(d^2*m) ，d <= 5*10^5，d <= 20
// 使用 Floyd 求出线路间最短路 O(n^3)，n <= 500 
// 对于每个计划 x, y，遍历x, y连接的线路对，求最小O(d^2*q)，q <= 10^5，d <= 20
#include <iostream>
#include <cstring>
#include <vector>
int test_pnt, line_cnt, station_cnt, max_lpass, plan_cnt;
long long const_time[500005], line_dis[505][505];
std::vector<std::pair<int, long long>> lines_in_station[500005];
int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	memset(line_dis, 0x3f, sizeof line_dis);
	std::cin >> test_pnt >> line_cnt >> station_cnt >> max_lpass >> plan_cnt;
	for (int i = 1; i <= station_cnt; ++i) std::cin >> const_time[i];
	for (int i = 1, k, t1, t2; i <= line_cnt; ++i) {
		std::cin >> k;
		for (int j = 0; j < k; ++j) {
			std::cin >> t1 >> t2;
			lines_in_station[t1].push_back({i, t2});
		}
	}
	for (int i = 0; i < station_cnt; ++i) {
		for (std::pair<int, long long> l1 : lines_in_station[i])
			for (std::pair<int, long long> l2 : lines_in_station[i]) {
				if (l1.first == l2.first) line_dis[l1.first][l2.first] = 0;
				else line_dis[l1.first][l2.first] = std::min(line_dis[l1.first][l2.first], l1.second + l2.second);
			}
	}
	for (int k = 1; k <= line_cnt; ++k) {
		for (int i = 1; i <= line_cnt; ++i) {
			for (int j = 1; j <= line_cnt; ++j) {
				line_dis[i][j] = std::min(line_dis[i][j], line_dis[i][k] + line_dis[k][j]);
			}
		}
	}
	for (int i = 0, x, y; i < plan_cnt; ++i) {
		std::cin >> x >> y;
		long long dis = 0x3f3f3f3f3f3f3f3f;
		for (std::pair<int, long long> lx : lines_in_station[x])
			for (std::pair<int, long long> ly : lines_in_station[y])
				dis = std::min(dis, lx.second + line_dis[lx.first][ly.first] + ly.second);
		std::cout << const_time[x] + dis + const_time[y] << '\n';
	}
} 

