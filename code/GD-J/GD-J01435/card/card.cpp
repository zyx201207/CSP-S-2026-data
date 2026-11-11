#include <bits/stdc++.h>
using namespace std;
int a[500005];
int ans[300005];
bool vis[300005];
stack<int> st;
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = i; j <= n; ++j) {
			if (vis[a[j]]) {
				while(st.top() != a[j]){
					vis[st.top()] = false;
					st.pop();
				}
			} else {
				vis[a[j]] = true;
				st.push(a[j]);
			}
		}
		while(st.size()) {
			++ans[st.top()];
			vis[st.top()] = false;
			st.pop();
		}
	}
	for (int i = 1; i <= m; ++i) {
		cout << ans[i] << ' ';
	}
	cout << endl;
}
