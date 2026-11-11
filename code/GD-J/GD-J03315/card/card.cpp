#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	vector<int> a(n), cnt(m + 1);
	for (auto &x : a) cin >> x;
	for (int r = 0; r < n; r++) {
		stack<int> st;
		vector<bool> vis(n, false);
		for (int i = r; i < n; i++) {
			if (vis[a[i]]) {
				while (st.top() != a[i]) {
					vis[st.top()] = false;
					st.pop();
				} continue;
			} st.push(a[i]);
			vis[a[i]] = true;
		} while (!st.empty()) {
			int i = st.top();
			st.pop();
			cnt[i]++;
		}
	} for (int i = 1; i <= m; i++) cout << cnt[i] << " ";
}
