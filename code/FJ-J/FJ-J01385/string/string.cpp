#include <iostream>
#include <algorithm>
using namespace std;
#define Write cin.tie(nullptr);
#define by cout.tie(nullptr);
#define ___NightDay___ ios::sync_with_stdio(0)
#define N 200005
#define int long long

int n, l;
struct Node {
	int bp, lt;
	char c;
	bool operator<(const Node x) const {
		return bp < x.bp;
	}
} a[N], b[N], c[2 * N];

signed main() {
	Write by ___NightDay___;
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	a[1].bp = 1;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i].lt >> a[i].c;
		a[i + 1].bp = a[i].bp + a[i].lt;
	}
	l = a[n + 1].bp - 1;
	a[n + 1].c = a[n].c;
	for (int i = 1; i <= n; i ++) {
		b[i].bp = l - a[i + 1].bp + 2;
		b[i].lt = a[i].lt;
	}
	sort(b + 1, b + n + 1);
	int cnt = 1, pa = 1, pb = 1;
	c[1].bp = 1;
	c[1].c = a[pa].c;
	pa ++;
	pb ++;
	while (1) {
		cnt ++;
		if ((a[pa].bp < b[pb].bp && pa <= n) || pb > n) {
			c[cnt].bp = a[pa].bp;
			pa ++;
		} else if (a[pa].bp == b[pb].bp && pa <= n && pb <= n) {
			c[cnt].bp = a[pa].bp;
			pa ++;
			pb ++;
		} else {
			c[cnt].bp = b[pb].bp;
			pb ++;
		}
		if (pb > n && pa > n) {
			break;
		}
	}
	c[cnt + 1].bp = l + 1;
	for (int i = 1; i <= cnt; i ++) {
		c[i].lt = c[i + 1].bp - c[i].bp;
		int l = 1, r = n, ans = 0;
		while (l <= r) {
			int mid = (l + r)  >> 1;
			if (a[mid].bp == c[i].bp) {
				ans = mid;
				break;
			}
			if (a[mid].bp <=c[i].bp) {
				ans = mid;
				l = mid + 1;
			} else {
				r = mid - 1;
			}
		}
		c[i].c = a[ans].c;
	}
	int ans = 0;
	for (int i = 1; i <= cnt / 2; i ++) {
		if (c[i].c != c[cnt - i + 1].c) {
			ans += c[i].lt;
		}
	}
	cout << ans;
	return 0;
}
// 你自己看看你 J 组 T2 放的什么 勾10 玩意，卡了我一小时 
// 100pts 
