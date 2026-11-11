#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q,k,x,y;
int w[500010],a[500010],dis[500010][500010];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			dis[i][j]=1e8;
		}
	}
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&k);
		for(int j=1;j<=k+k;j++){
			scanf("%d",&a[j]);
		}
		for(int j=1;j<=k;j++){
			for(int p=1;p<=k;p++){
				if(p==j){
					continue;
				}
				dis[a[j+j-1]][a[p+p-1]] = a[j+j]+a[p+p];
				dis[a[p+p-1]][a[j+j-1]] = a[j+j]+a[p+p];
			}
		}
	}
	for(k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				if(k!=i&&i!=j&&k!=j){
					dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j]);
				}
			}
		}
	}
	while(q--){
		scanf("%d%d",&x,&y);
		printf("%d\n",dis[x][y]+w[x]+w[y]);
	}
	return 0;
}
