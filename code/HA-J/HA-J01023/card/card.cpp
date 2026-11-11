#include <bits/stdc++.h>
using namespace std;
const int N = 200005, M = 100005;
int n, m, a[N], ans[M];
bool noww[M] = {0};
stack<int> st;
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = n; i >= 1; i--) cin >> a[i];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) noww[j] = 0;
		for (int j = 1; j <= i; j++) {
			if (noww[a[j]] == 0) {
				noww[a[j]] = 1;
				st.push(a[j]);
			} else  while(st.top() != a[j]) st.pop();
		}
		while (!st.empty()) {
			ans[st.top()]++;
			st.pop();
		}
	}
	for (int i = 1; i <= m; i++) cout << ans[i] << " "; 
	return 0;
}
