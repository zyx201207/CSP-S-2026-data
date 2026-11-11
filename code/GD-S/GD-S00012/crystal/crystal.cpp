#include <bits/stdc++.h>
using namespace std;

using ll  = long long;
using ull = unsigned long long;

int fast_io = []() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin.tie(nullptr) -> sync_with_stdio(false);
	return 0;	
}();

constexpr int N = 5e5;

ll n, m;
ll arr[N + 5];
ll sum[N + 5];

bool check(int x) {
	for (int i = x; i <= n; i++) {
		int l = i-x+1;
		ll ans = arr[i] * x;
		ll tmp = sum[i] - sum[l-1];
		if (ans - tmp <= m) {
			return true;
		}
	} return false;
}

void input() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	} sort(arr+1, arr+n+1);
	for (int i = 1; i <= n; i++) {
		sum[i] = sum[i-1] + arr[i];
	}
}

void solve() {
	int l = 1;
	int r = n+1;
	while (l+1 < r) {
		int mid = (l+r) >> 1;
		if (check(mid)) l = mid;
		else r = mid;
	} cout << l << endl;
}

int main() {
	input();
	solve();
	return 0;
}
