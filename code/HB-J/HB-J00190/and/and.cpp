#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
using ll = long long;
using ull = unsigned long long;

const int N = 2e5 + 5, maxn = 1.1e9 + 5;
ll n, m, a[N], ans, k = 1;

void dfs(ll sum, ll cur, ll lst) {
	if (cur == m + 1) {
		ans = max(ans, sum);
		return ;
	}
	for (int i = lst + 1; i <= n; i++) {
		dfs(sum & a[i], cur + 1, i);
	}
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= 31; i++) k *= 2;
	for (int i = 1; i <= n; i++) cin >> a[i];
	dfs(k - 1, 1, 0);
	cout << ans;
	return 0;
}
