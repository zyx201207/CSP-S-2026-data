#include <bits/stdc++.h>
using namespace std;
int shuju,n,m,k,a,b,c,d,D,T,x[500050],dis[1010][1010];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d %d %d %d %d",&shuju,&n,&m,&D,&T);
	for(int i=1;i<=m;i++)
		scanf("%d",&x[i]);
//	if(shuju>=7 and shuju<=11){
		memset(dis,0x3f,sizeof(dis));
		for(int i=0;i<n;i++){
			scanf("%d",&k);
			if(k==1)
				scanf("%d %d",&a,&b);
			else{
				scanf("%d %d %d %d",&a,&b,&c,&d);
				dis[a][c]=b+d;
				dis[c][a]=b+d;
			}
		}
		for(int i=1;i<=m;i++)
			for(int j=1;j<=m;j++){
				if(i==j) continue;
				for(int k=1;k<=m;k++){
					if(k==i or k==j) continue;
					if(dis[i][j]>dis[i][k]+dis[k][j]){
						dis[i][j]=dis[i][k]+dis[k][j];
						dis[j][i]=dis[i][k]+dis[k][j];
					}
				}
			}
		while(T--){
			scanf("%d %d",&a,&b);
			printf("%d\n",dis[a][b]+x[a]+x[b]);
		}
//	}
//	if(shuju>=12 and shuju<=19){
//		for(int i=0;i<n;i++){
//			scanf("%d",&k);
//			for(int j=0;j<k;j++){
//				cin>>a>>b;
//			}
//		}
//	}
	return 0;
}
