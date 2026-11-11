#include<bits/stdc++.h>
#define endl '\n'
#define pi pair<int, int>
#define ll long long

using namespace std;
const int N = 5e5 + 10;
int n;
ll m, a[N], s[N];

inline bool check(int l, int r) {
	ll sum = s[r] - s[l - 1];
	ll len = r - l + 1;
	return (len*a[r] - m) <= sum;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
	int ans = 1;
	for (int i = 2; i <= n; i++) {
		int l = 1, r = i, res = i;
		while (l <= r) {
			int mid = l + r >> 1;
			if (check(mid, i)) r = mid - 1, res = mid;
			else l = mid + 1;
		}
		ans = max(ans, i - res + 1);
	}
	cout << ans << endl;
	return 0;
}
