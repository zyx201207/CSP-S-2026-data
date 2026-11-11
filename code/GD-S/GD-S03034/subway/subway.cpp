#include<bits/stdc++.h>
using namespace std;
int c,x,y,n,m,d,q,w[500005],k[505],a[505][505],t[505][505],g[505][505];
pair<int,int> now;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	scanf("%d %d %d %d %d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;++i){
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			g[i][j]=0x3f3f3f3f;
		}
	}
	for(int i=1;i<=n;++i){
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];++j){
			scanf("%d",&a[i][j]);
			scanf("%d",&t[i][j]);
			for(int x=1;x<j;++x){
				g[a[i][x]][j]=t[i][j]+t[i][a[i][x]];
				g[j][a[i][x]]=t[i][j]+t[i][a[i][x]];
			}
		} 
	}
	for(int zh=1;zh<=n;++zh){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				g[i][j]=max(g[i][j],g[i][zh]+g[zh][j]);
			}
		}
	}
	for(int i=1;i<=q;++i){
		scanf("%d %d",&x,&y);
		printf("%d\n",w[x]+g[x][y]+w[y]);
	}
	
	return 0;
}

