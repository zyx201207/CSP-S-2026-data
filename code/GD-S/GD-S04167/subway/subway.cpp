#include <iostream>
#include <tuple>
#include <queue>
#include <vector>

int c, n, m, d, q;
int w[505];

struct node {
	int way_id, way_idx, time;
};

struct tmp {
	int id, idx, time; // 这个节点的 id 这个节点在 info[id] 中的哪一条线路 到达这个节点花的时间 
};

std::vector<int> way[505];
std::vector<node> info[505]; // 节点信息 

int bfs(int s, int e) {
	bool visited[505][505];
	std::queue<tmp> q;
	for (int i = 0; i < info[s].size(); i++) { // 遍历 s 节点所在的线路 
		q.push({s, i, info[s][i].time}); 
		visited[s][i] = true;
	}
	
	while (!q.empty()) {
		tmp now = q.front();
		q.pop();
		
//		std::cout << "Debug: " << now.id << " " << now.idx << " " << now.time << std::endl;
		if (now.id == e) {
//			std::cout << "Debug: " << now.id << " " << now.idx << " " << info[now.id][now.idx - 1].time << std::endl;
			return now.time + info[now.id][now.idx - 1].time;
		}
		
		// 不换乘
//		std::cout << info[now.id][now.idx].way_idx << " " << way[info[now.id][now.idx].way_id].size() << std::endl;
		if (info[now.id][now.idx].way_idx < way[info[now.id][now.idx].way_id].size() - 1) { // 如果不在终点站 
			// 下一个站点是 way[info[now.id][now.idx].way_id][info[now.id][now.idx].way_idx + 1]
			if (visited[way[info[now.id][now.idx].way_id][info[now.id][now.idx].way_idx + 1]][now.idx]) {
				continue;
			}
			
			q.push({way[info[now.id][now.idx].way_id][info[now.id][now.idx].way_idx + 1], now.idx, now.time});
			visited[way[info[now.id][now.idx].way_id][info[now.id][now.idx].way_idx + 1]][now.idx] = true;
		}
		
		// 换乘
		for (int i = 0; i < info[now.id].size(); i++) { // 遍历 now.id 可以换乘的线路
			if (i + 1 == info[now.id][now.idx].way_id) {
				continue;
			}
			if (visited[now.id][i]) {
				continue;
			}
			q.push({now.id, i, now.time + info[now.id][now.idx].time + info[now.id][i].time});
			visited[now.id][i] = true;
		}
	}
}

int main() {
	std::freopen("subway.in", "r", stdin);
	std::freopen("subway.out", "w", stdout);
	
	std::cin >> c >> n >> m >> d >> q;
	
	for (int i = 1; i <= m; i++) {
		std::cin >> w[i];
	}
	
	for (int i = 1; i <= n; i++) {
		int k;
		std::cin >> k;
		way[i].push_back(-1);
		for (int j = 1; j <= k; j++) {
			int x, t;
			std::cin >> x >> t;
			way[i].push_back(x); // 第 i 条线路加入 x 节点 
			info[x].push_back({i, j, t}); // 第 x 节点添加所在的线路 
//			std::cout << "Debug1: " << x << " " << i << " " << j << " " << t << " " << std::endl;
			if (x == 3) {
//				std::cout << "Debug2: " << info[3][0].time << std::endl;
			}
		}
	}
	
	while (q--) {
		int s, e;
		std::cin >> s >> e;
		std::cout << bfs(s, e) + w[s] + w[e] << std::endl;
	}
}
