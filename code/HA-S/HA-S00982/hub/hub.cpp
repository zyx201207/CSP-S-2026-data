#include<bits/stdc++.h>
using namespace std;
long long n,m,a[600010],dp,ans,ddp;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(long long i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++){
		dp+=(a[i]-a[i-1])*(i-1);
		if(dp>m)break;
		ans=i;
	}
	for(long long i=1;i<=n;i++){
		printf("%lld:%lld\n",i,a[i]);
	}
	printf("%lld",ans);
	return 0;
}
//crystal·ÏÆú´úÂë 
