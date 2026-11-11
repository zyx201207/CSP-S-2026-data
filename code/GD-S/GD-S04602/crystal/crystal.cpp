#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3fLL;
ll n,m,a[N],ts[N],sum[N];

ll bnry_srch(ll now) {
	ll l = 1, r = now,ans = 1;
	while (l <= r) {
		ll mid = (l + r) >> 1;
		if (a[now] * (now - mid) - sum[now - 1] + sum[mid - 1] <= m) {
			r = mid - 1;
			ans = (now - mid + 1);
		}else l = mid + 1;
	}
	return ans;
}

int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++) cin >> a[i];
	sort(a + 1,a + n + 1); 
	
	for(int i = 1; i <= n; i ++) {
		sum[i] = sum[i - 1] + a[i];
		ts[i] = ts[i - 1] + sum[i];
	}
	ll ans = 1,x;
	for(int i = 1; i <= n; i ++) {
		x = bnry_srch(i);
		ans = max(ans,x);
	}
	cout << ans;
	return 0;
}
