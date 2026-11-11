//GZ-S00016 贵阳市白云区华师一学校 闫宇凡 
#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,k,xq,yq;
long long a[5005][5005],x[5005],t[5005],ti[5005];
void sdf(){
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			for(int k=1;k<=m;k++){
				a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%lld",&ti[i]);
	}
	for(int i=1;i<=m;i++){
		a[i][i]=0;
		for(int j=1;j<=m;j++){
			a[i][j]=1e9;
		}
	}
	while(n--){
		scanf("%d",&k);
		for(int i=1;i<=k;i++){
			scanf("%lld%lld",&x[i],&t[i]);
		}
		for(int i=1;i<=k;i++){
			for(int j=i+1;j<=k;j++){
				a[x[i]][x[j]]=t[i]+t[j];
				a[x[j]][x[i]]=t[i]+t[j];
			}
		}
	}
	sdf();
	while(q--){
		scanf("%d%d",&xq,&yq);
		printf("%lld\n",a[xq][yq]+ti[xq]+ti[yq]);
	}
	return 0;
}
