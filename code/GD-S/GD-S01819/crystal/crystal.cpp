#include <bits/stdc++.h>
typedef long long ll;
int n;
ll m,a[500010];
bool chk(ll x) {
	for(int i=x;i<=n;i++) {
		ll now=a[i]-a[i-x];
		ll tag=(a[i]-a[i-1])*x;
		if(tag-now<=m) return true;
	}
	return false;
}
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::cin>>n>>m;
	for(int i=1;i<=n;i++)
		std::cin>>a[i];
	std::sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
		a[i]+=a[i-1];
	ll l=1,r=n;
	while(l<r) {
		ll mid=(l+r+1)>>1;
		if(chk(mid)) l=mid;
		else r=mid-1;
	}
	std::cout<<r;
	return 0;
} 
