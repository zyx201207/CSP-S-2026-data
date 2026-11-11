#include<bits/stdc++.h>
using namespace std;

long long n, m;
struct node {
	long long x, y;
};
node a[200005];
long long f[200005][5]; 
bool vis[200005];

long long work(long long x) { // 计算位数 
	long long cnt = 0;
	while (x) {
		cnt++;
		x /= 2;
	}
	return cnt;
}

bool check(long long x, long long w) {
	bool ff = 0;
	long long cnt = 0;
	while (x) {
		++cnt;
		if (cnt == w && x % 2 == 0) return false;
		if (cnt == w && x % 2 == 1) return true;
		x /= 2;
	}
	return false;
}

signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	long long maxn = 0;
	for (long long i = 1; i <= n; i++) {
		cin >> a[i].x;
		maxn = max(maxn, work(a[i].x));
	}
	
	long long ans = 0;
	for (long long w = maxn; w >= 1; w--) { // 从最大位数开始，求最大 
		long long cnt = 0;
		for (long long i = 1; i <= n; i++) {
			if (check(a[i].x, w) && !vis[i]) {
				++cnt;
			}
		}
//		cout << w << " " << cnt << endl;
		if (cnt >= m) { // 如果成立，就 ans 记录
			ans += (1 << (w - 1));
			for (long long i = 1; i <= n; i++) {
				if (!check(a[i].x, w)) vis[i] = 1;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
/*
4 2
3 15 12 12
*/
