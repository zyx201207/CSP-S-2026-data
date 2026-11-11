#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5; 
int n, m, k, sum, cnt, a[N], ans[N], vis[N];
deque<int>q;
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0); 
	int i, j, x, y, z, t;
	cin >> n >> m;
	for (i = 1; i <= n; i++)
		cin >> a[i];
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++)
			vis[j] = 0;
		for (j = i; j <= n; j++) {
			if (vis[a[j]]) {
				while (q.back() != a[j])
					vis[q.back()] = 0, q.pop_back();
				q.pop_back();
			}
			q.push_back(a[j]);
			vis[a[j]] = 1;
		}
		while (!q.empty())
			ans[q.back()]++, q.pop_back();
	}
	for (i = 1; i <= m; i++)
		cout << ans[i] << " "; 
	return 0;
}
