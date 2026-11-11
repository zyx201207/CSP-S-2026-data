#include <bits/stdc++.h>
using namespace std;

int n, m;
long long ans;
vector<long long> a, ps;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	a.resize(n + 5);
	ps.resize(n + 5);
	ps[0] = 1;
	for (int i = 1; i <= n; i++)
		cin >> a[i],
		ps[i] = ps[i - 1] & a[i];
	for (int i = m; i <= n; i++)
		ans = max(ans, ps[i] | ps[i - m + 1]);
	cout << ans;
	return 0;
}
