#include <bits/stdc++.h>
#define ll long long
using namespace std;
constexpr ll N = 2e5+5;
ll a[N];
char c[N];
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll n;
	cin >> n;
	for (ll i = 1; i <= n; ++i) cin >> a[i] >> c[i];
	ll ans = 0;
	ll l = 1,r = n;
	ll ldel = 0,rdel = 0;
	
//	cout << "l\tr\tldel\trdel\tans\n";
	
	while (l <= r) {
		if (l == r) break;
		
		ll llast = a[l] - ldel;
		ll rlast = a[r] - rdel;
		ll minlast = min(llast,rlast);
		
		if (c[l] != c[r]) ans += minlast;
		llast -= minlast;
		rlast -= minlast;
		
		if (llast == 0) ++l,ldel = 0;
		else ldel = a[l] - llast;
		if (rlast == 0) --r,rdel = 0;
		else rdel = a[r] - rlast;
		
//		cout << l << "\t" << r << "\t" << ldel << "\t" << rdel << "\t" << ans << endl;
	}
	cout << ans << endl;
	return 0;
}
