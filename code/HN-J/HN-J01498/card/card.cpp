#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 5;
stack <int> st;
bool f[N];
int n, m, a[N], cc[N];
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int c = 1; c <= n; c++) {
		memset(f, 0, sizeof f);
		for(int i = c; i <= n; i++) {
			if(f[a[i]]) {
				while(st.top() != a[i]) f[st.top()] = 0, st.pop();
			} else {
				f[a[i]] = 1;
				st.push(a[i]);
			}
		}
		while(!st.empty()) {
			cc[st.top()]++;
			st.pop();
		}
	}
	for(int i = 1; i <= m; i++) cout << cc[i] << " ";
	return 0;
}
