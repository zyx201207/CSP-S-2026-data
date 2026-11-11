#include<bits/stdc++.h>
using namespace std;
#define int long long
int n, m, mxnum;
int a[500005],b[500005],pre[500005];
//bool check(int mid) {
//	for (int i = 1; i <= n; i++) {
//		b[i] = a[i] - mid;
//		if (b[i] < 0) b[i] = -b[i];
//	}
//	sort(b + 1, b + 1 + n);
//	int sum = 0;
//	for(int i = 1;i <= n ;i ++){
//		sum += b[i];
//		if (sum >= m) {
//			if (i - 1 > mxnum) {
//				mxnum
//			}
//		}
//	}
//}
bool check(int mid,int i) {
	int q = i - mid + 1;
	if (a[i] * q - (pre[i] - pre[mid-1]) <= m) {
		return 1;
	}
	else return 0;
}
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++) {
		pre[i] = a[i] + pre[i - 1];
	}
	for (int i = 1; i <= n; i++) {
		int l = 1, r = i;
		while (l < r) {
			int mid = (l + r) >> 1;
			if (check(mid,i)) {
				r = mid;
			}
			else {
				l = mid + 1;
			}
		}
		b[i] = i - l + 1;
	}
	int mx = 0;
	for(int i =1; i<= n ;i ++){
//		cout << b[i] << ' ';
		mx = max(mx, b[i]);
	}
//	cout << endl;
	cout << mx;
	fclose(stdin);
	fclose(stdout);
}
