#include<bits/stdc++.h>
#define pii pair<long long,int>
using namespace std;
const int N=1e6+5;
const long long inf=1e18;
int cas,n,m,d,q;
int ww[N],k[N],a[505][505],t[505][505];
struct edge{
	int to;
	long long w;
	int nxt;
}e[N],gg[N];
int hd[N],tot;
void add(int u,int v,int w){
	e[++tot]={v,w,hd[u]};
	hd[u]=tot;
}
int hdg[N],totg;
void add2(int u,int v,int w){
	gg[++totg]={v,w,hdg[u]};
	hdg[u]=totg;
}
long long dis[N],diss[505][505],g[505][505];
int vis[N];
void dij(int st){
	priority_queue<pii,vector<pii>,greater<pii>>q;
	for(int i=1;i<=n;i++) dis[i]=inf,vis[i]=0;  
	dis[st]=0;
	diss[st][st]=0;
	q.push({0,st});
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=hdg[u];i;i=gg[i].nxt){
			int v=gg[i].to,w=gg[i].w;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				diss[st][v]=dis[v];
				q.push({dis[v],v});
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0); 
	cin>>cas>>n>>m>>d>>q; //n线路 m站 
	for(int i=1;i<=m;i++){
		cin>>ww[i];
	}
	//1~n:线路 n+1~n+m:地铁站  
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			add(i,a[i][j]+n,t[i][j]);
			add(a[i][j]+n,i,t[i][j]);
		}
		for(int j=1;j<=n;j++){
			g[i][j]=inf;
			if(i==j) g[i][j]=0;
		}
	}
	for(int i=n+1;i<=n+m;i++){
		for(int j=hd[i];j;j=e[j].nxt){
			int v=e[j].to;
			long long w=e[j].w;
			for(int kk=hd[i];kk;kk=e[kk].nxt){
				int vv=e[kk].to;
				long long ww=e[kk].w;
				g[v][vv]=min(g[v][vv],w+ww);
				g[vv][v]=min(g[vv][v],w+ww);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(g[i][j]!=inf) add2(i,j,g[i][j]);
		}
	}
	for(int i=1;i<=n;i++){
		dij(i);
	} 
	for(int i=1;i<=q;i++){
		int l,r;
		cin>>l>>r;
		long long ans=inf;
		for(int j=hd[l+n];j;j=e[j].nxt){
			int v=e[j].to,w=e[j].w;
			for(int kk=hd[r+n];kk;kk=e[kk].nxt){
				int vv=e[kk].to,ww=e[kk].w;
				ans=min(ans,w+ww+diss[v][vv]);
			}
		}
		cout<<ans+ww[l]+ww[r]<<'\n';
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


0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

*/
