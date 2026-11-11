#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,t[1000];
struct A{
	long qq,ww,ee;
}a[5][20];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)scanf("%lld",&t[i]);
	for(long long i=1;i<=n;i++){
		long long yu;
		scanf("%lld",&yu);
		for(int j=1;j<=yu;j++){
			scanf("%lld%lld",&a[i][j].ww,&a[i][j].ee);
			a[i][j].qq=yu;
		}
		while(q--){
			int lo,ro;
			scanf("%d%d",&lo,&ro);
			printf("%lld\n",t[lo]+t[ro]+a[1][lo].ee+a[1][ro].ee);
		}
	}
	return 0;
}
