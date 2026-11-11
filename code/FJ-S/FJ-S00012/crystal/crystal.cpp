#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 10;
int n, m, a[N], k[N];
int read() {
	int x = 0, f = 1;
	char c = getchar();
	while(c < '0' || c > '9') {
		if(c == '-') f = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9') {
		x = (x << 1) + (x << 3) + (c - '0');
		c = getchar(); 
	}
	return x * f;
}
bool check(int x) {
	for(int i = 1; i + x - 1 <= n; i++) {
		int j = i + x - 1, cnt = 0;
		for(int k = i; k <= j; k++) {
			cnt += (a[j] - a[k]);
		}
		if(cnt <= m) return true;
	}
	return false;
}
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0); 
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i]; 
		if(i > 1) k[i] = a[i] - a[i - 1];
	}
	sort(a + 1, a + n + 1);
	if(a[1] == a[n]) {
		cout << n << '\n';
		return 0;
	}
	sort(k + 2, k + n + 1);
	if(k[2] == k[n]) {
		int t = m / k[n];
		int e = 1, cnt = 0;
		while(t >= e) {
			t -= e; cnt++, e++;
		}
		cout << cnt << '\n';
		return 0;
	}
	int l = 1, r = n, ans;
	while(l < r) {
		int mid = (l + r) / 2;
		if(check(mid)) {
			l = mid + 1, ans = mid;
		}else r = mid;
	}
	cout << ans << '\n';
	return 0;
}
