// GZ-S00079 贵阳市第一中学 伍星恒  
// Exceptation : 32 points of 100 
#include <bits/stdc++.h>
using namespace std;

const int M = 40005;

int k, n, m, z, q;
int vis[M], a;
int x, y;
long long d[M], s[M], t;

vector< pair<int, long long> > e[M];
/* 
整体思路： 
分层图： 
第i层是第i条线路，第0层是站厅 
每个节点在本层内与线路联通的站点有边权为零的边
与第零层的这个节点有边权为从站厅走到对应线路站台的步行时间的边 
均为无向图 
第i层的j节点在编程的时候写成节点(j+(k1+k2+...+ki-1)+m)(进行一些离散化) 

于是每次询问只需要跑一遍 Dijkstra 就可以知道最小总步行时间， 
只是别忘了加上进出站的时间 s[x] + s[y] 
*/

void Dijkstra(int S){
	memset(d, 0x3f, sizeof(d));
	memset(vis, 0, sizeof(vis));
	// 上面那两个O(qnm)超级慢！ 
	priority_queue<pair<long long, int>, vector<pair<long long, int> >, greater<pair<long long, int> > > q; 
	d[S] = 0;
	q.push({d[S], S});
	while(!q.empty()){
		int u = q.top().second;
		q.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		for(int i = 0; i < e[u].size(); i++){
			int v = e[u][i].first;
			long long w = e[u][i].second;
			if(d[v] > d[u] + w){
				d[v] = d[u] + w;
				q.push({d[v], v});
			}
		}
	}
}

int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> k >> n >> m >> z >> q;
	for(int i = 1; i <= m; i++){
		cin >> s[i];
	} 
	// 建图 
	int sum = 0; 
	for(int i = 1; i <= n; i++){
		cin >> k;
		int root;
		for(int j = 1; j <= k; j++){
			cin >> a >> t;
			if(j == 1){
				root = j + m + sum;
				e[j + m + sum].push_back({a, t});
				e[a].push_back({j + m + sum, t});
			}
			else
			{
				e[root].push_back({j + m + sum, 0});
				e[j + m + sum].push_back({root, 0});
				
				e[j + m + sum].push_back({a, t});
				e[a].push_back({j + m + sum, t});
			}
		}
		sum += k;
	} 
	for(int i = 1; i <= q; i++){
		cin >> x >> y;
		Dijkstra(x);
		cout << d[y] + s[x] + s[y] << "\n";
	}
	return 0;
}
