#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,m,a[500005],s[500005],l=1,r=500000,mid;
bool check(LL x) {
	for(LL i=1;i<=n-x+1;++i)
		if(a[i+x-1]*x-s[i+x-1]+s[i-1]<=m) return true;
	return false;
}
int main(void) {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(LL i=1;i<=n;++i) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(LL i=1;i<=n;++i) s[i]=s[i-1]+a[i];
	while(l<r) {
		mid=(l+r+1)/2;
		if(check(mid)) l=mid;
		else r=mid-1;
	}
	printf("%lld",l);
	return 0;
}
