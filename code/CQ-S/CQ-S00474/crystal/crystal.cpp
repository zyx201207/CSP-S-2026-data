#include <bits/stdc++.h>
using namespace std;
namespace WorldMachine {
	#define int long long
	const int N = 5e5 + 5;
	int n, m, a[N], s[N];
	void main() {
		cin >> n >> m;
		for (int i = 1; i <= n; i++) cin >> a[i];
		sort(a + 1, a + 1 + n);
		for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			int l = 1, r = i, ret = i;
			while (l <= r) {
				int mid = (l + r) >> 1;
				if ((i - mid + 1) * a[i] - (s[i] - s[mid - 1]) <= m)
					ret = mid, r = mid - 1;
				else l = mid + 1;
			}
			ans = max(ans, i - ret + 1);
		}
		cout << ans;
	}
	#undef int
}
int main() {
	freopen("crystal.in", "r", stdin), freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	return WorldMachine::main(), 0;
}
/*
每次选一个数 ++，至多操作 m 次，最大化众数出现次数
最后众数肯定在原数列里面出现过，枚举一下
容易二分出最大个数，时间复杂度 O(n log n)
*/
