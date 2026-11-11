#include<bits/stdc++.h>
using namespace std;
const int maxm=5e5+5;
const int maxn=500+5;
int k[maxn];
long long dis[maxn],w[maxm],a[maxn][30],t[maxn][30];
struct Edge{
	int v;
	long long w;
};
vector<Edge> vec[maxn];
vector<pair<int,int> > p[maxm];
bool vis[maxn];
struct Node{
	long long dis;
	int u;
	bool operator >(const Node &o) const{
		return dis>o.dis;
	}
};
long long bfs(int x,int y){
	memset(vis,false,sizeof(vis));
	memset(dis,0x3f,sizeof(dis));
	priority_queue<Node,vector<Node>,greater<Node> > q;
	for(auto i:p[x]){
		q.push({w[x]+t[i.first][i.second],i.first});
		dis[i.first]=w[x]+t[i.first][i.second];
	} 
	while(!q.empty()){
		int u=q.top().u;
		q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(auto ad:vec[u]){
			int v=ad.v;
			long long w=ad.w;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				q.push({dis[v],v});
			}
		}
	}
	long long ans=0x3f3f3f3f3f3f3f3f;
	for(auto i:p[y]){
		ans=min(ans,dis[i.first]+w[y]+t[i.first][i.second]);
	}
	return ans;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c;
	scanf("%d",&c);
	int n,m,d,q;
	scanf("%d %d %d %d",&n,&m,&d,&q);
	for(int i=1;i<=m;i++) scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++){
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];j++){
			scanf("%lld %lld",&a[i][j],&t[i][j]);
			p[a[i][j]].push_back({i,j}); 
		} 
	}
	for(int i=1;i<=m;i++){
		for(auto s:p[i]){
			for(auto y:p[i]){
				int u=s.first,v=y.first,k=s.second,g=y.second;
				if(u==v) continue;
				vec[u].push_back({v,t[u][k]+t[v][g]});
				vec[v].push_back({u,t[u][k]+t[v][g]});
			}
		}
	}
	memset(dis,0x3f,sizeof(dis));
	while(q--){
		int x,y;
		scanf("%d %d",&x,&y);
		if(x==y) printf("0\n");
		else printf("%lld\n",bfs(x,y));
	}	
	return 0;
}

