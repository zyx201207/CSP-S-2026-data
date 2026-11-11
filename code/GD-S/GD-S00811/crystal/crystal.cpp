#include <bits/stdc++.h>
#define ll long long

using namespace std;

int n, m, ans;
ll a[500005], sum[500005];

bool check(int len) {
	bool flag = false;
	for(int i = 1; i + len - 1 <= n; i++) {
		int j = i + len - 1;
		ll cnt = 1ll * a[j] * (len - 1);
		if(cnt - (sum[j - 1] - sum[i - 1]) <= m) {
			flag = true;
			break;
		}
	}
	return flag;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
	int l = 1, r = n;
	while(l <= r) {
		int mid = (l + r) / 2;
		if(check(mid)) {
			l = mid + 1;
			ans = mid;
		} else r = mid - 1;
	}
	cout << ans << '\n';
	
	return 0;
} 
