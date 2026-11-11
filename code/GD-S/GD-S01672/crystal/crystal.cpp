#include <bits/stdc++.h>
#define fi first
#define se second
#define int long long
using namespace std; 
const int maxn = 5e5 + 5, inf = 1e18;
int n, m, a[maxn], sum[maxn];
inline int calc(int l, int r, int x) {
	if (a[r] > x) return inf;
	return (r - l + 1) * x - (sum[r] - sum[l - 1]);
}
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0),
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
	int l = 1, ans = 1;
	for (int r = 2; r <= n; r++) {
		while (l <= r && calc(l, r, a[r]) > m) l++;
		ans = max(ans, r - l + 1);
	}
	cout << ans << '\n';
	return 0;
}
/*
给你 n 个数，至多给指定数字增加 m
求最后最多得到多少相同的数字
从小到大贪心即可 
但还是不优，会存在前面一段空掉的可能 
为了让迷惑行为看到我，所以我留下来这个：
froepen()
关注 luogu 的 dvsfanjo 谢谢 
人活着就是为了黑部奈叶香
*/
