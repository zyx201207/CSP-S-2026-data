//#include <iostream>
//
//using std::ios;
//using std::cin;
//using std::cout;
//using std::min;

#include <bits/stdc++.h>
using namespace std;

int c, T, n, cnt, u, v, ans, mn;
long long d, x[2000010];
bool b;

void D(int t, int sum, int mode) {
	if (t == v) {
		if (mode == 1) mn = min(mn, sum);
		else cnt += (sum == mn);
		return;
	}
	for (int i = t + 1; i <= n && x[i] - x[t] <= d; i++) D(i, sum + 1, mode);
}

void S() {
	ans = 0;
	cin >> n >> d;
	for (int i = 1; i <= n; i++) cin >> x[i];
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			mn = 1145141919, cnt = 0;
			u = i, v = j;
			D(u, 0, 1);
			D(u, 0, 2);
			ans += (cnt == 2);
//			if (cnt == 2) cout << "i = " << i << "\tj = " << j << "\n"; 
		}
	}
	cout << ans << "\n";
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> c >> T;
	while (T--) S();
	return 0;
}

// jin tian pcl he hmcl xia jia le, 
// ni men mimi shijie wan jia kai xin le ba, 
// zhe you xi pei le wo shi nian, shi nian a, 
// shuo xia jia jiu xia jia le.
