#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5 + 5;

int n;
ll m, a[N], sum[N];

int bs(int ind){
	int l = 1, r = ind, ans = 0;
	while (l <= r){
		int mid = (l + r) >> 1;
		if (1ll * a[ind] * (ind - mid + 1) - 1ll * (sum[ind] - sum[mid - 1]) <= m){
			r = mid - 1;
			ans = max(ans, ind - mid + 1);
		}else l = mid + 1;
	}
	return ans;
}

void solve(){
	cin >> n >> m;
	for (int i = 1;i <= n;i ++) sum[i] = 0;
	for (int i = 1;i <= n;i ++){
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1;i <= n;i ++){
		sum[i] = sum[i - 1] + a[i];
	}
	ll cnt = 0, ans = 1;
	for (int i = 2;i <= n;i ++){
		ans = max(ans, 1ll * bs(i));
	}
	cout << ans << "\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int t = 1;
	// cin >> t;
	while (t --){
		solve();
	}
	return 0;
}
/*
5 8
-3 -1 2 2 7
*/
