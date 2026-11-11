#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,p,q;
int w[500001],cnt=0,head[501];
int tot[1000001],sum[1000001],tim[1000001];
struct node{
	int k;
}e[501];
struct point{
	int tot;
	int num[21],tim[21];
}edge[5000001];
struct bian{
	int to,w,nxt;
}path[10000001];
void add(int u,int v,int w){
	path[++cnt].to=v;
	path[cnt].w=w;
	path[cnt].nxt=head[u];
	head[u]=cnt;
}
int dis[501],vis[501],diss[501][501];
void dij(int t){
	for(int i=1;i<=n;i++) dis[i]=1e18;
	for(int i=1;i<=n;i++) vis[i]=0;
	dis[t]=0;
	priority_queue<pair<int,int> >line;
	line.push(make_pair(0,t));
	while(!line.empty()){
		int u=line.top().second;
		line.pop();
		if(vis[u]==1) continue;
		vis[u]=1;
		for(int i=head[u];i;i=path[i].nxt){
			int v=path[i].to,w=path[i].w;
			if(dis[v]<=dis[u]+w) continue;
			dis[v]=dis[u]+w;
			line.push(make_pair(-dis[v],v));
		}
	}
	for(int j=1;j<=n;j++){
		diss[t][j]=dis[j];
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout); 
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&p,&q);
	for(int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%lld",&e[i].k);
		for(int j=1;j<=e[i].k;j++){
			int a,t;
			scanf("%lld%lld",&a,&t);
			edge[a].tot++;
			edge[a].num[edge[a].tot]=i;
			edge[a].tim[edge[a].tot]=t;
		}
	}
	for(int i=1;i<=m;i++){
		for(int l=1;l<=edge[i].tot;l++){
			for(int r=1;r<=edge[i].tot;r++){
				if(l==r) continue;
				add(edge[i].num[l],edge[i].num[r],edge[i].tim[l]+edge[i].tim[r]);			
			}
		}
	}
	for(int i=1;i<=n;i++){
		dij(i);
	}
	for(int i=1;i<=q;i++){
		int u,v,ans=1e18;
		scanf("%lld%lld",&u,&v);
		for(int l=1;l<=edge[u].tot;l++){
			for(int r=1;r<=edge[v].tot;r++){
				int from=edge[u].num[l],to=edge[v].num[r];
				ans=min(ans,diss[from][to]+edge[u].tim[l]+edge[v].tim[r]);
			}
		}
		printf("%lld\n",ans+w[u]+w[v]);
	}
}
