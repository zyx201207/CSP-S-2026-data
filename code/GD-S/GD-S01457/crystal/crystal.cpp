#include<bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10;
typedef long long LL;
LL a[N], sum[N];

int main () {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n; LL m;
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	sum[0] = 0;
	for (int i = 1; i <= n; i ++) {
		sum[i] = sum[i - 1] + a[i];
	}
	
	LL ans = 0;
	LL l = 1;
	for (LL i = 1; i <= n; i ++) {
		LL tmp = a[i] * (i - l + 1) - (sum[i] - sum[l - 1]);
		while (tmp > m && l < i) {
			l ++;
			tmp = a[i] * (i - l + 1) - (sum[i] - sum[l - 1]);
		} 
		if (tmp <= m) ans = max(ans, i - l + 1);
	}
	cout << ans << "\n";
	
	
	return 0;
}
