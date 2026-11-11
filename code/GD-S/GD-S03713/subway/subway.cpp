#include<bits/stdc++.h>
using namespace std;
const int M=5e5+10,N=5e2+10,INF=1e9+10;
int c,n,m,d,q,w[M],k[N],t[N][M];
long long f[N][N];
vector<int>g[M];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	memset(f,INF,sizeof f);
	for(int i=1;i<=n;i++){
		scanf("%d",&k[i]);
		f[i][i]=0;
		for(int j=1;j<=k[i];j++){
			int a;
			scanf("%d",&a);
			scanf("%d",&t[i][a]);
			g[a].push_back(i);
		}
	}
	for(int i=1;i<=m;i++){
		if(g[i].size()<2)
			continue;
		for(int j=0;j<g[i].size()-1;j++){
			for(int l=j+1;l<g[i].size();l++){
				int u=g[i][j],v=g[i][l];
				f[u][v]=f[v][u]=min(f[u][v],(long long)t[u][i]+t[v][i]);
			}
		}
	}
	for(int l=1;l<=n;l++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)
				f[i][j]=f[j][i]=min(f[i][j],f[i][l]+f[l][j]);
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		long long ans=-1;
		cin>>x>>y;
		for(int u:g[x]){
			for(int v:g[y]){
				if(f[u][v]==INF)
					continue;
				if(ans<0)
					ans=(long long)w[x]+t[u][x]+f[u][v]+t[v][y]+w[y];
				else
					ans=min(ans,(long long)w[x]+t[u][x]+f[u][v]+t[v][y]+w[y]);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
