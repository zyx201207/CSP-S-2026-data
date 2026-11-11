#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int W = 5e5 + 5, M = 3e5 + 5;
stack<int> st;
int n, m;
int a[W], ans[M], vis[M];
int main() {
	freopen ("card.in", "r", stdin);
	freopen ("card.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) {
		fill(vis + 1, vis + m + 1, 0);
		for (int j = i; j <= n; j++) {
			if (!vis[a[j]]) {
				vis[a[j]] = 1;
				st.push(a[j]);
			} else {
				while (!st.empty() && st.top() != a[j]) {
					vis[st.top()] = 0;
					st.pop();
				}
			}
		}
		while (!st.empty()) {
			ans[st.top()]++;
			st.pop();
		}
	}
	for (int i = 1; i <= m; i++) cout << ans[i] << ' '; 
	return 0;
} 
