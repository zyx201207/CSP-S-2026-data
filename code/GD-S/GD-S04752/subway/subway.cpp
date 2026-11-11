//subway
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,d;
int k[600];
int a[500005];
int cntl[500005];
struct node{
	int v;
	int w;
}f[500005][25];
ll g[600][600];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int c,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int v,w;
			cin>>v>>w;
			f[v][++cntl[v]]={i,w};
		}
	}
	memset(g,0x3f,sizeof(g));
	for(int i=1;i<=m;i++){
		for(int j=1;j<cntl[i];j++){
			for(int jj=j+1;jj<=cntl[i];jj++){
				int u=f[i][j].v,v=f[i][jj].v;
				ll w=0ll+f[i][j].w+f[i][jj].w;
				g[u][v]=g[v][u]=min(g[u][v],w);
			}
		}
	}
	for(int i=1;i<=n;i++)g[i][i]=0ll;
	for(int l=1;l<=n;l++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(l==i||l==j||i==j)continue;
				g[i][j]=min(g[i][j],g[i][l]+g[l][j]);
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		ll ans=1e18;
		for(int i=1;i<=cntl[x];i++){
			for(int j=1;j<=cntl[y];j++){
				int u=f[x][i].v,v=f[y][j].v;
				ans=min(ans,g[u][v]+f[x][i].w+f[y][j].w);
			}
		}
		cout<<ans+a[x]+a[y]<<'\n';
	}
	return 0;
}
