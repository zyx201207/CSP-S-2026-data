#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 5e5 + 10;
const ll V = 1e18;

int n;
ll m, a[N], sum[N];

bool check(int p, int x) {
	int len = x - p + 1;
	ll res = 1ll * len * a[x] - (sum[x] - sum[p - 1]);
	return res > m;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);

	for (int i = 1; i <= n; i++) {
		sum[i] = sum[i - 1] + a[i];
	}
	int res = 0;
	for (int i = 1; i <= n; i++) {
		int L = 1, R = i, pos = 0;
		while (L <= R) {
			int mid = L + (R - L) / 2;
			if (check(mid, i)) L = mid + 1, pos = mid;
			else R = mid - 1;
		}
		res = max(res, i - L + 1);
//		cout << i << ' ' << L << "\n";
	}
	cout << res << "\n";


	return 0;
}

/*
5 5
1 2 4 8 9
*/
