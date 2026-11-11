#include<bits/stdc++.h>
#define eh(...) for(const auto& __VA_ARGS__)
#define pb(...) push_back(__VA_ARGS__) 
using namespace std;
using ll = long long;
const ll maxn=5e5+10;
const ll inf=1e18+7;
inline ll read(){
	ll res=0,f=1;char ch=getchar();
	while (ch<'0' || ch>'9') {if(ch=='-')f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') res=res*10+ch-'0',ch=getchar();
	return res*f; 
}

struct EDGE {
	ll v,w;
};vector <EDGE> edge[maxn];
ll owo[maxn],dp[510][510];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	ll c=read(),n=read(),m=read(),d=read(),q=read();
	for (ll i=1;i<=m;++i) owo[i]=read();
	
	for (ll i=1;i<=n;++i){
		ll k=read();
		for (ll j=1;j<=k;++j){
			ll u=read(),t=read();
			edge[u].pb({i,t});
		}
	}
	
	for (ll i=1;i<=n;++i)
		for (ll j=1;j<=n;++j)
			dp[i][j]=inf;
	for (ll i=1;i<=n;++i)
		dp[i][i]=0;
	
	for (ll u=1;u<=m;++u){
		for (ll i=0;i<edge[u].size();++i){
			for (ll j=i+1;j<edge[u].size();++j){
				ll x=edge[u][i].v,
					y=edge[u][j].v,
					t=edge[u][i].w+edge[u][j].w;
				dp[x][y]=min(dp[x][y],t);
				dp[y][x]=min(dp[y][x],t);
			}
		}
	}
	
	for (ll k=1;k<=n;++k)
		for (ll i=1;i<=n;++i)
			for (ll j=1;j<=n;++j)
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
				
	while (q--){
		ll x=read(),y=read(),ans=inf;
		eh (a : edge[x])
			eh (b : edge[y])
				ans=min(ans,a.w+dp[a.v][b.v]+b.w);
		ans+=owo[x]+owo[y];
		printf("%lld\n",ans);
	}
} 
