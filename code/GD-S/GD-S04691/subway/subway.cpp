//#include <bits/stdc++.h>
//using namespace std;
//typedef long long ll;
//const int N = 5e5,M = 5e2;	// N：站点；M：线路 
//const ll INF = 1e18;
//
//struct edge{
//	int v,w,nxt;
//}edges[N * 2 + 1];
//int tot,head[N + 5];
//void add(int u,int v,int w){
//	// [1,m] 为站点，(m,m + n] 为线路
//	edges[++tot] = {v,w,head[u]};
//	head[u] = tot;
//}
//
//int n,m,q,w[N + 5];
//ll d1[N + M + 5],d2[N + M + 5];
//bool f1[N + M + 5],f2[N + M + 5];
//ll bfs(int s,int t){
//	fill(d1 + 1,d1 + m + n + 1,INF);
//	fill(d2 + 1,d2 + m + n + 1,INF);
//	fill(f1 + 1,f1 + m + n + 1,0);
//	fill(f2 + 1,f2 + m + n + 1,0);
//	priority_queue<pair<ll,int>> q1,q2;
//	q1.push({0,s});
//	d1[s] = 0;
//	q2.push({0,t});
//	d2[t] = 0;
//	while (!q1.empty() || !q2.empty()){
//		if (!q1.empty()){
//			int u = q1.top().second;
//			q1.pop();
//			if (f1[u])	continue;
//			f1[u] = 1;
//			for (int i = head[u];i;i = edges[i].nxt){
//				int v = edges[i].v,w = edges[i].w;
//				if (d1[u] + w < d1[v]){
//					d1[v] = d1[u] + w;
//					q1.push({-d1[v],v});
//					if (f2[v]){
//						return d1[v] + d2[v];
//					}
//				}
//			}
//		}
//		if (!q2.empty()){
//			int u = q2.top().second;
//			q2.pop();
//			if (f2[u])	continue;
//			f2[u] = 1;
//			for (int i = head[u];i;i = edges[i].nxt){
//				int v = edges[i].v,w = edges[i].w;
//				if (d2[u] + w < d2[v]){
//					d2[v] = d2[u] + w;
//					q2.push({-d2[v],v});
//					if (f1[v]){
//						return d1[v] + d2[v];
//					}
//				}
//			}
//		}
//	}
//}
//int main(int argc, char **argv){
//	ios::sync_with_stdio(0),cin.tie(0);
////#ifndef LOCAL
//	freopen("subway.in","r",stdin);
////#endif
////#ifndef LOCAL
//	freopen("subway.out","w",stdout);
////#endif
//	int id,d;
//	cin >> id >> n >> m >> d >> q;
//	for (int i = 1;i <= m;i++){
//		cin >> w[i];
//	}
//	for (int i = 1;i <= n;i++){
//		int k;
//		cin >> k;
//		for (int j = 1;j <= k;j++){
//			int v,w;
//			cin >> v >> w;
//			add(m + i,v,w);
//			add(v,m + i,w);
//		}
//	}
//	while (q--){
//		int x,y;
//		cin >> x >> y;
//		cout << bfs(x,y) + w[x] + w[y] << '\n';
//	}
//	return 0;
//}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5,M = 5e2;	// N：站点；M：线路 
const ll INF = 1e18;

struct edge{
	int v,w,nxt;
}edges[N * 2 + 1];
int tot,head[N + M + 5];
void add(int u,int v,int w){
	// [1,m] 为站点，(m,m + n] 为线路
	edges[++tot] = {v,w,head[u]};
	head[u] = tot;
}

int n,m,q,w[N + 5];
ll dis[M + 5][M + 5];
int main(int argc, char **argv){
	ios::sync_with_stdio(0),cin.tie(0);
#ifndef LOCAL
	freopen("subway.in","r",stdin);
#endif
#ifndef LOCAL
	freopen("subway.out","w",stdout);
#endif
	int id,d;
	cin >> id >> n >> m >> d >> q;
	for (int i = 1;i <= m;i++){
		cin >> w[i];
	}
	for (int i = 1;i <= n;i++){
		int k;
		cin >> k;
		for (int j = 1;j <= k;j++){
			int v,w;
			cin >> v >> w;
			add(m + i,v,w);
			add(v,m + i,w);
		}
	}
	for (int i = 1;i <= n;i++){
		fill(&dis[i][1],&dis[i][n + 1],INF);
		dis[i][i] = 0;
	}
	for (int i = 1;i <= m;i++){
		for (int j = head[i];j;j = edges[j].nxt){
			int u = edges[j].v - m,w1 = edges[j].w;
			for (int k = head[i];k;k = edges[k].nxt){
				int v = edges[k].v - m,w2 = edges[k].w;
				dis[u][v] = dis[v][u] = min(dis[u][v],1ll * w1 + w2);
			}
		}
	}
	for (int k = 1;k <= n;k++){
		for (int i = 1;i <= n;i++){
			for (int j = 1;j <= n;j++){
				dis[i][j] = dis[j][i] = min(dis[i][j],dis[i][k] + dis[j][k]);
			}
		}
	}
	while (q--){
		int x,y;
		cin >> x >> y;
		ll mn = INF;
		for (int i = head[x];i;i = edges[i].nxt){
			int u = edges[i].v - m,w1 = edges[i].w;
			for (int j = head[y];j;j = edges[j].nxt){
				int v = edges[j].v - m,w2 = edges[j].w;
				mn = min(mn,dis[u][v] + w1 + w2);
			}
		}
		cout << mn + w[x] + w[y] << '\n';
	}
	return 0;
}

