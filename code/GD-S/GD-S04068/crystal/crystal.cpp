#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5+10;
void file() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
}
ll n,m,a[N];
bool check(ll x) {
	ll cnt=0, ret=0x3f3f3f3f3f3f3f3f;
	//printf("[Debug] x=%lld {\n",x);
	for(ll i=1;i<=n;i++) { // majorNumber
		cnt += (a[i]-a[i-1])*min(x,i-1);
		if(i>x) cnt -= (a[i]-a[i-x]);
		if(i>=x) ret = min(ret,cnt);
		//printf("cnt[%lld] = %lld\n",i,cnt);
	}
	//if(ret<=m) cout << "Good!\n";
	//cout << "}\n";
	return (ret<=m);
}
void solve() {
	cin >> n >> m;
	for(ll i=1;i<=n;i++) cin >> a[i];
	sort(a+1,a+1+n);
	ll l=1,r=n,ans=1;
	while(l<=r) {
		ll mid = (l+r)/2;
		if(check(mid)) (l = mid+1, ans = mid);
		else            r = mid-1;
	}
	cout << ans << '\n';
}
int main() {
	file();
	int t=1;
	// cin >> t;
	while(t--) solve();
}
