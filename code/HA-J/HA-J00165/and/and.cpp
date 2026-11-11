#include<bits/stdc++.h>
using namespace std;
/*
guanzhu _Liyx_ miao
AC at 9:22
*/
#define N 200005
int n, m, a[N];
int ans;
bool flg[N];
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		flg[i] = 1;
	}
	for (int i = 30; i >= 0; i--) {
		int k = 0;
		for (int j = 1; j <= n; j++) {
			if (!flg[j]) continue;
			if (a[j] >> i & 1) k++;
		}
		if (k >= m) {
			ans |= 1 << i;
			for (int j = 1; j <= n; j++) {
				if (!flg[j]) continue;
				if (!(a[j] >> i & 1)) flg[j] = 0;
			}
		}
	}
	cout << ans;
	return 0;
}
