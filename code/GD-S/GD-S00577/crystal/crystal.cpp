#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, m, a[500050], s[500050], now=0, ans=1;
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}a[0]=0;
	sort(a+1, a+n+1);
	for(int i=1; i<n; i++) {
		s[i]=a[i+1]-a[i];
	}
	for(int l=1, r=1; r<=n; r++) {
		now+=(r-l+1)*s[r];
		while(now>m) {
			now-=(a[r+1]-a[l]);
			l++;
		}ans=max(ans, r-l+2);
		//cout<<l<<" "<<r<<"\n";
	}
	cout<<ans;
	return 0;
}

