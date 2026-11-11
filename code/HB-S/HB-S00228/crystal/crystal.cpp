#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],sum[500005];
bool check(long long x){
	for(int i=x;i<=n;i++) if(x*a[i]-sum[i]+sum[i-x]<=m) return true;
	return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	long long low=1,high=n,mid;
	while(low<high-1){
		mid=(low+high)/2;
		if(check(mid)) low=mid;
		else high=mid-1;
	}
	if(low>=high) printf("%lld",low);
	else if(check(high)) printf("%lld",high);
	else printf("%lld",low);
	return 0;
}
