#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 5e5 + 10;

int n; ll m, a[N];
ll pre[N];

bool check(int l, int r) {
	int need = a[r] * (r - l + 1) - (pre[r] - pre[l - 1]);
	return (need <= m);
}

int get(int x) {
	int l = x, r = n, ans = x;
	
	while (l <= r) {
		int mid = (l + r) >> 1;
		
		if (check(x, mid))
			ans = mid, l = mid + 1;
		else
			r = mid - 1;
	}
	
	return ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	
	sort(a + 1, a + n + 1);
	
	for (int i = 1; i <= n; i++)
		pre[i] = pre[i - 1] + a[i];
	
	int res = 0;
	for (int i = 1; i <= n; i++) {
		res = max(res, get(i) - i + 1);
	}
	
	cout << res << endl;
	
	return 0;
}
