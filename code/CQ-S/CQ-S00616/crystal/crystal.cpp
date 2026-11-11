#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
typedef long long ll;
int n;
ll a[N];
ll m;
ll pr[N];

bool check(int x) {
	for (int i = x; i <= n; i++) {
		ll sum = pr[i] - pr[i - x], sum1 = a[i] * x;
		if(sum1 - sum <= m) return true;
	}
	return false;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
//	freopen("crystal4.in", "r", stdin);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++) pr[i] = pr[i - 1] + a[i]; 
	int l = 1, r = n, ans = 0;
	while(l <= r) {
		int mid = (l + r) >> 1;
		if(check(mid)) {
			ans = mid;
			l = mid + 1;
		}else r = mid - 1;
	}
	cout << ans;
}
/*
二分?
毕竟最终选的水晶数量小于他的在<=m此也能做到
那么,该如何写check呢
我们只有最多O(nlongn)的时间复杂度去判断
首先，肯定要排序吧 
欧克,check很简单
只需要有个前缀和就行了 
*/
