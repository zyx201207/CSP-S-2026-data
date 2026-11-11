#include <bits/stdc++.h>
using namespace std;
const int N = 500005;
int n, pre[N] = {0}, ans = 0;
long long a[N] = {0}, m, sum = 0;
vector<pair<long long, int> > v;
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	v.push_back({0, 0});
	for (int i = 1; i <= n; i++) {
		if (a[i] != a[i - 1]) v.push_back({a[i], i});
		else v[v.size() - 1].second++;
	}
	pre[1] = 0;
	for (int i = 2; i < v.size(); i++) {
		int l = pre[i - 1];
		sum += (v[i].first - v[i - 1].first) * (v[i - 1].second - v[l].second);
		while (sum > m) {
			l++;
			sum -= (v[i].first - v[l].first) * (v[l].second - v[l - 1].second);
		} pre[i] = l;
		ans = max(ans, v[i].second - v[pre[i]].second);
	}
	cout << ans;
	return 0;
}
