#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e5 + 5;
int n, m, a[N], ans, pre[N];

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) {
		priority_queue<int, vector<int>, greater<int>> q;
		for (int j = 1; j <= n; j++) {
			if (i != j) {
				q.push(abs(a[i] - a[j]));
			}
		}
		
		int t = m, sum = 0;
		
		while (!q.empty() && t >= q.top()) {
			t -= q.top(); q.pop(); sum++;
		}
		ans = max(ans, sum);
	}
	cout << ans + 1;
	
	return 0;
}
