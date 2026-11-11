#include <bits/stdc++.h>
#define ll long long
#define IOS cin.tie(0)->ios::sync_with_stdio(0);
using namespace std;
const int N=5e5+5;
int n,ans;
ll a[N],dif[N],m;
bool check(int x) {
	ll t=0,res=0;
	for(int i=1;i<x;++i) t+=a[x]-a[i];
	res=t;
	for(int i=x;i<=n;++i) {
		t+=x*a[i]-(x+1)*a[i-1]+a[i-x+1];
		res=min(res,t);
	}
	return res<=m;
}
void solve() {
	int l=1,r=n;
	while(l<=r) {
		int mid=l+((r-l)>>1);
		if(check(mid)) l=mid+1,ans=mid;
		else r=mid-1;
	}
}
signed main() {
	IOS
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;++i) cin >> a[i];
	sort(a+1,a+n+1);
	solve();
	cout << ans;
	return 0;
}
