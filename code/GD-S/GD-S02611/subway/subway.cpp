#include<bits/stdc++.h>
using namespace std;
long long m,n,w[501000],c,d,q,t,a,k[501000],x,y;
long long lj[5500][5500];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(lj,30,sizeof(lj));
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%lld",&k[i]);
		for(int j=1;j<=k[i];j++){
			scanf("%lld%lld",&a,&t);
			lj[n+a][i]=t;
			lj[i][n+a]=t;
		}
	}
	for(int l=1;l<=n+m;l++){
		for(int i=1;i<=n+m;i++){
			for(int j=1;j<=n+m;j++){
				if(lj[i][l]+lj[l][j]<lj[i][j]){
					lj[i][j]=lj[i][l]+lj[l][j];
				}
			}
		}
	}
	for(int i=1;i<=q;i++){
		scanf("%lld%lld",&x,&y);
		printf("%lld\n",lj[n+x][n+y]+w[x]+w[y]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
