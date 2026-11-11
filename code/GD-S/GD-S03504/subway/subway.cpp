#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=505;
const int M=405;
int c,n,m,d,q,w[M],k,a[M],t[M],x,y;
int g[M][M];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)
		scanf("%lld",&w[i]);
	memset(g,0x3f,sizeof g);
	for(int i=1;i<=n;i++){
		scanf("%lld",&k); 
		for(int j=1;j<=k;j++)
			scanf("%lld%lld",&a[j],&t[j]);
		for(int j=1;j<=k;j++)
			for(int l=1;l<=k;l++){
				int u=a[j],v=a[l];
				g[u][v]=min(g[u][v],t[j]+t[l]);
			}
	}
	for(int p=1;p<=m;p++)
		for(int i=1;i<=m;i++)
			for(int j=1;j<=m;j++)
				g[i][j]=min(g[i][j],g[i][p]+g[p][j]);
	while(q--){
		scanf("%lld%lld",&x,&y);
		printf("%lld\n",w[x]+g[x][y]+w[y]); 
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
