#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
long long w[500010],k[510],f[510][510];
struct edge{
	long long v,w;
};
vector<edge>g[500010],G[500010];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++){
		scanf("%lld",&k[i]);
		for(int j=1;j<=k[i];j++){
			long long v,w;
			scanf("%lld%lld",&v,&w);
			g[m+i].push_back((edge){v,w});
			g[v].push_back((edge){m+i,w});
		}
	}
	memset(f,0x3f3f3f3f,sizeof(f));
	for(int i=m+1;i<=m+n;i++){
		f[i-m][i-m]=0;
		for(int j=0;j<g[i].size();j++){
			long long v=g[i][j].v,w1=g[i][j].w;
			for(int k=0;k<g[v].size();k++){
				long long u=g[v][k].v,w2=g[v][k].w;
				if(u==i)continue;
				f[i-m][u-m]=min(f[i-m][u-m],w1+w2);
			}
		}
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				f[i][j]=min(f[i][k]+f[k][j],f[i][j]);
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<f[i][j]<<" ";
//		}
//	}
	while(q--){
		long long u,v,ans=1e18;
		scanf("%lld%lld",&u,&v);
		for(int i=0;i<g[u].size();i++){
			for(int j=0;j<g[v].size();j++){
				ans=min(ans,w[u]+g[u][i].w+g[v][j].w+w[v]+f[g[u][i].v-m][g[v][j].v-m]);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
