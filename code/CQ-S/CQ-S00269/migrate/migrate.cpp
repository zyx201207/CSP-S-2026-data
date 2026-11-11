#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll c,t,n,d,a[2000005];

int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >>c>>t;
	while(t--) {
		cin >>n>>d;
		if(n<=3) {
			cout <<0<<"\n";
			continue;
		}
		ll ans=0;
		for(ll i=1;i<=n;i++) cin >>a[i];
		sort(a+1,a+n+1);
		for(ll i=1;i<=n-3;i++) {
			if(a[i+3]-a[i]<=d) continue;
			if(a[i+1]-a[i]<=d&&a[i+2]-a[i]<=d&&a[i+3]-a[i+1]<=d&&a[i+3]-a[i+2]<=d) ans++;
		}
		cout <<ans<<"\n";
	}
	return 0;
}
