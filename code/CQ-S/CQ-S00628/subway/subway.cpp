#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int M=5e5+5;
const int N=505;
int c,n,m,d,q;
ll w[M];
ll dis[N][N];
const ll INF=0x7f7f7f7f7f7f7f7f;
#define pii pair<int,ll>
#define fi first
#define se second
#define mkp(x,y) make_pair((x),(y))
basic_string<pii> g[M];
map<pii,ll> mp;

ll read(){
	ll x=0,t=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')t=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
	return x*t;
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read();n=read();m=read();d=read();q=read();
	for(int i=1;i<=m;i++)w[i]=read();
	for(int i=1;i<=n;i++){
		int k=read();
		for(int j=1;j<=k;j++){
			int u=read();ll t=read();
			g[u]+=mkp(i,t);mp[mkp(u,i)]=t;
		}
	}
	memset(dis,0x7f,sizeof dis);
	for(int i=1;i<=n;i++)dis[i][i]=0;
	
	for(int i=1;i<=m;i++){
		for(auto to:g[i]){
			for(auto _to:g[i]){
				dis[to.fi][_to.fi]=min(dis[to.fi][_to.fi],1ll*to.se+_to.se);
			}
		}
	}
	
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(dis[i][k]!=INF&&dis[k][j]!=INF)dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	
	while(q--){
		int x=read(),y=read();
		ll ans=INF;
		for(auto u:g[x]){
			for(auto v:g[y]){
				ans=min(ans,dis[u.fi][v.fi]+w[x]+w[y]+mp[mkp(x,u.fi)]+mp[mkp(y,v.fi)]);
			}
		}
		printf("%lld\n",ans);
	}
	
	return 0;
}
// yellow
// LIFE'S NOT OUT TO GET YOU! 
