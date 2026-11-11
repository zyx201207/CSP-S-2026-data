#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[100005],k;
long long a[500005],t[500005],g[1005][1005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(g,0x3f3f,sizeof(g));
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			scanf("%lld%lld",&a[j],&t[j]);
		}
		for(int j=1;j<=k;j++){
			for(int u=j+1;u<=k;u++){
				g[a[j]][a[u]]=g[a[u]][a[j]]=min(t[j]+t[u],g[a[u]][a[j]]);
			}
		}
	}
	for(int i=1;i<=m;i++){
		g[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			for(int k=1;k<=m;k++){
				if(i!=j&&i!=k&&j!=k){
					g[i][j]=g[j][i]=min(g[i][j],g[i][k]+g[k][j]);
				}
			}
		}
	}
	int x,y;
	long long ans=0;
	while(q--){
		scanf("%d%d",&x,&y);
		ans=g[x][y]+w[x]+w[y];
		printf("%lld\n",ans);
	}
	return 0;
}
