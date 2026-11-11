//GZ-S00433 遵义市南白中学 辜煜祺
#include <bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[2000002];
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int all=1; all<=t; all++) {
		memset(a,0,sizeof(a));
		n=0;
		d=0;
		scanf("%lld %lld",&n,&d);
		for(int i=1; i<=n; i++)
			scanf("%lld",&a[i]);
		if(d>a[n]-a[1]||d<a[2]-a[1]) {
			printf("0");
			continue;
		}
		long long k=a[2]-a[1];
		if(d>=2*k&&d<3*k&&n>3)printf("%lld",n-3);
		else printf("0");
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}

