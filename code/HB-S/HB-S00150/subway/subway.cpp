#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=505;
const int M=5e5+5;
const ll INF=100000000000000000;
int C,n,m,D,Que;
ll w[M];
struct Edge{ int v,nxt;ll t;} E[M<<1];
int h[M+N],tot;
struct Line{ int v;ll t;};
vector<Line> L[M];
ll T[N][N],dis[M+N];
struct Node{
	int v;ll t;
	bool operator <(Node x) const{
		return t>x.t;
	}
};
priority_queue<Node> Q;
int vis[N+M];
void Dj(int st){
	for(int i=1;i<=m+n;++i) vis[i]=0,dis[i]=INF;
	Q.push({st+m,dis[st+m]=0});
	while(!Q.empty()){
		int u=Q.top().v;
		Q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=h[u];i;i=E[i].nxt){
			int v=E[i].v,t=E[i].t;
			if(vis[v]) continue;
			if(dis[u]+t<dis[v])
				Q.push({v,dis[v]=dis[u]+t});
		}
	}
	for(int i=1;i<=n;++i) T[st][i]=dis[m+i];
//	for(int i=1;i<=m+n;++i) printf("%d %lld\n",i,dis[i]);
//	printf("\n");
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&C,&n,&m,&D,&Que);
	for(int i=1;i<=n;++i)
	for(int j=1;j<=n;++j) T[i][j]=INF;
	for(int i=1;i<=m;++i) scanf("%lld",&w[i]);
	for(int i=1;i<=n;++i){
		int u=i+m,k,v;
		ll t;
		scanf("%d",&k);
		while(k--){
			scanf("%d%lld",&v,&t);
			E[++tot]={v,h[u],t};
			h[u]=tot;
			E[++tot]={u,h[v],t};
			h[v]=tot;
			L[v].push_back({i,t});
		}
	}
//	for(int i=1;i<=n;++i)
//	for(int j=h[m+i];j;j=E[j].nxt){
//		printf("%d->%d %lld\n",m+i,E[j].v,E[j].t);
//	}
	for(int i=1;i<=n;++i) Dj(i);
//	for(int i=1;i<=n;++i)
//	for(int j=1;j<=n;++j)
//		printf("T[%d][%d]=%lld\n",i,j,T[i][j]);
//	for(int i=1;i<=m;++i)
//	for(auto j:L[i])
//		printf("%d->%d %lld\n",i,j.v,j.t);
	while(Que--){
		int x,y;
		ll ans=INF;
		scanf("%d%d",&x,&y);
		for(auto X:L[x])
		for(auto Y:L[y])
			ans=min(ans,X.t+Y.t+T[X.v][Y.v]);
		printf("%lld\n",ans+w[x]+w[y]);
	}
	return 0;
}
