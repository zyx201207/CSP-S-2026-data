#include <bits/stdc++.h>
using namespace std;
const int N=505,M=500005,D=20;
const long long inf=0x3f3f3f3f3f3f3f3f;
int c,n,m,d,q;
int ww[M];
vector<pair<int,long long> > vc[M];
long long g[N][N];
void floyd(){
	for(int x=1;x<=n;x++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				g[i][j]=min(g[i][j],g[i][x]+g[x][j]);
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		scanf("%d",&ww[i]);
	}
	for(int i=1;i<=n;i++){
		int k;scanf("%d",&k);
		for(int j=1;j<=k;j++){
			int x,y;scanf("%d%d",&x,&y);
			vc[x].push_back({i,y});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			g[i][j]=inf;
		}
	}
	for(int i=1;i<=n;i++){
		g[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<vc[i].size();j++){
			for(int k=0;k<j;k++){
				long long u=vc[i][j].first,v=vc[i][k].first,w=vc[i][j].second+vc[i][k].second;
				g[u][v]=g[v][u]=min(g[u][v],w);
			}
		}
	}
	floyd();
	for(int i=1;i<=q;i++){
		int x,y;scanf("%d%d",&x,&y);
		long long ans=inf;
		for(int j=0;j<vc[x].size();j++){
			for(int k=0;k<vc[y].size();k++){
				ans=min(ans,vc[x][j].second+vc[y][k].second+g[vc[x][j].first][vc[y][k].first]);
			}
		}
		ans+=ww[x]+ww[y];
		printf("%lld\n",ans);
	}
}
