#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 1010;
int c, n, m, d, q;
int w[N];//从地铁口到站厅的时间
struct node{
	int v, w;
};
vector<node>g[N];//建图
struct date{
	int id, u, step, lw;
}; 
//大概思路
/*
把每一个站点指向它对应的路线
如果这个站点当前要去的站点与来的站点不一样，说明要换站，加上边权
不然的话变迁等于0
然后跑最短路，不知道会不会超时awa 
超时了 qwq 
*/ 



//记得开long long !!!!!!!!!!!!!!!!!!!!!!! 



bool vis[N];
long long dis[N];
void dijk(int s, int e){
	for(int i = 1;i <= m + n;i++){
		vis[i] = 0;
		dis[i] = INT_MAX;
	}
	priority_queue<pair<int, pair<int, int> > >q;
	dis[s] = 0;
	q.push({0, {s, 0}});
	while(!q.empty()){
		pair<int, pair<int, int> >now = q.top();q.pop();
		int u = now.second.first;
		int lw = now.second.second;
		if(vis[u]) continue ;
		vis[u] = 1;
		for(auto it : g[u]){
			int v = it.v, w = it.w;
			if(u > m){//说明当前点是路线 
				if(v == e){
					if(dis[v] > dis[u] + w){
						dis[v] = dis[u] + w;
						q.push({-dis[v], {v, w}});
					}
				}
				else if(dis[v] > dis[u]){
					dis[v] = dis[u];
					q.push({-dis[v], {v, w}});
				}
			}
			else{//说明当前点不是路线
				if(dis[v] > dis[u] + lw + w){
					dis[v] = dis[u] + lw + w;
					q.push({-dis[v], {v, 0}});
				}
			}
		}
	}
}
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++){
		cin >> w[i];
	}
	for(int i = 1;i <= n;i++){
		int k;
		cin >> k;
		for(int j = 1;j <= k;j++){
			int u, t;
			cin >> u >> t;
			g[u].push_back({m + i, t});
			g[m + i].push_back({u, t});
			//m + i避免与站点重复 
		} 	
	}
	while(q--){
		int x, y;
		cin >> x >> y;
		dijk(x, y);
		long long ans = dis[y];
		ans += 1ll * w[x];
		ans += 1ll * w[y];
		cout<<ans<<endl;
	}
	//qwq
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7


0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
*/

