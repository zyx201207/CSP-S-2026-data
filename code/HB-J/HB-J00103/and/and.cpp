#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 10;

int n, m, maxlog;
int a[MAXN]; 
int lst[MAXN], nxt[MAXN], head, tail, cnt, ans;

int main() {
	freopen("and5.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		int nwlog = log2(a[i]);
		maxlog = max(maxlog, nwlog);
		lst[i] = i - 1; nxt[i] = i + 1;
	}
	nxt[0] = 1, lst[n + 1] = n;
	head = 0, tail = n + 1, cnt = n;
	for (int i = maxlog; i >= 0; --i) {
		int nwCnt = 0;
		for (int j = nxt[head]; j != tail; j = nxt[j]) {
			if (!(a[j] & (1 << i))) {
				++nwCnt;
			}
		}
		if (cnt - nwCnt < m)
			continue;
		cnt -= nwCnt;
		for (int j = nxt[head]; j != tail; j = nxt[j]) {
			if (!(a[j] & (1 << i))) {
				nxt[lst[j]] = nxt[j];
				lst[nxt[j]] = lst[j];
			}
		}
		if (i == 0) {
			if (cnt > m)
				break;
		}
		ans += (1 << i);
	}
	cout << ans;
	return 0;
}