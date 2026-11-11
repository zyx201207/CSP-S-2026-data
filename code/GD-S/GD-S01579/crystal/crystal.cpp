#define zhc
#include <iostream>
#include <algorithm>
#define int long long
using namespace std;
int a[500005];
int b[500005];
int n, m;
bool check(int c) {
	int rad = c / 2;
	int flag = false;
	int i = rad + c % 2;
	//cout << "start_c: " << c << endl;
	for (; i <= n - rad; i++) {
		// including end but no front
		int end = i + rad;
		int front = i - rad - c % 2;
		int sum = b[end] - b[front];
		int qmax = a[end];
		int req = qmax * c;
		//cout << "    i/rad/b_back/b_front/qmax/req: " << i << ' ' << rad << ' ' << end << ' ' << front << ' ' << qmax << ' ' << req << endl;
		if (req <= sum + m) {
			flag = true;
			break;
		}
	}
	//cout << "end_flage: " << flag << endl;
	return flag;
}
signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	//int l = -1, r = -1;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		//l = min(a[i], l); r = max(a[i], r);
	}
	// yuchuli
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++) {
		b[i] = b[i - 1] + a[i];
	}
	// ans find
	int ans = -1, l = 1, r = n;
	while (l < r) {
		int mid = l + (r - l) / 2;
		if (check(mid)) {
			l = mid + 1;
			ans = mid;
		}
		else {
			r = mid;
		}
	}
	cout << ans << endl;
	return 0;
}
