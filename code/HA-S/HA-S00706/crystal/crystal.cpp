#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500010],l=1e18,r=-1e18,mid,ans=-1,bj;
long long c(long long bj) {
	long long s=m,sum=0;
	for (int i=1;i<=n;i++) {
		if (bj>=a[i]&&s-(long long)(bj-a[i])>=0) {
			s-=(bj-a[i]);
			sum++;
		}
	}
	return sum;
}
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for (int i=1;i<=n;i++) {
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	l=1,r=n;
	while (l<=r) {
		mid=(l+r)/2;
		if (c(a[mid])<=ans) {
			r=mid-1;
		}
		else {
			ans=c(a[mid]);
			l=mid+1;
		}
	}
	cout<<ans;
	return 0;
}
