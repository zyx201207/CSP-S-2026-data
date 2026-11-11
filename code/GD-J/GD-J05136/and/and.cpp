#include <bits/stdc++.h>
const int N = 2e5 + 10;
using namespace std;
long long n, m, a[N], pos[50][N], len[N], lmax, ans;
bool need[50];
bool check(int j) {
	for(int i = 1; i <= 35; i ++) {
		if(need[i] && pos[i][j] != 1) return 1;
	}
	return 0;
}
long long pow1(int i) {
	long long res = 1;
	while(i --) res *= 2;
	res /= 2;
	return res;
}
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i ++) cin >> a[i];
	sort(a + 1, a + 1 + n);
	for(int i = 1;i <= n;i ++) {
		long long h = a[i];
		while(h) {
			pos[++len[i]][i] = h % 2;
			h /= 2;
		}
		lmax = max(lmax, len[i]);
	}
	for(int i = lmax; i >= 1; i --) {
		int count = 0;
		for(int j = 1; j <= n; j ++) {
			if(check(j)) continue;
			if(pos[i][j] == 1) count ++;
		}
		if(count >= m) need[i] = 1;
	}
	for(int i = 1;i <= 49;i ++) {
		if(need[i]) {
			ans += (1 << (i - 1));
		}
	}
	cout << ans;
	return 0;
}
