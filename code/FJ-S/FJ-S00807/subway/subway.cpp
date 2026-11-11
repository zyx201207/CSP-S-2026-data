#include<bits/stdc++.h>
using namespace std;
#define int long long
int gra[505][505];
int c,n,m,d,q;
int a[500005];
vector<pair<int,int> > g[500005];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(gra,0x3f,sizeof(gra));
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<=n;i++){
		gra[i][i]=0;
		int x;
		scanf("%lld",&x);
		for(int j=1;j<=x;j++){
			int u,v;
			scanf("%lld%lld",&u,&v);
			g[u].push_back({i,v});
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<g[i].size();j++){
			for(int k=j+1;k<g[i].size();k++){
				int u=g[i][j].first;
				int v=g[i][k].first;
				gra[v][u]=gra[u][v]=min(gra[u][v],g[i][j].second+g[i][k].second);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				gra[i][j]=min(gra[i][j],gra[i][k]+gra[k][j]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		int u,v,ans=1e18;
		scanf("%lld%lld",&u,&v);
		for(int j=0;j<g[u].size();j++){
			for(int k=0;k<g[v].size();k++){
				int x=g[u][j].first;
				int y=g[v][k].first;
				ans=min(ans,gra[x][y]+g[u][j].second+g[v][k].second);
			}
		}
		ans+=a[u]+a[v];
		printf("%lld\n",ans);
	}
	return 0;
}
