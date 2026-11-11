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
int n, m, a[MAXN], b[MAXN];
int id[MAXN];
bool cmp(int x, int y) {
	if (b[x] == b[y]) return a[x] > a[y];
	return b[x] > b[y];
}
signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
//	freopen("and.in", "r", stdin);
//	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i], id[i] = i;
	bool flg = 0;
	for (int i = 31; i >= 0; i--) {
		int res = 0;
		for (int j = 1; j <= n; j++) {
			b[j] = (a[j] >> i) & 1;
			res += (b[j] == 1);
		}
		if (res < m) continue;
		sort(id + 1, id + n + 1, cmp);
		int ans = a[id[1]];
		for (int i = 2; i <= m; i++) ans &= a[id[i]];
		cout << ans;
		flg = 1;
		break;
	}
	if (!flg) cout << 0;
	return 0;
}
/*

*/

