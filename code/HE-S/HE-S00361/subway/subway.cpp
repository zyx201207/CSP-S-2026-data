#include<bits/stdc++.h>
using namespace std;
const int N = 510 , M = 5e5+10;
int c,n,m,d,que,x,y;
long long dis[N+M];
bool vis[N+M];
int w[N],k[N];
struct edge{
	int to;
	long long dist;
};
vector<edge> g[M+N];
struct node{
	int id;
	long long dist;
	operator < (const node &x)const{
		return x.dist<dist;
	}
};

void dijkstra(int s) {
	priority_queue<node> q;
	dis[s]=0;
	q.push({s,0});
	while(!q.empty()){
		node nid=q.top();
		int u=nid.id;
		q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(int i=0;i<g[u].size();i++){
			int v=g[u][i].to;
			long long d=g[u][i].dist;
			if(dis[v]>dis[u]+d){
				dis[v]=dis[u]+d;
				q.push({v,dis[v]});
			}
		}
	}
}
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&que);
	for(int i=1; i<=m; i++) {
		scanf("%d",&w[i]);
	}
	for(int i=1; i<=n; i++) {
		scanf("%d",&k[i]);
		for(int j=1; j<=k[i]; j++) {
			int a_;
			long long t_;
			scanf("%d%lld",&a_,&t_);
			g[m+i].push_back({a_,t_});
			g[a_].push_back({m+i,t_});
		}
	}
	for(int i=1; i<=que; i++) {
		scanf("%d%d",&x,&y);
		for(int j=1; j<=n+m; j++) {
			dis[j]=1e18;
			vis[j]=0;
		}
		dijkstra(x);
		cout<<w[x]+dis[y]+w[y]<<endl;
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

32
17

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

35
16
*/
