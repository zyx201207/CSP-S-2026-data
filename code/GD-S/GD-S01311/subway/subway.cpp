#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500005],i,j,k,t,a[505][505],b[500005][25],e[500005][25],x,y,ans;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(i=1;i<=m;i++)scanf("%lld",&w[i]);
	for(i=1;i<=n;i++){
		scanf("%lld",&k);
		while(k--)scanf("%lld%lld",&j,&t),b[j][++b[j][0]]=i,e[j][++e[j][0]]=t;
	}
	for(i=1;i<=n;i++)for(j=1;j<=n;j++)a[i][j]=1e18;
	for(i=1;i<=n;i++)a[i][i]=0;
	for(i=1;i<=m;i++)
		for(j=1;j<=b[i][0];j++)
			for(k=j+1;k<=b[i][0];k++)
				a[b[i][j]][b[i][k]]=a[b[i][k]][b[i][j]]=min(e[i][j]+e[i][k],a[b[i][j]][b[i][k]]);
	for(k=1;k<=n;k++)
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
	while(q--){
		scanf("%lld%lld",&x,&y),ans=1e18;
		for(i=1;i<=b[x][0];i++)
			for(j=1;j<=b[y][0];j++)
				ans=min(ans,a[b[x][i]][b[y][j]]+e[x][i]+e[y][j]);
		printf("%lld\n",ans+w[x]+w[y]);
	}
	return 0;
}
