#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 5, inf = 1e18;
int n, m, a[N], sum[N], ans;
int qry(int l, int r){
	return sum[r] - sum[l - 1];
}
signed main(){
	cin.tie(0)->sync_with_stdio(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i){
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; ++i){
		sum[i] = sum[i - 1] + a[i];
	}
	a[n + 1] = inf;
	int l = 1;
	for (int i = 1; i <= n; ++i){
		if (a[i] == a[i + 1])continue;
		while (l < i && (i - l + 1) * a[i] - qry(l, i) > m){
			++l;
		}
		ans = max(ans, i - l + 1);
	}
	cout << ans;
	return 0;
}
/*
不是你们这个鼠标右键咋还是坏的。
上午都是。这是人类吗。
中键也是坏的/xk/xk/xk 
14：38
*/
