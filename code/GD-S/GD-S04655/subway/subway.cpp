#include <bits/stdc++.h>
#define maxn 500005
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
struct node{
	int v,w;
};
int C,n,m,k,d,q,a[maxn],dis[505][505];
vector<node>g[maxn];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int u,v;
	cin>>C>>m>>n>>d>>q;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++) dis[i][j]=inf;
	}
	for(int i=1;i<=m;i++){
		cin>>k;
		for(int j=1;j<=k;j++) cin>>u>>v,g[u].push_back({i,v});
	}
	for(int i=1;i<=n;i++){
		for(int l=0;l<g[i].size();l++){
			for(int r=l+1;r<g[i].size();r++) dis[g[i][l].v][g[i][r].v]=dis[g[i][r].v][g[i][l].v]=min(dis[g[i][l].v][g[i][r].v],g[i][l].w+g[i][r].w);
		}
	}
	for(int i=1;i<=m;i++) dis[i][i]=0;
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			for(int j=i+1;j<=m;j++){
				dis[i][j]=dis[j][i]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		cin>>u>>v;int ans=inf;
		for(int l=0;l<g[u].size();l++){
			for(int r=0;r<g[v].size();r++) ans=min(ans,g[u][l].w+dis[g[u][l].v][g[v][r].v]+g[v][r].w);
		}
		cout<<a[u]+ans+a[v]<<"\n";
	}
	cout.flush();
}

