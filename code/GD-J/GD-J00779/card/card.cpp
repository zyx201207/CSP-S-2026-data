#include<bits/stdc++.h>
#define int long long
#define vec vector
#define f(i, l, r) for (int (i) = (l); (i) <= (r); (i) ++)
using namespace std;
signed main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	vec<int> a(n + 1), ans(m + 1, 0);
	f(i, 1, n) cin >> a[i];
//	stack<int> st;
//	vec<bool> to(m + 1, 0);
//	f(k, 1, n) {
//		to.resize(m + 1, 0);
//		f(i, k, n) {
//			if (to[a[i]]) {
//				while (st.top() != a[i]) {
//					st.pop();
//				}
//			} else {
//				to[a[i]] = 1;
//				st.push(a[i]);
//			}
//		}
//		while (!st.empty()) {
//			ans[st.top()] ++;
//			st.pop();
//		}
//	}
//	f(i, 1, m) cout << ans[i] << ' ';
	f(i, 2, n) {
		if (a[i] != a[i - 1]) cout << i - 1 << ' ';
	}
	cout << n;
	return 0;
}

