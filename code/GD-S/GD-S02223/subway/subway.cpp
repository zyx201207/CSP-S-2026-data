#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N=505,M=5e5+5;

struct edge{
	int v,w;
};
vector<edge>g[M];
int c,n,m,d,p,f[N][N],w[M];

signed main(){
	cin.tie(0),cout.tie(0),ios::sync_with_stdio(false);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(f,0x3f,sizeof f);
	for(int i=1;i<N;++i)
		f[i][i]=0;
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;++i)cin>>w[i];
	for(int i=1;i<=n;++i){
		int k,a,t;
		cin>>k;
		for(int j=1;j<=k;++j){
			cin>>a>>t;
			g[a].push_back({i,t});
		}
	}
	for(int i=1;i<=m;++i)
		for(int j=0;j<g[i].size();++j)
			for(int l=0;l<g[i].size();++l){
				int u=g[i][j].v,v=g[i][l].v,w=g[i][j].w+g[i][l].w;
				f[u][v]=min(f[u][v],w);
			}
	for(int k=1;k<=n;++k)
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	while(p--){
		int u,v,ans=1e18;
		cin>>u>>v;
		for(int i=0;i<g[u].size();++i)
			for(int j=0;j<g[v].size();++j){
				int a=g[u][i].v,b=g[v][j].v;
				ans=min(ans,f[a][b]+g[u][i].w+g[v][j].w);
			}
		cout<<ans+w[u]+w[v]<<"\n"; 
	}
}
