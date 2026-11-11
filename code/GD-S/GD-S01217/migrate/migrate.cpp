#include<bits/stdc++.h>
#define int long long
int a[2000005],d[2000005];
signed main(){
	std::freopen("migrate.in","r",stdin);
	std::freopen("migrate.out","w",stdout); 
	int c,t;
	scanf("%lld%lld",&c,&t);
	while(t--){
		memset(d,0x3f,sizeof d);
		int n,d;
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
		printf("%lld\n",n);
	}
}
