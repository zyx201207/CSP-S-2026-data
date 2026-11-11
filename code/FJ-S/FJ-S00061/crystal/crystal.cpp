#include <bits/stdc++.h>
#define int long long
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;

int n, m, a[500005];

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin>>n>>m;
	for (int i = 1; i <= n; i++) cin>>a[i];
	sort(a+1, a+1+n);
	deque<int> q;
	int ans = 0;
	int cur = 0;
	for (int i = 1; i <= n; i++) {
		if (!q.empty()) cur += q.size() * (a[i] - q.front());
		while (!q.empty() && cur > m) {
			int v = q.back();
			q.pop_back();
			cur -= (a[i] - v);
		}
		q.push_front(a[i]);
		ans = max(ans, q.size());
	}
	cout<<ans;
	return 0;
}
