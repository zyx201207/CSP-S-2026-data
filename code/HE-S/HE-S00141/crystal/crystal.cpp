#include<bits/stdc++.h>
#define ll long long
using namespace std;//Oct31==Dec25?
const int N=5e5+5;
ll n,m,a[N],s[N];
inline bool check(ll mid) {
	ll minn=LLONG_MAX;
	for(int i=mid; i<=n; i++) {
		minn=min(minn,1LL*(mid*a[i])-1LL*(s[i]-s[i-mid]));
		if(minn<=m) return 1;
	}
	return 0;
}
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1; i<=n; i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1; i<=n; i++) s[i]=s[i-1]+a[i];
	ll l=0,r=n;
	while(l<r) {
		ll mid=(l+r+1)>>1;
		if(check(mid)) l=mid;
		else r=mid-1;
	}
	cout<<l;
	return 0;
}


