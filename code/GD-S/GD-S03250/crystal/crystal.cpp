#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5e5 + 5;
int n;
int maxcnt = 0;
ll m;
ll a[N];
ll pre[N];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];

	sort(a + 1, a + n + 1);
	int l = 1;
	ll sum = 0;
	for (int r = 2; r <= n; r++) {
		// 假如大家都变成a[r] 
		sum += (r - l) * (a[r] - a[r - 1]);
		while (sum > m) {
			sum -= (a[r] - a[l]);
			l++;
		}
		maxcnt = max(maxcnt, r - l + 1);
	}
	cout << maxcnt;
	return 0;
}
