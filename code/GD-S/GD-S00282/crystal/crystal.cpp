#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 10;
int n, m, a[N], s[N], d[N], l, r, mid, ans;
bool check(int mid){
	int cnt = 0;
	for(int i = 2;i <= mid;i ++) cnt += d[i] * (i - 1);
	if(cnt <= m) return 1;
	for(int i = mid + 1;i <= n;i ++){
		cnt = cnt - (s[i - 1] - s[i - mid]) + (mid - 1) * d[i];
		if(cnt <= m) return 1;
	}
	return 0;
}
signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i ++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for(int i = 1;i <= n;i ++) d[i] = a[i] - a[i - 1];
	for(int i = 2;i <= n;i ++) s[i] = s[i - 1] + d[i];
	l = 1;r = n;
	while(l <= r){
		mid = l + r >> 1;
		if(check(mid)) l = mid + 1, ans = mid;
		else r = mid - 1;
	}
	cout << ans;
	return 0;
}
