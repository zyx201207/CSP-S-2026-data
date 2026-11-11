#include <bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
	int x = 0,f = 1; char c = getchar();
	while(c < '0' || c > '9')  {
		if(c == '-') f = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9') {
		x = (x << 3) + (x << 1) + (c - '0');
		c = getchar();
	}
	return x * f;
}
void solve() {
	int n = read(), m = read(); vector <int> a(n + 10), pre(n + 10);
	for(int i = 1;i <= n;i++) a[i] = read(); 
	sort(a.begin() + 1, a.begin() + n + 1);
	for(int i = 1;i <= n;i++) pre[i] = pre[i - 1] + a[i];
	int ans = 1;
	for(int i = 1;i <= n;i++) {
		int l = 1, r = i, res = i;
		while(l <= r) {
			int mid = (l + r) >> 1;
			if(a[i] * (i + 1 - mid) + pre[mid - 1] - pre[i] <= m) res = mid, r = mid - 1;
			else l = mid + 1;
		}
		ans = max(ans, i - res + 1);
	}
	cout << ans << "\n"; 
}
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int t = 1;
//	t = read();
	while(t--) solve();
}

