#include<bits/stdc++.h>
using namespace std;
long long n, m;
long long a[500005];
long long x[300005];
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = n; i >= 1; i--) {
		stack<long long> st;
		vector<bool> mp(m + 1, false);
		for (int j = i; j <= n; j++) {
			if (mp[a[j]] == false) {
				mp[a[j]] = true, st.push(a[j]);
			} else {
				while (st.top() != a[j]) {
					mp[st.top()] = false;
					st.pop();
				}
			}
		}
		while (!st.empty()) {
			x[st.top()]++;
			st.pop();
		}
	}
	for (int i = 1; i <= m; i++) cout << x[i] << " ";
	return 0;
}

