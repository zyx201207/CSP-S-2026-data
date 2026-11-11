#include <bits/stdc++.h>
#define PLI pair<long long,int>
using namespace std;
typedef long long ll;
const int N=4e4+5,N2=2005,M=8e4+5;
const ll INF=1e18;
inline int read() {
	int x=0,f=1; char ch=getchar();
	while (ch>'9'||ch<'0') {if (ch=='-') f=-1; ch=getchar();}
	while (ch>='0'&&ch<='9') {x=x*10+ch-'0'; ch=getchar();}
	return x*f;
}
int ID,n,m,dmx,Q,nd,tot=0,head[N];
bool vis[N];
ll w[N],dis[N],d[N2][N2];
struct E {int v,nxt; ll w;}e[M];
inline void AddEdge(int u,int v,ll w) {e[++tot]={v,head[u],w},head[u]=tot;}
priority_queue<PLI,vector<PLI>,greater<PLI> > q;
inline void Dijkstra(int ed) {
	while (!q.empty()) {
		int u=q.top().second; q.pop();
		if (vis[u]) continue;
		vis[u]=1;
		if (u==ed) return ;
		for (int i=head[u];i;i=e[i].nxt) {
			int v=e[i].v; ll w=e[i].w;
			if (dis[u]+w<dis[v]) dis[v]=dis[u]+w,q.push(make_pair(dis[v],v));
		}
	}
}
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ID=read(),n=read(),m=read(),dmx=read(),Q=read(); nd=m;
	for (int i=1;i<=m;i++) w[i]=read();
	for (int i=1,k,u,t;i<=n;i++) {
		k=read(),u=read(),t=read(); nd++;
		AddEdge(nd,u,t),AddEdge(u,nd,t);
		for (int j=2;j<=k;j++) {
			u=read(),t=read(),nd++;
			AddEdge(nd,u,t),AddEdge(u,nd,t),AddEdge(nd-1,nd,0),AddEdge(nd,nd-1,0);
		}
	}
	if (ID<=11&&ID>=9) {
		for (int i=1;i<=m;i++) {
			for (int j=1;j<=nd;j++) dis[j]=INF,vis[j]=0;
			while (!q.empty()) q.pop();
			dis[i]=0,q.push(make_pair(dis[i],i)); Dijkstra(0);
			for (int j=1;j<=nd;j++) d[i][j]=dis[j];
		}
	}
	while (Q--) {
		int u=read(),v=read();
		if (ID<=11&&ID>=9) printf("%lld\n",w[u]+w[v]+d[u][v]);
		else {
			for (int i=1;i<=nd;i++) dis[i]=INF,vis[i]=0;
			while (!q.empty()) q.pop();
			dis[u]=0,q.push(make_pair(dis[u],u)); Dijkstra(v);
			printf("%lld\n",dis[v]+w[u]+w[v]);
		}
	}
	return 0;
}