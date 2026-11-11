#include <iostream>
#include <map>
#include <cmath>
#include <algorithm>
#define int long long
using namespace std;

const int N = 5e5 + 5;
map <pair<int, int>, int> mp;
int n, m, a[N], suf[N], pre[N];

bool checkA() {
	for(int i = 1; i <= n; i++)
		if(a[i] != i) return 0;
	return 1;
}

bool checkB() {
	int d = a[2] - a[1];
	for(int i = 3; i <= n; i++)
		if(a[i] - a[i - 1] != d) return 0;
	return 1;
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("cristal.in", "r", stdin);
	freopen("cristal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	if(m == 0) {
		cout << 0;
		return 0;
	}
	bool A = checkA(), B = checkB();
	if(A) {
		int ans = 0;
		if(m >= (int)sqrt(m) * ((int)sqrt(m) + 1) && m < ((int)sqrt(m) + 1) * ((int)sqrt(m) + 1))
			ans += ((int)sqrt(m) * 2);
		else if(m >= (int)sqrt(m) * (int)sqrt(m) && m < (int)sqrt(m) * ((int)sqrt(m) + 1))
			ans += ((int)sqrt(m) * 2 - 1);
		cout << min(ans, n);
		return 0;
	}
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++) suf[i] = suf[i - 1] + a[i];
	for(int i = n; i >= 1; i--) pre[i] = pre[i + 1] + a[i];
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = i + 1; j <= n; j++) {
			int mid = (i + j) / 2;
			int l = abs((mid - i) * a[mid] - suf[mid - 1] + suf[i - 1]);
			int r = abs(pre[mid + 1] - pre[j + 1] - (j - mid) * a[mid]);
			mp[{i, j}] = l + r;
			if(l + r <= m) ans = max(ans, j - i + 1);
		}
	}
	cout << mp[{1, n}];
}
