#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=5e5+10,maxd=21;
int c,n,m,q,d,w[maxn],dis[maxn],p[maxn],u,v,t,head[maxn],cnt;
bool vis[maxn];
struct node{
	int to,dis,nxt;
}e[maxd*maxn<<1];
void add(int u,int v,int w){
	e[++cnt]={v,w,head[u]};
	head[u]=cnt;
}
struct dijk{
	int dis,id;
	bool operator<(const dijk &a)const{
		return a.dis<dis;
	}
};
int dijkstra(int s,int t){
	priority_queue<dijk>pq;
	memset(vis,0,sizeof(vis));
	memset(dis,0x3f,sizeof(dis));
	dis[s]=0;
	pq.push({0,s});
	while(!pq.empty()){
		int x=pq.top().id;
		pq.pop();
		if(vis[x])
			continue;
		vis[x]=true;
		for(int i=head[x];i;i=e[i].nxt){
			int to=e[i].to;
			if(dis[to]>dis[x]+e[i].dis){
				dis[to]=dis[x]+e[i].dis;
				if(to==t)
					return dis[t];
				if(!vis[to])
					pq.push({dis[to],to});
			}
		}
	}
	return dis[t];
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)
		scanf("%lld",&w[i]);
	for(int i=1,k;i<=n;i++){
		scanf("%lld",&k);
		while(k--){
			scanf("%lld%lld",&u,&t);
			add(u,m+i,t),add(m+i,u,t);
		}
	}
	while(q--){
		scanf("%lld%lld",&u,&v);
		printf("%lld\n",w[u]+w[v]+dijkstra(u,v));
	}
	return 0;
}
