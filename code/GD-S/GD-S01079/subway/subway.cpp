#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=503,M=5e5+3;
const ll inf=1e18;
int c,n,m,d,q;
ll dis[N][N],ds[M];
struct edge{
	int v;
	ll w;
};
vector<edge>g[M];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>ds[i];
	for(int i=1,k;i<=n;i++){
		cin>>k;
		for(int j=1,x,t;j<=k;j++)cin>>x>>t,g[x].push_back({i,t});
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)dis[i][j]=inf;
		dis[i][i]=0;
	}
	for(int i=1;i<=m;i++)
		for(edge j:g[i]){
			int u=j.v;ll t1=j.w;
			for(edge k:g[i]){
				int v=k.v;ll t2=k.w;
				dis[u][v]=dis[v][u]=min(dis[u][v],t1+t2);
			}
		}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int k=1;k<=n;k++)dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	while(q--){
		int u,v;cin>>u>>v;
		ll ans=inf;
		for(edge i:g[u])
			for(edge j:g[v])
				ans=min(ans,dis[i.v][j.v]+i.w+j.w);
		ans+=ds[u]+ds[v];
		cout<<ans<<"\n";
	}
	return 0;
}
