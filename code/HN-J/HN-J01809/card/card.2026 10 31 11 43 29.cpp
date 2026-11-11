#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
using namespace std;
const int N = 5e5 + 5;
int n, m, x;
int a[N], b[N], buk[N], ans[N];
struct Stuck {
	int a[5005];
	int cnt;
	inline void init() {
		cnt = 0;
		memset(a, 0, sizeof a);
	}
	inline void push(int x) {
		a[++ cnt] = x;
	}
	inline void pop(int x) {
		cnt --;
	}
	inline int top() {
		return a[cnt];
	}
} stk[3005];
void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
		b[i] = a[i];
	}
	for (int k = 1; k <= n; k ++) {
		for (int i = 1; i <= m; i ++) {
			stk[i].init();
			buk[i] = 0;
		}
		for (int i = k; i <= n; i ++) {
			buk[a[i]] ++;
			ans[i] ++;
			if (buk[a[i]] & 1 == 0) {
				while (stk.top() != a[i]) {
					stk.pop();
				}
				ans[i] --;
			} 
			stk.push(a[i]);
		}
	}
	for (int i = 1; i <= n; i ++) {
		cout << ans[i] << " ";
	}
}
signed main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin.tie(0) -> sync_with_stdio(0);
	int t = 1;
//	cin >> t;
	while (t --) {
		solve();
	}
	return 0;
}

