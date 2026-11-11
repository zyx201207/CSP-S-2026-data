//From: CSP-S
//Problem: T1能量水晶（crystal） 
//文件名: crystal.in/.out/.cpp
//时间限制: 1000 ms
//空间限制: 1024 MiB 
//预期得分: 100 pts 
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
constexpr int N = 5e5 + 10;

int n;
ll m;
ll a[N], sum[N];//前缀和 

bool check(int x) {
	for (int i = 1; i <= n - x + 1; i ++) {
		int j = i + x - 1;
		ll spend = sum[j] - sum[i - 1];//原来有的水晶能量值
		ll should = x * a[j];
		if (should - spend <= m) return true; 
	}
	return false;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) cin >> a[i];
	sort(a + 1, a + n + 1);//先对它进行排序
	for (int i = 1; i <= n; i ++) sum[i] = sum[i - 1] + a[i];
	int l = 1, r = n, ans = 0;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (check(mid)) l = mid + 1, ans = mid;
		else r = mid - 1;
	}
	cout << ans;
	return 0;
}
