#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 5e5+10;
int cnt[N], C[N];
LL sum[N], a[N];
vector<LL> v;
int n, ans = 1, c = 1;
LL m;
bool check(LL x) {
	return x <= m;
}
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a+1, a+n+1);
	cnt[1] = 1;
	for (int i = 2; i <= n; i++) {
		if (a[i] == a[i-1]) cnt[c]++;
		else {
			c++;
			cnt[c] = 1;
		}
	}
	v.push_back(0);
	for (int i = 1; i <= n; i++) v.push_back(a[i]);
	auto it = unique(v.begin(), v.end());
	v.erase(it, v.end());
	for (int i = 1; i <= c; i++) {
		sum[i] = sum[i-1] + cnt[i]*v[i];
		C[i] = C[i-1]+cnt[i];
	}
	for (int i = 1; i <= v.size(); i++) {
		int l = 1, r = i - 1;
		int t;
		while (l <= r) {
			int mid = (l+r) >> 1;
			LL x = v[i]*i-(sum[i]-sum[mid-1]);
			if (check(x)) {
				r = mid-1;
			} else {
				l = mid+1;
			}
			t = mid;
		}
		LL x = m-(v[i]*i-(sum[i]-sum[t-1]));
		int y = C[i] - C[t-1];
		for (int j = t-1; j >= 0; j--) {
			if (x >= cnt[j] * (v[i]-v[j])) {
				y += cnt[j];
				x -= 1ll * cnt[j] * (v[i]-v[j]);
			} else if (x >= v[i]-v[j]){
				int z = x / (v[i]-v[j]);
				y += z;
				x -= z * (v[i]-v[j]);
			} else break;
		}
		ans = max(ans, y);
	}
	cout << ans;
	return 0;
} 
