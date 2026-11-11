#include<bits/stdc++.h>
using namespace std;
#define int long long
int w[600001];
struct node{
	int v,w;
};
vector<node> g[600001];
//1~m 地铁站点
int tot = 0;
//设：x=线路编号 ,y=站台编号 101xy 为编号 
int k[600001];
int a[1001][1001];
int t[1001][6001];
int dyz[600001];
int dis[600001];
struct qnode{
	int v,w;
	bool operator < (const qnode y) const{
		return w > y.w;
	}
};
int dij(int s,int t){
	priority_queue<qnode> q;
	memset(dis,0x3f,sizeof(dis));
	q.push({s,0});dis[s] = 0;
	while(!q.empty()){
		qnode tmp = q.top();q.pop();
		int x = tmp.v,step = tmp.w;
		if(dis[x] != step) continue;
		for(auto to : g[x]){
			if(dis[x]+to.w < dis[to.v]){
				dis[to.v] = dis[x]+to.w;
				q.push({to.v,dis[to.v]});
			}
		}
	}
//	for(int i = 1;i<=tot;i++) {
//		cout << dis[i] << " ";
//	}
//	cout << endl;
	return dis[t];
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,p,q;
	cin >> c >> n >> m >> p >> q;
	tot = m;
	for(int i = 1;i<=m;i++){
		cin >>w[i];
		g[i].push_back({++tot,w[i]});
		g[tot].push_back({i,w[i]});
		dyz[i] = tot;
	}
	for(int i = 1;i<=n;i++){
		cin >> k[i];
		for(int j = 1;j<=k[i];j++){
			cin >> a[i][j] >> t[i][j];
			if(j == 1){
				g[dyz[a[i][j]]].push_back({++tot,t[i][j]});
				g[tot].push_back({dyz[a[i][j]],t[i][j]});
			}else{
				//dyz[a[i][j]] 当前要连的站厅 
				//tot 目前站台
				//tot-1 之前的站台
				tot++;
				g[dyz[a[i][j]]].push_back({tot,t[i][j]});
				g[tot-1].push_back({tot,0});
				g[tot].push_back({dyz[a[i][j]],t[i][j]});
			}
		}
	}
//	for(int i = 1;i<=tot;i++){
//		cout << i << ":";
//		for(auto to : g[i]){
//			cout << "{" << to.v << "," << to.w << "} ";
//		}
//		cout << endl;
//	}
	while(q--){
		int xr,yr;
		cin >> xr >> yr;
		cout << dij(xr,yr) << endl;
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
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

*/
