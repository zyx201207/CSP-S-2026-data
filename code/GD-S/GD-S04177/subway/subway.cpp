#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
const int M=505,N=5e5+5;
ll dis[M][M],w[N];
int type,n,m,d,Q,k;
struct edge{int v;ll w;};
vector<edge>e[N];
ll read(){
	ll x(0);char ch=getchar();
	while(!isdigit(ch))ch=getchar();
	do x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	while(isdigit(ch));
	return x;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	type=read(),n=read(),m=read(),d=read(),Q=read();
	for(int i=1;i<=m;++i)w[i]=read();
	for(int i=1,k;i<=n;++i){
		k=read();
		for(int j=1,u;j<=k;++j){
			u=read();ll w=read();
			e[u].push_back({i,w});
		}
	}
	memset(dis,127/3,sizeof(dis));
	for(int i=1;i<=n;++i)dis[i][i]=0;
	for(int i=1;i<=m;++i)
		for(auto E : e[i])
			for(auto E2 : e[i]){
				int u=E.v,v=E2.v;
				dis[u][v]=dis[v][u]=min(dis[u][v],E.w+E2.w);
			}
	for(int k=1;k<=n;++k)
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	while(Q--){
		ll ans=1e18;
		int u=read(),v=read();
		for(auto X : e[u])
			for(auto Y : e[v])
				ans=min(ans,dis[X.v][Y.v]+X.w+Y.w);
		printf("%lld\n",ans+w[u]+w[v]);
	}
	return 0;
} 
