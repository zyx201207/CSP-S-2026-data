#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5;
long long n,m,a[MAXN+10],pre[MAXN+10];
bool check(long long l,long long r) {
	return (a[r]*(r-l+1))-(pre[r]-pre[l-1])<=m;
}
int main(void) {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(long long i=1; i<=n; i++) {
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	pre[0]=0;
	for(long long i=1; i<=n; i++) {
		pre[i]=pre[i-1]+a[i];
	}
	long long ans=0;
	for(long long i=1; i<=n; i++) {
		long long l=1,r=i,res=i;
		while(l<=r) {
			long long mid=(l+r)>>1;
			if(check(mid,i)) {
				r=mid-1;
				res=mid;
			} else {
				l=mid+1;
			}
		}
		ans=max(ans,i-res+1);
	}
	printf("%lld",ans);
	return 0;
}
