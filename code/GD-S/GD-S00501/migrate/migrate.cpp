#include <bits/stdc++.h>
typedef long long LL;
using namespace std;
//#define DEBUG(x, y) (cerr << :(x) << ":" << x << ' ' << (y))

constexpr int MAXN = 5e6+10, MAXNN = 5e3+10;
int TC, T;
int n;
LL d;
LL x[MAXN];
LL f[MAXN];
int lft[MAXN], rgt[MAXN];
LL sum[MAXN];
LL ans;

void clr() {
//	memset(sum, 0, sizeof(sum));
	for (int i = 1; i<=n+n; i++) sum[i] = f[i] = lft[i] = rgt[i] = 0;
	ans = 0;
}

void solve1() {
	for (int i = 1; i<=n; i++) {
		for (int j = i; j<=n; j++) {
			if (x[j] - x[i] <= d) rgt[i] = j;
			else break;
		}
		for (int j = i; j>=1; j--) {
			if (x[i] - x[j] <= d) lft[i] = j;
			else break;
		}
	}
	for (int i = 1; i<=n; i++) {
//		cerr << "i:" << i << endl;
		sum[i] = 1;
		for (int j = i-1, las = i; j>=0; j--) {
			if (x[las] - x[j] > d || j == 0) { // 处理j+1 
//				cerr << "j+1:" << j+1 << endl;
				for (int k = las-1; k>j; k--) { // 这些点需要！ 
					int l = las, r = min(i, rgt[k]);
					f[k] = sum[l] - sum[r+1];
//					cerr << "k:" << k << ' ' << "l:" << l << ' ' << "r:" << r << ' ' << "f[k]" << ' ' << f[k] << endl;
					if (f[k] == 2) ans++;
					sum[k] = sum[k+1] + f[k];
				}
				las = j+1;
				if (j == 0 || x[las]-x[j] > d) break; // 停下！ 
			}
			
		}
	}
	cout << ans << '\n';
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
//	freopen("migrate3.in", "r", stdin);
//	freopen("myout.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> TC >> T;
	while (T--) {
		cin >> n >> d;
		clr();
		for (int i = 1; i<=n; i++) cin >> x[i];
//		if (TC <= 10) {
			solve1();
//		}
	}
	return 0;
}

