#include <bits/stdc++.h>

using namespace std;


const int N_MAX = 5e2 + 10;
const int M_MAX = 5e5 + 10;

int c, n, m, d, q;
int w[M_MAX];
int k[N_MAX];
int a[M_MAX], t[M_MAX];
int vis[M_MAX], dis[M_MAX];
int x, y, Ans;
int Add = 0;

int first[M_MAX], line;
int path[M_MAX][2];
struct Edge {
	int v, nxt, val;
} edge[(int) 5e7 + 10];

priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> heap;

void Addedge(int u, int v, int val) {
	edge[++line].v = v;
	edge[line].val = val;
	edge[line].nxt = first[u];
	first[u] = line;
}

void Dijkstra(int u) {
	memset(vis, 0, sizeof(vis));
	memset(dis, 0x3f, sizeof(dis));
	
	dis[u] = 0;
	
	heap.push({ 0, u });
	
	while(!heap.empty()) {
		pair<int, int> head;
		do {
			if(heap.empty()) break;
			head = heap.top();
			heap.pop();
		}
		while(vis[head.second] && !heap.empty());
		
		u = head.second;
		vis[u] = 1;
		
		for(int i = first[u]; i; i = edge[i].nxt) {
			int v = edge[i].v;
			int val = edge[i].val;
			if(!vis[v]) {
				if(edge[i].nxt) {
					for(int j = first[v]; j; j = edge[j].nxt) {
						if(edge[j].v == u) {
							Add = edge[j].val;
							break;
						}
					}
					if(dis[u] + val + Add < dis[v]) {
						dis[v] = dis[u] + val + Add;
						path[v][0] = u;
						path[v][1] = i;
						heap.push({ dis[v], v });
					}
				}
				else {
					if(dis[u] - edge[path[u][1]].val + val < dis[v]) {
						dis[v] = dis[u] - edge[path[u][1]].val + val;
						path[v][0] = u;
						path[v][1] = i;
						heap.push({ dis[v], v });
					}
				}
			}
		}
		
	}
}

void Path(int x, int y) {
	if(x == path[y][0]) {
		for(int i = first[y]; i; i = edge[i].nxt) {
			if(edge[i].v == x) {
				Ans += edge[i].val;
				break;
			}
		}
		return ;
	}
	Path(x, path[y][0]);
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for(int i = 1; i <= n; i++) {
		cin >> k[i];
		for(int j = 1; j <= k[i]; j++) {
			cin >> a[j] >> t[j];  
		}
		for(int j = 2; j < k[i]; j++) {
			Addedge(a[j - 1], a[j], t[j]);
			Addedge(a[j], a[j - 1], t[j - 1]);
		}
	}
	
	for(int i = 1; i <= q; i++) {
		cin >> x >> y;
		Dijkstra(x);
		Ans = dis[y];
		Path(x, y);
		cout << Ans + w[x] + w[y] << endl;
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

*/
