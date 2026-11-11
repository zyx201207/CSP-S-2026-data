#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> Pii;

const int N = 5e5;
int n, ans;
LL m;
LL a[N+5], sum[N+5];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1, j = 1; i <= n; i++) {
		sum[i] = sum[i-1] + a[i];
		for (; j <= i && a[i] * (i-j+1) - sum[i] + sum[j-1] > m; j++);
		ans = max(ans, i-j+1);
	}
	cout << ans;
	return 0;
}
/*
找到最多的数，每个取最大值与其的差，它们的和小于等于 m。（转化了一步，是不断加一使得它们与最大值相等）
排序取区间，发现存在单调性，变成双指针。f(l, r) = a[r] * (r-l+1) - (sum[r] - sum[l-1])
总和小于等于 1e18。
时间快了 5min，需要注意。
*/
