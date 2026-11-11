/*
欢迎关注洛谷 kaikai_qwq(uid = 1106246) qwq

- 空间炸了 / 小了吗？
- 边界特判了吗？
-  多测清空了吗？
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 2e5 + 10;
int n;
int a[MAXN];
char c[MAXN];
signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
//	freopen("string.in", "r", stdin);
//	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i] >> c[i];
	int l = 1, r = n;
	int ans = 0;
	while (l <= r) {
		if (c[l] == c[r]) {
			if (a[l] < a[r]) a[r] -= a[l], l++;
			else if (a[l] > a[r]) a[l] -= a[r], r--;
			else l++, r--;
		} else {
			ans += min(a[l], a[r]);
			if (a[l] == a[r]) l++, r--;
			else if (a[l] > a[r]) a[l] -= a[r], r--;
			else a[r] -= a[l], l++;
		}
	}
	cout << ans;
	return 0;
}
/*

*/

