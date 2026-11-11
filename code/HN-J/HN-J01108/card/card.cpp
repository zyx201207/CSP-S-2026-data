#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m, a[500500], ans[500500];
int t[500500];
signed main() {
	freopen("card.in" , "r", stdin );
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(NULL);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	cin >> a[1];
	for (int i = 2; i <= n; i++) {
		cin >> a[i];
	}
	int js = 1;
	
	while (js <= n) {
		for (int i = 0; i <= m; i++) {
			t[i] = 0;
		}
		stack<int> st;
		st.push(a[js]);
		t[a[js]] = 1;
		for (int i = js + 1; i <= n; i++) {
			if (t[a[i]] == 1) {
				while (true) {
					if (st.top() != a[i]) {
						st.pop();
					} 
					else {
						st.pop();
						break;
					}
				}
			}
			st.push(a[i]);
			t[a[i]] = 1;
		}
		while (!st.empty()) {
			ans[st.top()]++;
			st.pop();
		}
		js++;
	}
	for (int i = 1; i <= m; i++) {
		cout << ans[i] << " ";
	}
	return 0;
}
