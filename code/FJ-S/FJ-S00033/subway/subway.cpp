#include<bits/stdc++.h>
using namespace std;

const int MAXN = 505;
const int MAXM = 500005;
int ans = 0x3f3f3f3f;

int n, m, d, q;
int jz[MAXM], t[MAXM][MAXN];
int k[MAXN];

struct Edge{
	int to, line;
};
vector<Edge> g[MAXM];

//------------------------------------------------------  1~3
bool vis[MAXM]; // 与dfs配套 还有dijkstra ()
void dfs(int now, int ter, int L, int cost){
	if(now == ter){
		ans = min(ans, cost + t[ter][L]);
		return;
	}
	for(Edge edg : g[now]){
		int v = edg.to;
		int li = edg.line;
		if(vis[v]) continue;
		vis[v] = 1;
		dfs(v, ter, li, cost + ((li == L) ? (0) : (t[now][L] + t[now][li])));
		vis[v] = 0;
	}
} 
//-------------------------------------------------------- 7~11
int dist[MAXM];
struct Node{
	int x, dist;
	bool operator < (const Node& other) const {
		return dist > other.dist;
	}
};
int dijkstra(int S, int T){
	memset(dist, 0x3f, sizeof(dist));
	memset(vis, 0, sizeof(vis));
	dist[S] = 0;
	priority_queue<Node> pq;
	pq.push({S, 0});
	while(!pq.empty()){
		Node temp = pq.top();
		int u = temp.x, dis = temp.dist;
		vis[u] = 1;
		pq.pop();
		for(Edge edg : g[u]){
			int v = edg.to;
			if(vis[v]) continue;
			if(dis + t[u][edg.line]+t[v][edg.line] < dist[v]){
				dist[v] = dis + t[u][edg.line] + t[v][edg.line];
				pq.push(Node{v, dist[v]});
			}
		}
	}
	return dist[T];
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int cccccc;
	cin >> cccccc >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++){
		cin >> jz[i];
	}
	for(int i = 1; i <= n; i++){
		cin >> k[i];
		for(int j = 1, x, last=-1; j <= k[i]; j++){
			cin >> x;
			cin >> t[x][i];
			if(last != -1){
				g[x].push_back(Edge{last, i});
				g[last].push_back(Edge{x, i});
			}
			last = x;
		}
	}
	int S, T;
	while(q--){
		cin >> S >> T;
		if(cccccc <= 3){
			vis[S] = 1;
			for(int i = 1; i <= n; i++)
				if(t[S][i])
					dfs(S, T, i, t[S][i]);
			cout << jz[S] + jz[T] + ans << endl;
			continue;
		}
		if(cccccc >= 7 && cccccc <= 11){ // task A: m个结点且最多n条边 走一步，换乘一次 
			cout << jz[S] + jz[T] + dijkstra(S, T) << endl;
			continue;
		}
	}
	return 0;
}
