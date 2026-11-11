#include <bits/stdc++.h>
#define LL long long

using namespace std;

const int N = 5e5 + 10;

int n;
LL m, a[N];
LL b[N], cnt[N], idx = 0;
LL s[N], sum[N], res = 0;

inline bool check (int x, int ed) {
	LL tot = (sum[ed] - sum[x - 1])  - (b[idx] - b[ed]) * (s[ed] - s[x - 1]);
	if (tot > m) return false;
	return true;
}

int main() {
	freopen ("crystal.in", "r", stdin);
	freopen ("crystal.out", "w", stdout);
	
	scanf ("%d %lld", &n, &m);
	for (int i = 1; i <= n; i ++) scanf ("%lld", &a[i]);
	
	sort (a + 1, a + n + 1);
	
	for (int i = 1; i <= n; ) {
		b[++ idx] = a[i]; cnt[idx] ++; i ++;
		while (a[i] == a[i - 1]) cnt[idx] ++, i ++;
	}
	
	for (int i = 1; i <= idx; i ++) s[i] = s[i - 1] + cnt[i];
	for (int i = 1; i <= idx; i ++) sum[i] = sum[i - 1] + cnt[i] * (b[idx] - b[i]);
	
//	for (int i = 1; i <= idx; i ++) cout << s[i] << " ";
//	cout << endl;
//	for (int i = 1; i <= idx; i ++) cout << sum[i] << " ";
//	cout << endl;
	
	for (int i = idx; i; i --) {
		int l = 1, r = i, target = 0;
//		cout << i << endl;
		while (l <= r) {
//			cout << l << " " << r << endl;
			int mid = (l + r) / 2;
			if (check (mid, i)) r = mid - 1, target = mid;
			else l = mid + 1;
		}
		res = max (res, s[i] - s[target - 1]);
	}
	
	printf ("%lld\n", res);
	
	return 0;
}