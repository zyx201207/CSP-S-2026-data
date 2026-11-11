// 14:37 配置完环境，看了第一题，一眼二分
// 14:51 编码完成，大阳历全过，好久没有这么顺利过
// 14:53 垃圾鼠标，滚轮根本托不动，移动还很卡，还好最近学了用vim

#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10;
int n;
int64_t m;
int64_t A[N];
int64_t F[N];

int64_t check (int k) {
	int64_t wzh = 1.1e18;
	for (int i = k; i <= n; i++) {
		int64_t tmp = A[i] * k - (F[i] - F[i - k]);
		wzh = min(wzh, tmp);
	}
	return wzh;
}

int main () {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	ios :: sync_with_stdio(0); cin.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> A[i];
	}

	sort(A + 1, A + 1 + n);

	for (int i = 1; i <= n; i++) {
		F[i] = F[i - 1] + A[i];
	}

	int l = 1, r = n, ans = -1;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (check(mid) <= m) {
			ans = mid;
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}

	cout << ans << "\n";
}