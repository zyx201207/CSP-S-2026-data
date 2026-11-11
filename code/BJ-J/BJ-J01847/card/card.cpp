/**
 * @file CSP-J 2026
 *       Problem D. card
 * @author BJ-J01847
 *         LG-1014842 liuli688
 * @date 2026/10/31
*/

// We exists in cyberspace...
// +ERABY+E CONNEC+10N - Camellia

// password: Trick||Treat!

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 10;
int n, m, a[N], q[N], lst[N], nxt[N], ans[N];

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		cin >> a[i], q[i] = 1;
	for (int i = n; i; --i) {
		nxt[i] = (lst[a[i]] ? lst[a[i]] : i) + 1;
		lst[a[i]] = lst[a[i]] ? lst[a[i]] : i;
	}
	for (int i = 1; i <= n; ++i) {
		ans[a[i]] += q[i];
		q[nxt[i]] += q[i];
	}
	for (int i = 1; i <= m; ++i)
		cout << ans[i] << " \n"[i == m];
	return 0;
}

//10:24

/**
 * 也是有幸 AK 了喵，至少在现在
 * 开心开心
 * 希望大家都能成为自己想要的样子，实现自己的梦想喵
 * 我怎么没有 NGOI!! /ll
 * 1099
*/