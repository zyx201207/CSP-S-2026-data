#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MAXN = 500005;
int n;
ll m, A[MAXN], S[MAXN];

bool check(int base, int mid) {
	return mid * A[base] - (S[base + mid] - S[base]) <= m;
}

int work(int base) {
	int l = 0, r = n - base;
	while (l < r) {
		int mid = (l + r + 1) / 2;
		if (check(base, mid))
			l = mid;
		else 
		    r = mid - 1;
	}
	return l + 1;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)cin >> A[i];
	sort(A + 1, A + 1 + n, greater<ll>());
	for (int i = 1; i <= n; ++i) {
		S[i] = S[i - 1] + A[i];
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		ans = max(ans, work(i));
	}
	cout << ans;
	return 0;
}