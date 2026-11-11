#include <bits/stdc++.h>

using namespace std;

#define int long long
const int N = 5e5 + 114 + 514;
int a[N], cnt, ans, n, m;
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	if(n == 1) {
		cout << 1;
		return 0;
	} 
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	int l = 1;
	for(int i = 2; i <= n; i++) {
		cnt += (i - l) * (a[i] - a[i - 1]);
		while(cnt > m) {
			cnt -= (a[i] - a[l]);
			l++;
		}
		ans = max(ans, i - l + 1);
	}
	cout << ans;
	
	return 0;
} 
