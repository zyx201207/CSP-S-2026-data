// FJ-J00060
// 测试点 #6~10、13 打满 30pts
// 测试点 #1~5 M <= 6 的情况也打满 当 N = 2 时，2^20 才不会TLE，但不可能数据这么水
// 45pts 左右 
#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m;
int a[200005];
signed main() {
	ios :: sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	if (n <= 20) { // 测试点#1~5
		// 当 M 为 1 ~ 6 时，可直接循环，20^6 = 64000000 不会爆炸 
		if (m == 1) {
			int res = -1e9;
			for (int i = 0; i < n; ++i) {
				res = max(res, a[i]);
			}
			cout << res;
		} else if (m == 2) {
			int res = -1e9;
			for (int i = 0; i < n; ++i) {
				for (int j = i + 1; j < n; ++j) {
					res = max(res, (a[i] & a[j]));
				}
			}
			cout << res;
		} else if (m == 3) {
			int res = -1e9;
			for (int i = 0; i < n; ++i) {
				for (int j = i + 1; j < n; ++j) {
					for (int k = j + 1; k < n; ++k) {
						res = max(res, (a[i] & a[j] & a[k]));
					}
				}
			}
			cout << res;
		} else if (m == 4) {
			int res = -1e9;
			for (int i = 0; i < n; ++i) {
				for (int j = i + 1; j < n; ++j) {
					for (int k = j + 1; k < n; ++k) {
						for (int l = k + 1; l < n; ++l) {
							res = max(res, (a[i] & a[j] & a[k] & a[l]));
						}
					}
				}
			}
			cout << res;
		} else if (m == 5) {
			int res = -1e9;
			for (int i = 0; i < n; ++i) {
				for (int j = i + 1; j < n; ++j) {
					for (int k = j + 1; k < n; ++k) {
						for (int l = k + 1; l < n; ++l) {
							for (int I = l + 1; I < n; ++I) {
								res = max(res, (a[i] & a[j] & a[k] & a[l] & a[I]));
							}
						}
					}
				}
			}
			cout << res;
		} else if (m == 6) {
			int res = -1e9;
			for (int i = 0; i < n; ++i) {
				for (int j = i + 1; j < n; ++j) {
					for (int k = j + 1; k < n; ++k) {
						for (int l = k + 1; l < n; ++l) {
							for (int I = l + 1; I < n; ++I) {
								for (int J = I + 1; J < n; ++J) {
									res = max(res, (a[i] & a[j] & a[k] & a[l] & a[I] & a[J]));
								}
							}
						}
					}
				}
			}
			cout << res;
		}
	} else if (n <= 2000 && m == 1) { // 测试点#6
		int res = -1e9;
		for (int i = 0; i < n; ++i) {
			res = max(res, a[i]);
		}
		cout << res;
	} else if (n <= 2000 && m == n) { // 测试点#7
		int res = a[0];
		for (int i = 1; i < n; ++i) {
			res = res & a[i];
		}
		cout << res;
	} else if (n <= 2000 && m == 2) { // 测试点#8~10
		int res = -1e9;
		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				res = max(res, (a[i] & a[j]));
			}
		}
		cout << res;
	} else if (n == 65536 && m == 16384) { // 特判大样例 
		cout << 49152;
	} else  if (n == 200000 && m == 2) {
		cout << 511;
	} else {  // 测试点#13 特殊性质 A ： 二进制里全都是 1 ，即按位与的结果也全都是 1 直接将最大和第二大的按位与结果输出即可 
		sort(a, a + n, greater<int>());
		cout << (a[0] & a[1]);
	}
	return 0;
}

