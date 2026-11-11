#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 10;
int w[N];

int head[N << 1];
int to[N << 2], nxt[N << 2], val[N << 2];
int top = 0;
void add(int u, int v, int w){
	to[++top] = v;
	val[top] = w;
	nxt[top] = head[u];
	head[u] = top;
}

const int M = 5e3 + 20;
int dis[M][M];
int ddis[N << 2];

void Dijkstra(int s, int n, int dis[]){
	dis[0] = 1;
	for (int i = 1; i <= n; i++) dis[i] = 0x3f3f3f3f3f3f3f3f;
	dis[s] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	q.push({0, s});
	while(!q.empty()){
		pair<int, int> t = q.top();
		q.pop();
		if (dis[t.second] > t.first) continue;
		for (int i = head[t.second]; i; i = nxt[i]){
			if (dis[to[i]] > t.first + val[i]){
				dis[to[i]] = t.first + val[i];
				q.push({dis[to[i]], to[i]});
			}
		}
	}
}

signed main(){
	
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) cin >> w[i];
	
	int node = m;
	
	for (int i = 1; i <= n; i++){
		int k;
		cin >> k;
		
		if (c >= 7 && c <= 11){
			int u, v, t1, t2;
			cin >> u >> t1 >> v >> t2;
			add(u, v, t1 + t2);
			add(v, u, t1 + t2);
			continue;
		}
		
		if (c >= 12 && c <= 19){
			int v, t;
			cin >> v >> t;
			add(node + 1, node + 2, t);
			add(v, node + 1, 0);
			add(node + 2, v, 0);
			for (int j = 2; j <= k; j++){
				cin >> v >> t;
				add(v, node + 1, 0);
				add(node + 2, v, 0);
			}
			
			node += 2;
		}
		
		for (int j = 1; j <= k; j++){
//			if (node > (N << 1)) cout << "error for node bigger than N" << endl;
			node++;
			int v, t;
			cin >> v >> t;
			add(node, v, t);
			add(v, node, t);
			if (j != 1){
				add(node, node - 1, 0);
				add(node - 1, node, 0);
			}
		}
	}
	
//	bool choose = 0;
//	if (node <= 1e3 + 10){
////		choose = 1;
//		for (int i = 1; i <= m; i++) Dijkstra(i, node, dis[i]);
//	}
	
//	cout << 1;
//	if (node >= N) cout << "error for node bigger than N" << endl;
	
	for (int i = 1; i <= q; i++){
		int x, y;
		cin >> x >> y;
		int ans = -1;
		if (dis[x][0]) ans = dis[x][y];
		else if (dis[y][0]) ans = dis[y][x];
		else{
			if (node <= 5e3 + 10){
				Dijkstra(x, node, dis[x]);
				ans = dis[x][y];
			}
			else{
				Dijkstra(x, node, ddis);
				ans = ddis[y];
			}
		}
		cout << ans + w[x] + w[y] << endl;
	}
	return 0;
}