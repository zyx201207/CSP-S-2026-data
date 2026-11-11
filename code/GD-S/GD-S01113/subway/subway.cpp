#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int etr[20005];
int k,a[20005],t[20005],dis[20005][20005];
int x,y;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%d",&etr[i]);
		for(int j=1;j<=m;j++)
			dis[i][j]=500005;
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&k);
		for(int j=1;j<=k;j++)
			scanf("%d%d",&a[j],&t[j]);
		for(int j=1;j<=k;j++)	
			for(int l=j+1;l<=k;l++){
					dis[a[j]][a[l]]=min(dis[a[j]][a[l]],t[j]+t[l]);
					dis[a[l]][a[j]]=min(dis[a[l]][a[j]],t[j]+t[l]);
				}
	} 
	for(int i=1;i<=m;i++)
		for(int j=i+1;j<=m;j++)
			for(int l=1;l<=m;l++){
				if(l==i||l==j) continue;
				dis[i][j]=min(dis[i][j],dis[i][l]+dis[l][j]);
				dis[j][i]=min(dis[j][i],dis[i][l]+dis[l][j]);
			}
	for(int i=1;i<=q;i++){
		scanf("%d%d",&x,&y);
		printf("%d\n",dis[x][y]+etr[x]+etr[y]);
	}
	return 0;
}
