#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <map>
#include <cstring>
#include <queue>
#define ll long long
#define PU push_back
using namespace std;
const ll inf = 2e18;
const int M = 500 + 5;
const int N = 5e5 + 5;
int C, n, m, d, q, a[N], stt[N];
ll w[N], ans[N], dis[M][M];
bool vis[M];
vector<int> sub[N];
map<int, ll> t[N];
//t[i]表示第i个点（原始编号）到第j条路径所要用的时间 

struct node{
	ll w, v;
	
	bool operator < (const node &a) const {
		return this->w > a.w;
	}
};
vector<node> g[M];

void dijkstra(int st){
//	cout << "dk:" << st << "{\n";
	memset(vis, 0, sizeof vis);
	memset(dis[st], 0x3f, sizeof dis[st]);
	
	priority_queue<node> q;
	q.push({0, st});
	dis[st][st] = 0;
	while(!q.empty()){
		int u = q.top().v;
		q.pop();
		if(vis[u]) continue;
//		cout << "u:" << u << '\n';
		vis[u] = 1;
		for(node to : g[u]){
			int v = to.v;
			ll w = to.w;
			if(dis[st][u] + w < dis[st][v]){
				dis[st][v] = dis[st][u] + w;
//				cout << st << ':' << u << "->" << v << ':' << dis[st][v] << '\n';
				if(!vis[v]) q.push({dis[st][v], v});
			}
		}
	}
//	cout << "}\n";
}

//map<int, bool> visd;
//void debug(int u){
//	visd[u] = 1;
//	for(node to : g[u]){
//		cout << u << "->" << to.v << ':' << to.w << '\n';
//		if(!visd[to.v]) debug(to.v);
//	}
//}

int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	cin >> C >> m >> n >> d >> q;
	for(int i = 1; i <= n; ++i) cin >> w[i];
	for(int i = 1, k; i <= m; ++i){
		cin >> k;
		for(int j = 1, tt; j <= k; ++j){
			cin >> a[j] >> tt;
			t[a[j]][i] = tt;
			
			if(j == 1) stt[i] = a[j];
//			if(j > 1){
//				int lida = get_id(i, a[j - 1]);
//				g[lida].PU({0, ida});
//				g[ida].PU({0, lida});
////				if(ida == 57){
////					cout << lida << "->" << ida << '\n';
////				}
//			}
			
			for(int r : sub[a[j]]){
//				int idar = get_id(r, a[j]);
				g[r].PU({t[a[j]][r] + t[a[j]][i], i});
				g[i].PU({t[a[j]][r] + t[a[j]][i], r});
//				if(ida == 57){
//					cout << idar << "->" << ida << '\n';
//				}
//				if(idar == 57){
//					cout << ida << "->" << idar << '\n';
//				}
			}
			sub[a[j]].PU(i);
//			g[n + a[j]].PU({w[a[j]] + tt, i});
//			g[i].PU({w[a[j]] + tt, n + a[j]});
//			if(a[j] == 57){
//				cout << ida << "->" << a[j] << '\n';
//			}
//			if(ida == 57){
//				cout << a[j] << "->" << ida << '\n';
//			}
		}
	}
	
//	debug(57);
	for(int i = 1; i <= m; ++i) dijkstra(i);
	
	for(int i = 1; i <= q; ++i){
		int x, y;
		cin >> x >> y;
		ll ansd = inf;
		for(int rx : sub[x]){
			for(int ry : sub[y]){
				ansd = min(ansd, dis[rx][ry] + w[x] + t[x][rx] + w[y] + t[y][ry]);
//				cout << "r:" << rx << ' ' << ry << ' ' << dis[rx][ry] << '\n';
			}
		}
		cout << ansd << '\n';
	}
	
//	for(int i = 1; i <= n; ++i){
//		if(qry[i].empty()) continue;
//		dijkstra(i);
//		for(node1 r : qry[i]){
//			ans[r.id] = dis[r.v];
////			cout << "qry:" << dis[r.v] << ' ' << upd[r.v] << '\n';
//		}
//	}
//	
//	for(int i = 1; i <= q; ++i) cout << ans[i] << '\n';
	return 0;
}
/*
进站：地铁口->站厅->站台 
换乘：站台1->站厅->站台2
出战：站台->站厅->地铁口 

初步思路：
分层图，每条路径一层图，以路径编号为层数
层内边权为0，层间边权为换乘的权值和 
 
*/
