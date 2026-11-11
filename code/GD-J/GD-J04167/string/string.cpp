#include<bits/stdc++.h>
using namespace std;
long long n;
long long a[200005];
char c[200005];
long long sum;
pair<long long, long long> find_mid() {
	long long s = 0;
	for (long long i = 1; i <= n; i++) {
		s += a[i];
		if (s >= sum) return {i, a[i] - (s - sum)};
	}
	return {-1, -1};
}
long long ans;
//string st;
//long long find(long long x, long long y) {
//	long long sum = 0;
//	for (int i = 1; i <= x; i++)  sum += a[i];
//	return sum + y;
//}
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
		sum += a[i];
//		
//		for (int i = 1; i<= a[i]; i++) st = st + c[i];
	}
	long long t = sum % 2;
	sum = sum / (long long)2;
	pair<long long, long long> x = find_mid();
	long long t1 = x.first, t2 = x.second;
//	cout << t1 << " " << t2 << "\n";
	long long l = t1, l2 = t2, r = t1, r2 = t2 + 1;
	if (t == 1) l2--;
	if (l2 < 1) l--, l2 = a[l];
	if (r2 > a[r]) r++, r2 = 1;
	for (; l >= 0 && r <= n; ) {
//		cout << l << " " << l2 << " " << r << " " << r2 << "\n";
		long long len1 = l2, len2 = a[r] - r2 + 1;
//		cout << len1 << " " << len2 << "\n";
		if (c[l] != c[r]) ans += min(len1, len2);
		if (len1 == len2) {
			l--, r++;
			l2 = a[l], r2 = 1;
		} else if (len1 < len2) {
			r2 += l2;
			l--;
			l2 = a[l];
		} else {
			l2 -= len2;
			r++;
			r2 = 1;
		}
//		if (st[n + 1 - find(l, l2) - 1] != st[find(r, r2)]) {
//			
//			cout << l << " " << l2 << " " << r << " " << r2 << "\n";
//			return 0;
//		}
	}
	cout << ans;
	return 0;
}

