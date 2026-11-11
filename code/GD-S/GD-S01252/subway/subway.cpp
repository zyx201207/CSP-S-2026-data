#include<bits/stdc++.h>
#define int long long
#define P pair<int,int>
using namespace std;
const int N=5e4+5;//地铁站数 
int c,n,m,d,Q,w[N],cnt[N];//每个点的出现次数 
int dis[20*N];
vector<P> e[20*N];
vector<int> node;
bool vis[20*N];
void dij(int s) {
	for(auto i:node) dis[i]=1e18,vis[i]=0;
	priority_queue<P,vector<P>,greater<P>> q;
	q.push({0,s});
	dis[s]=0;
	vis[s]=1;
	while(!q.empty()) {
		int u=q.top().second;q.pop();
		for(auto ed:e[u]) {
			int v=ed.first,W=ed.second;
			if(dis[u]+W<dis[v]) {
				dis[v]=dis[u]+W;
				if(!vis[v]) {
					q.push({dis[v],v});
					vis[v]=1;
				}
			}
		}
	}
}
vector<P> q[N];
int ans[100005];
signed main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>c>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++) {
		cin>>w[i];
	}
	for(int i=1;i<=n;i++) {
		int k,x,y,t;
		cin>>k;
		cin>>x>>t;
		++cnt[x];
		e[x].push_back({cnt[x]*m+x,t});
		e[cnt[x]*m+x].push_back({x,t});
		for(int j=1;j<k;j++) {
			cin>>y>>t;
			++cnt[y];
			e[cnt[x]*m+x].push_back({cnt[y]*m+y,0});
			e[cnt[y]*m+y].push_back({cnt[x]*m+x,0});
			e[y].push_back({cnt[y]*m+y,t});
			e[cnt[y]*m+y].push_back({y,t});
			x=y;
		}
	}
	for(int i=1;i<=m;i++) {
		node.push_back(i);
		for(int j=1;j<=cnt[i];j++) node.push_back(j*m+i);
	}
	for(int x,y,i=1;i<=Q;i++) {
		cin>>x>>y;
		q[x].push_back({y,i});
	}
	for(int i=1;i<=m;i++) {
		if(q[i].size()) {
			dij(i);
			for(auto ed:q[i]) {
				int j=ed.first,id=ed.second;
				ans[id]=dis[j]+w[i]+w[j];
			}
		}
	}
	for(int i=1;i<=Q;i++) cout<<ans[i]<<"\n";
	return 0;
}
/*
从每条线路出都有各自的时间，同一条线路不会重复经过同一个地铁站
每个地铁站最多有 d 条线路经过，w应该只在开始和离开时会用到
从第i条线路离开或进入第j个地铁站的时间是 t[i][j]
将每一个点拆成d+2个，用虚拟源点跑最短路 
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
