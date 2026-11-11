#include <bits/stdc++.h>
using namespace std;
const int MAX = 5e5 + 10;
int n, m, a[MAX], ans[MAX];
bool vis[MAX];
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		stack<int> st;
		memset(vis, false, sizeof(vis));
		for (int j = i; j <= n; j++) {
			if (vis[a[j]]) {
				while (st.top() != a[j]) {
					vis[st.top()] = false;
					st.pop();
				}
			}
			else {
				st.push(a[j]);
				vis[a[j]] = true;
			}
		}
		while (!st.empty()) {
			ans[st.top()]++;
			st.pop();
		}
	}
	for (int i = 1; i <= m; i++) {
		cout << ans[i] << ' ';
	}
	return 0;
}
