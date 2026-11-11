#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,k,a[500002],x,y;
long long w[502],dis[502][502],t[500002];//dis´Óiµ½j 
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			dis[i][j]=1e18;
		}
	}
	for(int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&k);
		for(int i=1;i<=k;i++){
			scanf("%d%lld",&a[i],&t[i]);
			for(int j=1;j<i;j++){
				dis[a[j]][a[i]]=min(dis[a[j]][a[i]],t[j]+t[i]);
			}
		}
	}
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		scanf("%d%d",&x,&y);
		printf("%lld\n",w[x]+w[y]+dis[x][y]);
	}
	return 0;
}
