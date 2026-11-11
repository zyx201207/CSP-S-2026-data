#include <bits/stdc++.h>
#define int long long
using namespace std;

int read(){
	int i;
	scanf("%lld",&i);
	return i;
}

int c,n,m,d,q;
int wi[200010],k[510];

int head[500510],to[1000010],nex[1000010],we[1000010],edge=1;
int dis[500510];

struct Edge{
	int v,w;
	bool operator <(Edge e)const{
		return w>e.w;
	}
};

int solve(){
	int s=read(),t=read();
	priority_queue<Edge> p;
	fill(dis+1,dis+n+m+1,-1);
	dis[s]=0;
	p.push(Edge{s,0});
	for(int u,w;!p.empty();){
		u=p.top().v,w=p.top().w,p.pop();
		if(dis[u]!=-1&&p.top().w!=dis[u])continue;
		for(int e=head[u],v;e;e=nex[e]){
			v=to[e];
			if(dis[v]!=-1&&dis[v]<=dis[u]+we[e])continue;
			dis[v]=dis[u]+we[e];
			p.push(Edge{v,dis[v]});
			if(v==t)return dis[t]+wi[s]+wi[t];
		}
	}
	return wi[s]+wi[t];
}

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);

	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++)wi[i]=read();
	for(int i=1;i<=n;i++){
		k[i]=read();
		for(int j=1,u,v,w;j<=k[i];j++){
			u=read(),v=m+i,w=read();
			nex[++edge]=head[u];
			to[head[u]=edge]=v;we[edge]=w;
			nex[++edge]=head[v];
			to[head[v]=edge]=u,we[edge]=w;
		}
	} 
	for(int i=1;i<=q;i++)printf("%lld\n",solve());

	return 0;
}

