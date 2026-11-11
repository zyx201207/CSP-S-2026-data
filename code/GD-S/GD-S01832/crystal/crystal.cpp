#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
int n;
ll a[N],m;
ll s[N];
int check(int len) {
	for (int i=1;i<=n-len+1;i++) {
		int j=i+len-1;
		ll sum=s[j]-s[i-1];
		ll k=a[j]*len-sum;
		if (k<=m) {
			return 1;
		}
	}
	return 0;
}
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d %lld",&n,&m);
	for (int i=1;i<=n;i++) {
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	for (int i=1;i<=n;i++) {
		s[i]=s[i-1]+a[i];
	}
	int l=1,r=n,ans=0;
	while (l<=r) {
		int mid=(l+r)>>1;
		if (check(mid)) {
			ans=max(ans,mid);
			l=mid+1;
		}else {
			r=mid-1;
		}
	}
	printf("%d",ans);
	return 0;
}
