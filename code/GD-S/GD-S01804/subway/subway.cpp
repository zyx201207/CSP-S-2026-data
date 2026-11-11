#include<bits/stdc++.h>
using namespace std;
const long long RP=LONG_LONG_MAX;
long long T,n,m,q,K,t[2123],d[2123][2123];
struct sub{
	long long ax,tx;
}a[2123];
void fl(long long r){
	for(int j=1;j<=n;j++)
		for(int k=1;k<=n;k++)
			if(r!=j&&r!=k&&j!=k)
				d[j][k]=min(d[j][k],d[j][r]+d[r][k]);
	return ;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld %lld %lld %lld %lld",&T,&m,&n,&q,&K);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			d[i][j]=1e9;
	for(int i=1;i<=n;i++)
		scanf("%lld ",&t[i]);
	for(int i=1,x;i<=m;i++){
		cin>>x;
		for(int j=1;j<=x;j++)
			scanf("%lld %lld ",&a[j].ax,&a[j].tx);
		for(int j=1;j<=x;j++)
			for(int k=1;k<=x;k++)
				d[a[j].ax][a[k].ax]=a[j].tx+a[k].tx;
	}
	for(int i=1;i<=n;i++)
		fl(i);
	for(int i=1,x,y;i<=K;i++)
		scanf("%d %d",&x,&y),printf("%lld\n",t[x]+d[x][y]+t[y]);
	return 0;
}
