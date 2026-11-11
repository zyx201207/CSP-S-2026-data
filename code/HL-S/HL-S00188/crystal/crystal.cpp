#include <bits/stdc++.h>
using namespace std;

namespace OI {

#define int long long
#define endl "\n"

constexpr int maxn = 5e5+5;

int n, m;
int a[maxn], pre[maxn];

void main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++)
		pre[i] = a[i] + pre[i - 1];
	int ret = 0;
	for (int i = 1; i <= n; i++) {
		int l = 1, r = i, ans;
		while (l <= r) {
			int mid = l + r >> 1;
			if (a[i] * (i - mid + 1) - (pre[i] - pre[mid - 1]) <= m) {
				ans = mid;
				r = mid - 1;
			} else
				l = mid + 1;
		}
		ret = max(ret, i - ans + 1);
	}
	cout << ret << endl;
}

#undef int
#undef endl

}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	cin.tie(0), cout.tie(0);
	ios::sync_with_stdio(0);
	
	OI::main();
	
	return 0;
}
