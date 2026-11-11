#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005],qz[500005],ans;
bool check(int x) {
	for(int i=x; i<=n; i++) {
		if(a[i]*(x-1)-qz[i-1]+qz[i-x]<=m) return 1;
	}
	return 0;
}
signed main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for(int i=1; i<=n; i++) {
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1; i<=n; i++) {
		qz[i]=qz[i-1]+a[i];
	}
	int l=1,r=n;
	while(l<=r) {
		int mid=(l+r)/2;
		if(check(mid)) ans=mid,l=mid+1;
		else r=mid-1;
	}
	cout << ans;
	return 0;
}
