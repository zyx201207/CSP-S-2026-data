#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

const int N = 5000, inf = 0x3f3f3f3f;

int dis[N + 5], cnt[N + 5], ind[N + 5];
vector <int> Graph[N + 5];
long long x[N + 5];

void bfs(int start) {
	memset(dis, 0x3f, sizeof(dis));
	
	queue <int> que;
	que.push(start);
	dis[start] = 0;
	
	while (!que.empty()) {
		int u = que.front();
		que.pop();
		
		for (int i = 0; i < (int)(Graph[u].size()); i++) {
			int v = Graph[u][i];
			if (dis[v] == inf) {
				dis[v] = dis[u] + 1;
				que.push(v);
			}
		}
	}
	
	return ;
}

void topu(int start) {
	memset(cnt, 0, sizeof(cnt));
	
	queue <int> que;
	que.push(start);
	cnt[start] = 1;
	
	while (!que.empty()) {
		int u = que.front();
		que.pop();
		
		for (int i = 0; i < (int)(Graph[u].size()); i++) {
			int v = Graph[u][i];
			ind[v]--;
			if (dis[u] + 1 == dis[v]) {
				cnt[v] += cnt[u];
				if (cnt[v] > 2) {
					cnt[v] = 3;
				}
			}
			if (!ind[v]) {
				que.push(v);
			} 
		}
	}
	
	return ;
}

void solution() {
	long long d;
	int n;
	cin >> n >> d; 
	
	for (int i = 1; i <= n; i++) {
		cin >> x[i];
		Graph[i].clear();
	} 
	
	for (int i = 1, j = 1; i <= n; i++) {
		while (j < n && x[j + 1] - x[i] <= d) {
			j++;
		}
		for (int k = i + 1; k <= j; k++) {
			Graph[i].push_back(k);
		}
	}
	
	long long res = 0;
	for (int i = 1; i <= n; i++) {
		memset(ind, 0, sizeof(ind));
		for (int j = i; j <= n; j++) {
			for (int k = 0; k < (int)(Graph[j].size()); k++) {
				int v = Graph[j][k];
				ind[v]++;
			}
		}
		bfs(i);
		topu(i);
		for (int j = i; j <= n; j++) {
			if (cnt[j] == 2) {
				res++;
			}
		}
	}
	cout << res << "\n";
	
	return ;
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int c, t;
	cin >> c >> t;
	
	while (t--) {
		solution();
	}
	
	return 0;
}

// 16:36 (4:36) bfs求最短路+拓扑计数 40pts 
