#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 5;
int n, a[N], pos[N], ans;
char c[N];
int findpos(int x){
	return (lower_bound(pos + 1, pos + n + 1, x) - pos);
}
signed main(){
	cin.tie(0)->sync_with_stdio(0);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; ++i){
		cin >> a[i] >> c[i];
		pos[i] = pos[i - 1] + a[i];
	}
	int mid = pos[n] / 2 + 1;
	if (pos[n] & 1){
		int l = mid - 1, r = mid + 1;
		while (l >= 1 && r <= pos[n]){
			int pl = findpos(l), pr = findpos(r);
			int ll = pos[pl - 1] + 1, rr = pos[pr];
			if (rr - mid <= mid - ll){
				if (c[pl] != c[pr]){
					ans += rr - r + 1;
				}
				r = rr + 1, l = 2 * mid - r;
			} else {
				if (c[pl] != c[pr]){
					ans += l - ll + 1;
				}
				l = ll - 1, r = 2 * mid - l;
			}
		}
		cout << ans;
	} else {
		int l = mid - 1, r = mid;
		while (l >= 1 && r <= pos[n]){
			int pl = findpos(l), pr = findpos(r);
			int ll = pos[pl - 1] + 1, rr = pos[pr];
			if (rr - mid + 1 <= mid - ll){
				if (c[pl] != c[pr]){
					ans += rr - r + 1;
				}
				r = rr + 1, l = 2 * mid - r - 1;
			} else {
				if (c[pl] != c[pr]){
					ans += l - ll + 1;
				}
				l = ll - 1, r = 2 * mid - l - 1;
			}
		}
		cout << ans;
	}
	return 0;
} 
/*
double 有没有懂的。
神了。
懒死了。
11:34 ：

卧槽我小样例没过。。。改改改。。 
过了。。。 

还是使用 int 吧。
define int long long 对对对。

算了懒得改线性了，老哥就老哥吧。 
*/ 
