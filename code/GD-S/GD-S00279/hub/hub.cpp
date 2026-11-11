#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

const int N = 1e6, inf = 0x3f3f3f3f;

vector <int> Graph[N + 5];
int dis[N + 5];
bool vis[N + 5];

void bfs(int start, int cho) {
	queue <int> que;
	que.push(start);
	
	while (!que.empty()) {
		int u = que.front();
		que.pop();
		
		for (int i = 0; i < (int)(Graph[u].size()); i++) {
			int v = Graph[u][i];
			if (!vis[v] && ((cho >> (v - 1)) & 1)) {
				vis[v] = true;
				que.push(v);
			}
		}
	}
	
	return ;
}

void cml_dis(int cho, int n) {
	memset(dis, 0x3f, sizeof(dis));
	
	queue <int> que;
	for (int i = 1; i <= n; i++) {
		if ((cho >> (i - 1)) & 1) {
			que.push(i);
			dis[i] = 0;
		}
	}
	
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

bool check(int cho, int n) {
	memset(vis, false, sizeof(vis));
	int cnt = 0;
	for (int u = 1; u <= n; u++) {
		if ((cho >> (u - 1)) & 1) {
			if (!vis[u]) {
				bfs(u, cho);
				cnt++;
			}
		}
	}
	return cnt <= 2;
}

int count(int x) {
	int cnt = 0;
	while (x) {
		cnt += (x & 1);
		x >>= 1;
	}
	return cnt;
}

void solution() {
	int n, k;
	cin >> n >> k;
	
	for (int i = 1; i <= n; i++) {
		Graph[i].clear();
	}
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		Graph[u].push_back(v);
		Graph[v].push_back(u);
	}
	
	int res = inf;
	for (int cho = 0; cho < (1 << n); cho++) {
		if (count(cho) != k || !check(cho, n)) {
			continue;
		}
		cml_dis(cho, n);
		
		int now = 0;
		for (int i = 1; i <= n; i++) {
			now = max(now, dis[i]);
		}
		res = min(res, now);
	}
	cout << res << "\n";
	
	return ;
}

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int c, t;
	cin >> c >> t;
	
	while (t--) {
		solution();
	}
	
	return 0;
}

// 18:16 (6:16) 暴力 12pts
// 四题总计 100pts + 60pts + 40pts + 12pts = 212pts 
