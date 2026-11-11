#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long a[N],b[N];
long long n,m,ret=0;
bool check(long long x) {
	if(x>n) return false;
	for(long long i=x;i<=n;i++) {
		long long ant=x*a[i]-(b[i]-b[i-x]);
		if(ant<=m) return true;
	}
	return false;
}
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(long long i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++)
		b[i]=b[i-1]+a[i];
	long long l=-1e18,r=1e18;
	while(l<=r) {
		long long mid=(l+r)/2;
		if(check(mid)) {
			ret=max(ret,mid);
			l=mid+1;
		} else {
			r=mid-1;
		}
	}
	printf("%lld",ret);
	return 0;
}
