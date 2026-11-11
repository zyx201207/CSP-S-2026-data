#include<bits/stdc++.h>
using namespace std;
long long n,m,ans,cnt=0;
long long a[214514];
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(long long i=1;i<=n;i++) {
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(long long i=n;i>=m;i--) {
		ans=a[i];
		for(long long j=i-1;j>=i-m+1;j--) {
			ans=ans&a[j];
		}
		if(ans>cnt) {
			cnt=ans;
		}
	}
	printf("%lld",cnt);
	return 0;
}
