#include <bits/stdc++.h>
#define int long long
//#define double long double
#define max(x, y) ((x) > (y) ? (x) : (y))
#define min(x, y) ((x) < (y) ? (x) : (y))
using namespace std;
int C, T;
int n, d;
int a[2000010];
int ls[2000010], rs[2000010]; //向左向右最远跳到的节点
int fl[2000010], fr[2000010]; //单径岛屿对（确信
int ans;
signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> C >> T;
	while(T--) {
		cin >> n >> d;
		for(int i = 1; i <= n; i++) {
			scanf("%lld", &a[i]);
			ls[i] = rs[i] = fl[i] = fr[i] = 0;
		}
		for(int i = 1; i <= n; ++i) {
			rs[i] = max(i, rs[i - 1]);
			while(a[rs[i] + 1] - a[i] <= d && rs[i] < n) ++rs[i];
//			fr[i] = rs[i] - i;
			if(rs[i] != i) ++fl[rs[i]];
		}
		ls[n + 1] = n;
		for(int i = n; i >= 1; --i) {
			ls[i] = min(i, ls[i + 1]);
			while(a[i] - a[ls[i] - 1] <= d && ls[i] > 1) --ls[i];
//			fl[i] = i - ls[i];
			if(ls[i] != i) ++fr[ls[i]];
		}
//		for(int i = 1; i <= n; i++) {
//			cout << ls[i] << ' ';
//		}
//		cout << endl;
//		for(int i = 1; i <= n; i++) {
//			cout << rs[i] << ' ';
//		}
//		cout << endl;
		for(int i = 1; i <= n; ++i) {
			if(rs[ls[i]] == i) fl[i] += fl[ls[i]];
		}
		for(int i = n; i >= 1; --i) {
			if(ls[rs[i]] == i) fr[i] += fr[rs[i]];
		}
		ans = 0;
		for(int i = 1; i <= n; i++) {
			if(rs[i] == i || rs[i] - 1 == i) continue;
			int ql = lower_bound(ls + 1, ls + n + 1, rs[i] - 1) - ls;
			int qr = upper_bound(ls + 1, ls + n + 1, rs[i] - 1) - ls - 1;
			if(qr < ql) continue;
			if(ls[rs[i] - 1] == i && qr == rs[rs[i]]) ans += (fl[i] + 1) * (fr[qr] + (qr - ql + 1));
			else if(ls[rs[i] - 1] == i) ans += (fl[i] + 1) * (qr - ql + 1);
			else if(qr == rs[rs[i]]) ans += fr[qr] + (qr - ql + 1);
			else ++ans;
//			cout << i << ' ' << ans << endl;
		}
		cout << ans << endl;
	}
	return 0;
}
/*
0 2
10 21
0 7 14 21 28 35 42 49 56 63
10 22
0 7 14 21 28 35 42 49 56 63

*/
