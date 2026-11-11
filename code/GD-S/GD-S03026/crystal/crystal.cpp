#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define st first
#define nd second

const int N = 5e5 + 7;
vector<int> v(N);
int n, m;

signed main () {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> v[i];
	}
	sort(v.begin() + 1, v.begin() + n + 1);
	int res = 1, sum = 0;
	for (int l = 1, r = 2; r <= n; ++r) {
		sum += (v[r] - v[r - 1]) * (r - l);
		while (sum > m && l < r) {
			sum -= v[r] - v[l];
			l ++;
		}
		res = max(res, r - l + 1);
	}
	cout << res << endl;
	return 0;
}
