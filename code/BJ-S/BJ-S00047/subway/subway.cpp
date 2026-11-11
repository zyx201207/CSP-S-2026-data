#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define gc getchar_unlocked
#define pc putchar_unlocked
#define fre(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout)
int c,n,m,d,q,sz[500010],w[500010];
ll dis[510][510];
pair<int,int>g[500010][20];
ll read(){
	ll x(0);char c(gc());
	while(c<'0'||c>'9')c=gc();
	while(c>='0'&&c<='9')x=x*10+(c^48),c=gc();
	return x;
}
inline void cmn(ll&x,const ll y){x=y<x?y:x;}
signed main(){
	fre("subway");
	cin.tie(0)->sync_with_stdio(0),memset(dis,0x3f,sizeof(dis));
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;++i)w[i]=read();
	for(int i=1,k,a;i<=n;dis[i][i]=0,++i)for(k=read();k--;)a=read(),g[a][sz[a]++]={i,read()};
	for(int i=1;i<=m;++i){
		for(int j=0;j<sz[i];++j)for(int k=0;k<j;++k){
			const pair<int,int>&u=g[i][j],v=g[i][k];
			dis[u.fi][v.fi]=min(dis[u.fi][v.fi],1ll*(u.se+v.se));
		}
	}
	for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)dis[i][j]=min(dis[i][j],dis[j][i]);
	for(int k=1;k<=n;++k)for(int i=1;i<=n;++i){
		int j=1;
		for(;j+3<=n;j+=4){
			dis[i][j]=min(dis[i][j],dis[k][i]+dis[k][j]);
			dis[i][j+1]=min(dis[i][j+1],dis[k][i]+dis[k][j+1]);
			dis[i][j+2]=min(dis[i][j+2],dis[k][i]+dis[k][j+2]);
			dis[i][j+3]=min(dis[i][j+3],dis[k][i]+dis[k][j+3]);
		}
		for(;j<=n;++j)dis[i][j]=min(dis[i][j],dis[k][i]+dis[k][j]);
	}
	while(q--){
		int x(read()),y(read());
		register ll ans=1e18;if(sz[x]>sz[y])swap(x,y);
		if(sz[y]>=16){
			for(int i=0;i<sz[x];++i){
				cmn(ans,g[x][i].se+g[y][0].se+dis[g[x][i].fi][g[y][0].fi]);
				cmn(ans,g[x][i].se+g[y][1].se+dis[g[x][i].fi][g[y][1].fi]);
				cmn(ans,g[x][i].se+g[y][2].se+dis[g[x][i].fi][g[y][2].fi]);
				cmn(ans,g[x][i].se+g[y][3].se+dis[g[x][i].fi][g[y][3].fi]);
				cmn(ans,g[x][i].se+g[y][4].se+dis[g[x][i].fi][g[y][4].fi]);
				cmn(ans,g[x][i].se+g[y][5].se+dis[g[x][i].fi][g[y][5].fi]);
				cmn(ans,g[x][i].se+g[y][6].se+dis[g[x][i].fi][g[y][6].fi]);
				cmn(ans,g[x][i].se+g[y][7].se+dis[g[x][i].fi][g[y][7].fi]);
				cmn(ans,g[x][i].se+g[y][8].se+dis[g[x][i].fi][g[y][8].fi]);
				cmn(ans,g[x][i].se+g[y][9].se+dis[g[x][i].fi][g[y][9].fi]);
				cmn(ans,g[x][i].se+g[y][10].se+dis[g[x][i].fi][g[y][10].fi]);
				cmn(ans,g[x][i].se+g[y][11].se+dis[g[x][i].fi][g[y][11].fi]);
				cmn(ans,g[x][i].se+g[y][12].se+dis[g[x][i].fi][g[y][12].fi]);
				cmn(ans,g[x][i].se+g[y][13].se+dis[g[x][i].fi][g[y][13].fi]);
				cmn(ans,g[x][i].se+g[y][14].se+dis[g[x][i].fi][g[y][14].fi]);
				cmn(ans,g[x][i].se+g[y][15].se+dis[g[x][i].fi][g[y][15].fi]);
				cmn(ans,g[x][i].se+g[y][16].se+dis[g[x][i].fi][g[y][16].fi]);
				for(int j(16);j<sz[y];++j)cmn(ans,g[x][i].se+g[y][j].se+dis[g[x][i].fi][g[y][j].fi]);
			}
		}
		else if(sz[y]>=8){
			for(int i=0;i<sz[x];++i){
				cmn(ans,g[x][i].se+g[y][0].se+dis[g[x][i].fi][g[y][0].fi]);
				cmn(ans,g[x][i].se+g[y][1].se+dis[g[x][i].fi][g[y][1].fi]);
				cmn(ans,g[x][i].se+g[y][2].se+dis[g[x][i].fi][g[y][2].fi]);
				cmn(ans,g[x][i].se+g[y][3].se+dis[g[x][i].fi][g[y][3].fi]);
				cmn(ans,g[x][i].se+g[y][4].se+dis[g[x][i].fi][g[y][4].fi]);
				cmn(ans,g[x][i].se+g[y][5].se+dis[g[x][i].fi][g[y][5].fi]);
				cmn(ans,g[x][i].se+g[y][6].se+dis[g[x][i].fi][g[y][6].fi]);
				cmn(ans,g[x][i].se+g[y][7].se+dis[g[x][i].fi][g[y][7].fi]);
				for(int j(8);j<sz[y];++j)cmn(ans,g[x][i].se+g[y][j].se+dis[g[x][i].fi][g[y][j].fi]);
			}
		}
		else for(int i=0;i<sz[x];++i)for(int j(0);j<sz[y];++j)cmn(ans,g[x][i].se+g[y][j].se+dis[g[x][i].fi][g[y][j].fi]);
		cout<<ans+w[x]+w[y]<<'\n';
	}
	return 0;
}//16:00