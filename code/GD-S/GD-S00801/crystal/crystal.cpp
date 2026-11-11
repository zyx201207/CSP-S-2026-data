#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5+5;
ll n, m, ans;
ll a[N], sum[N];
ll find(ll x) {
	ll l=1, r=x, ans=x;
	while(l<=r) {
		ll mid=(l+r)>>1;
		if(a[x]*(x-mid+1)-(sum[x]-sum[mid-1])<=m) {
			ans=mid;
			r=mid-1;
		} 
		else {
			l=mid+1;
		}
	}
	return ans;
}
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld", &n, &m);
	for(int i=1;i<=n;i++) {
		scanf("%lld", &a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) {
		sum[i]=sum[i-1]+a[i];
	}
	for(ll i=1;i<=n;i++) {
		ll pos=find(i);
		ans=max(ans,i-pos+1);
	} 
	printf("%lld", ans);
	return 0;
} 
