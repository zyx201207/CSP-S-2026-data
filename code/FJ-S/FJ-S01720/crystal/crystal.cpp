# include<bits/stdc++.h>

# define int long long

using namespace std;

const int N = 500005;

int n, m, sum, ans;
int a[N];

priority_queue<int> q;

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin.tie(0) -> ios :: sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 1; i <= n; i ++)
		cin >> a[i];

	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i ++) {
		sum += q.size() * (a[i] - a[i - 1]);
		while (sum > m) {
			int x = - q.top();
			q.pop();
			sum -= (a[i] - x);
		}
		q.push(- a[i]);
		int sz = q.size();
		ans = max(ans, sz);
	}

	cout << ans << "\n";

	return 0;
}