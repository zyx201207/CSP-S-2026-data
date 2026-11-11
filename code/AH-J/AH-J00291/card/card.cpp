#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 7, MAXM = 3e5 + 7;
int n, m;
int a[MAXN], ans[MAXM];
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++) {
		map<int, bool> h;
		stack<int> st;
		for (int j = i; j <= n; j++) {
			if (h.count(a[j])) {
				while (!st.empty()) {
					if (st.top() == a[j]) break;
					h.erase(st.top());
					st.pop();
				}
			} else {
				st.push(a[j]); h[a[j]] = 1;
			}
		}
		while (!st.empty()) {
			ans[st.top()]++;
			st.pop();
		}
	}
	for (int i = 1; i <= m; i++) printf("%d ", ans[i]);
}
