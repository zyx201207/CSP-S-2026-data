#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <cstring>

#define N 505
#define M 500005
#define E 1000005

using namespace std;

int c,n,m,dd,qu,w[M],k[N];
long long a[M],t[M];
int idx,kou[M]; //地铁口编号
int ting[M]; //站厅编号
int tai[M][N]; //每个站的各个站台编号 

struct edge{
	int v;
	long long w;
};
vector<edge> e[E];
long long d[E];
bool vis[E];

void dijkstra(int s,int zd){
	memset(d,0x3f3f3f3f,sizeof d);
	memset(vis,0,sizeof vis);
	d[s]=0;
	priority_queue<pair<int,int> > q;
	q.push({0,s});
	while(q.size()){
		auto t=q.top();q.pop();
		int u=t.second;
		if(vis[u]) continue;
		vis[u]=1;
		for(auto ed:e[u]){
			int v=ed.v,w=ed.w;
			if(d[u]+w<d[v]){
				d[v]=d[u]+w;
				q.push({-d[v],v});
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>dd>>qu;
	for(int i=1;i<=m;i++) cin>>w[i];
	
	for(int i=1;i<=m;i++){ //各个站中地铁口与站厅建边 
		kou[i]=++idx;ting[i]=++idx;
		e[kou[i]].push_back((edge){ting[i],w[i]});
		e[ting[i]].push_back((edge){kou[i],w[i]});
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++) cin>>a[j]>>t[j];
		tai[a[1]][i]=++idx;
		e[ting[a[1]]].push_back((edge){tai[a[1]][i],t[1]});
		e[tai[a[1]][i]].push_back((edge){ting[a[1]],t[1]});
		for(int j=2;j<=k[i];j++){
			//每条路线中相邻站建边 
			tai[a[j]][i]=++idx;
			e[tai[a[j]][i]].push_back((edge){tai[a[j-1]][i],0});
			e[tai[a[j-1]][i]].push_back((edge){tai[a[j]][i],0});
			//每个站台向对应站厅建边 
			e[ting[a[j]]].push_back((edge){tai[a[j]][i],t[j]});
			e[tai[a[j]][i]].push_back((edge){ting[a[j]],t[j]});
		}
	}
	for(int i=1;i<=qu;i++){
		int x,y;
		cin>>x>>y;
		dijkstra(kou[x],x);
		cout<<d[kou[y]]<<'\n';
	}
	return 0;
}
