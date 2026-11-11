#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define file(s)	freopen(#s".in", "r", stdin), freopen(#s".out", "w", stdout)
const int N = 5e5 + 10;
int n, m, a[N], s[N], top;
int cnt[N];
bool vis[N];
signed main() {
	file(card);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)	cin >> a[i];
	for (int op = 1; op <= n; ++op) {
		top = 0;
		for (int i = op; i <= n; ++i) {
			if (vis[a[i]]) {
				while (s[top] != a[i])	vis[s[top]] = 0, top--;
				top--;
			}
			s[++top] = a[i];
			vis[a[i]] = 1;
		}
		for (int i = 1; i <= m; ++i) {
			if (vis[i])	cnt[i]++;	
			vis[i] = 0;
		}
	}
	for (int i = 1; i <= m; ++i)	cout << cnt[i] << " ";
	return 0;
}
