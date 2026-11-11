#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int N = 5e5 + 10;

int n, m;
int a[N];

bool check(int len) {
	int cnt = 0;
	for (int i = 1; i < len; i++) 
		cnt += a[len] - a[i];
	if(cnt <= m) return true;
	for (int i = len + 1; i <= n; i ++) {
		cnt -= a[i] - a[i - len];
		int dis = a[i] - a[i - 1];
		cnt += (len - 1) * dis;
		if(cnt <= m) return true;
	}
	return false;
} 

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0),	cout.tie(0);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++) 
		cin >> a[i];
	sort(a + 1, a + n + 1);
	
	int l = 1, r = n, ans;
	while (l <= r) {
		int mid = (l + r) / 2;
		if(check(mid)) {
			ans = mid;
			l = mid + 1;
		} 
		else r = mid - 1;
	}
	cout << ans;
}
