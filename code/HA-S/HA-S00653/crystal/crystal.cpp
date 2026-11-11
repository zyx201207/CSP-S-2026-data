#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

// UNLONGLONG!
// 排序
// 遍历右端点r
// 使用前缀和快速获取最大水晶个数
// 使用二分获取可能的最大左端点INDEX 
// 复杂度 O(NlogN)
// n <= 5 * 1e5，可行。必须开longlong
// 前缀和似乎用longlong也会溢出
// 哦不不不ai <= 1e12，很明显不会溢出
// LONG_LONG_MAX = 9223372036854775807 >= 1e12 * 5 * 1e5
// 现在开始写代码 
// 排序是否是必须的？是必须的

ll n, m;
vector<ll> a, prefixSum;

inline ll getM(ll l, ll r) {
	return (r - l) * a[r] - (prefixSum[r - 1] - prefixSum[l - 1]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
//	freopen("crystal1.in", "r", stdin);
//	freopen("crystal1.out", "w", stdout);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	cin >> n >> m;

	a.resize(n + 1);
	for (ll i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a.begin() + 1, a.end());
	
	prefixSum.resize(n + 1, 0);
	for (ll i = 1; i <= n; i++) {
		prefixSum[i] = prefixSum[i - 1] + a[i];
	}
	
	ll ans = LONG_LONG_MIN + 1;
	// 遍历右端点
	for (ll i = 1; i <= n; i++) {
		ll l = 1, r = i;
		ll mValue = 0;
		while (l < r) {
			ll mid = (l + r) / 2;
			mValue = getM(mid, i);
			if (mValue > m) {
				l = mid + 1;
			} else {
				r = mid;
			}
		}
		ans = max(ans, i - l + 1LL);
	}
	
	cout << ans << '\n';
	// 40min
	// 前缀和写错了，45min修改完毕 
	// 50min时检查完毕 
//	cout << LONG_LONG_MIN;
	return 0;
}
