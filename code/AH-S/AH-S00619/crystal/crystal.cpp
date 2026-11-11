#include <bits/stdc++.h>
using namespace std;
using LL=long long;
const LL N=5E5+5;
LL n,m,a[N],sum[N];
bool check(LL mid){
	for(LL i=1;i<=n-mid+1;i++){
		LL tmp=sum[i+mid-1]-sum[i-1];
		if(labs(tmp-a[i+mid-1]*mid)<=m) return 1;
		else return 0;
	}
	return 0;
}
LL Upper(LL l,LL r){
	while(l<r){
		LL mid=(l+r)>>1;
		if(check(mid)) l=mid+1;
		else r=mid;
	}
	return l-1;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(LL i=1;i<=n;i++) scanf("%lld",a+i);
	sort(a+1,a+n+1);
	sum[1]=a[1];
	for(LL i=2;i<=n;i++) sum[i]=sum[i-1]+a[i];
	printf("%lld",Upper(1,5E5+1));
	return 0;
}
