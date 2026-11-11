#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5e5 + 10;
ll n, m;
ll a[N];
ll diff[N];

ll tr[N];

inline ll lowbit(ll x) {
	return x & (-x);
}
void update(ll x, ll k) {
	for(; x <= n;x += lowbit(x)) {
		tr[x] += k;
	}
}
ll query(ll x) {
	ll ret = 0;
	for(; x > 0; x -= lowbit(x)) {
		ret += tr[x];
	}
	return ret;
}
ll query(ll l, ll r) {
	return query(r) - query(l - 1);
}
bool check(ll idx) {
	ll now_use = 0;
	for(int i = 1;i <= idx;i++) {
		now_use += (a[idx] - a[i]);
	}
	return now_use <= m;
}
ll calc(ll idx) {
	ll now_use = 0;
	for(int i = idx - 1;i >= 1;i--) {
		now_use += (a[idx] - a[i]);
		if(now_use > m) {
			return idx - i;
		}
	}
	return idx;
}
int search(int idx, int target) {
	int l = 1, r = idx;
	while(l < r) {
		int mid = (l + r + 1) >> 1;
		if(query(mid, idx) - (idx - mid + 1) * diff[idx + 1] > target) {
			l = mid;
		}
		else {
			r = mid - 1;
		}
	}return l;
}

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) {
		cin >> a[i];
	} 
	sort(a + 1, a + n + 1);
	if(n <= 5000) {
		ll ans = 0;
		for(int i = 1;i <= n;i++) {
			ans = max(ans, calc(i));
		}
		cout << ans;
		return 0;
	}
	for(int i = 1;i <= n;i++) {
		diff[i] = a[i] - a[i - 1];
	}
	for(int i = n; i >= 1;i--) {
		diff[i] += diff[i + 1];
	}
	for(int i= 1; i <= n;i++) {
		update(i, diff[i]);
	}
	ll ans = 1;
	for(int i = 1;i <= n;i++) {
		ll pos = search(i, diff[i] + m) + 1;
		ans = max(ans, i - pos + 2);
	}
	cout << ans;
	return 0;
} 
