#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll n,r,m,a[500005],ans;
map<ll,ll> mp;
signed main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> r >> m;
	for(int i=1; i<=r; i++) {
		ll x;
		cin >> x;
		if(!mp[x]) a[++n]=x;
		mp[x]++;
	}
	sort(a+1,a+n+1);
	for(int i=1; i<=n; i++) {
		ll sum=0,cnt=0;
		for(int j=i-1; j>=1; j--) {
			sum+=(a[i]-a[j])*mp[a[j]];
			if(sum>m) {
				sum-=(a[i]-a[j])*mp[a[j]];
				cnt+=(m-sum)/(a[i]-a[j]);
				break;
			}
			cnt+=mp[a[j]];
		}
		cnt+=mp[a[i]];
		ans=max(ans,cnt);
	}
	cout << ans;
	return 0;
}
