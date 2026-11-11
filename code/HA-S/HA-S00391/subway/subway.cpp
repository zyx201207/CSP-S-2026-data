#include<bits/stdc++.h>
#define ll long long
#define pr pair<int,int>
using namespace std;
inline ll read(){
	ll r=0,w=1;char c=getchar();
	while(c<'0'||c>'9') w=(c=='-')?(-1):(w),c=getchar();
	while(c>='0'&&c<='9') r=(r<<3)+(r<<1)+(c^48),c=getchar();
	return r*w;
}const int N=500005;
ll c,n,m,d,q;
int vis[N*2],fa[N*2],dep[N*2];
ll dis[N*2],w[N*2];
struct edge{
	int to,val,nxt;
}e[N*2+N];int cnt,head[N*2+N];
void add(int u,int v,int w){
	e[++cnt].to=v;
	e[cnt].val=w;
	e[cnt].nxt=head[u];
	head[u]=cnt;
}
void dijkstra(int x){
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis[x]=0;dis[0]=0;
	vis[x]=1;
	priority_queue<pr,vector<pr>,greater<pr>>q;
	q.push({0,x});
	while(!q.empty()){
		pr nw=q.top();q.pop();
		int u=nw.second;
		for(int i=head[u];i;i=e[i].nxt){
			int v=e[i].to,w=e[i].val;
			dis[v]=min(dis[v],dis[u]+w);
			if(dis[v]==dis[u]+w) dep[v]=dep[u]+1,fa[v]=u;
			if(!vis[v]){
				vis[v]=1;
				q.push({dis[v],v});
			}
		}
	}
}
int lca(int x,int y){
	if(dep[x]<dep[y]) swap(x,y);
	while(dep[x]>dep[y]) x=fa[x];
	if(x==y) return x;
	while(dep[x]>0&&fa[x]!=fa[y]) x=fa[x],y=fa[y];
	return fa[x];
}
void Meow(){
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++) w[i]=read();
	for(int i=1;i<=n+m;i++) fa[i]=i;
	for(int i=1;i<=n;i++){
		int k=read();
		for(int j=1;j<=k;j++){
			int a=read(),t=read();
			add(a,m+i,t);
			add(m+i,a,t);
		}
	}dijkstra(1);
	while(q--){
		int x=read(),y=read();
		int cfa=lca(x,y);
		printf("%lld\n",w[x]+w[y]+abs(dis[cfa]-dis[x])+abs(dis[cfa]-dis[y]));
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int t=1;
	while(t--) Meow();
	return 0;
}

