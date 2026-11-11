// 100

#include <bits/stdc++.h>

using namespace std;

#define int long long

const int kM = 4e5 + 7;

int n, a[kM], ans, cnt, q[kM << 1], h[kM << 1], qi, hi, z[kM << 2], zi;
char cq[kM << 1], ch[kM << 1], zc[kM << 2];
char c[kM];

signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
	}
//	cout << a[n] << "    \n\n";
	int l = 1, r = n;
	
	while (l < r) {
//		for (int i = 1; i <= qi; i++) {
//			cout << q[i] << " ";
//		}
//		cout << "\n";
//		for (int i = 1; i <= hi; i++) {
//			cout << h[i] << " ";
//		}
//		cout << "\n\n";
		if (a[l] == a[r]) {
//			cout << "JIN 1\n";
//			cout << "l = " << l << "    r = " << r << "\n";
//			for (int i = 1; i <= qi; i++) {
//				cout << q[i] << " ";
//			}
//			cout << "\n";
//			for (int i = 1; i <= hi; i++) {
//				cout << h[i] << " ";
//			}
			q[++qi] = a[l];
			cq[qi] = c[l];
			h[++hi] = a[r];
			ch[hi] = c[r];
			l++;
			r--;
		} else if (a[l] > a[r]) {
//			cout << "JIN 2\n";
//			cout << "l = " << l << "    r = " << r << "\n";
//			cout << "a[r] = " << a[r] << " \n"; 
			q[++qi] = a[r];
			cq[qi] = c[l];
			h[++hi] = a[r];
			ch[hi] = c[r];
			a[l] -= a[r];
			r--;
		} else {
//			cout << "JIN 3\n";
//			cout << "l = " << l << "    r = " << r << "\n";
			q[++qi] = a[l];
			cq[qi] = c[l];
			h[++hi] = a[l];
			ch[hi] = c[r];
			a[r] -= a[l];
			l++;
		}
	}
	for (int i = 1; i <= qi; i++) {
		z[++zi] = q[i];
		zc[zi] = cq[i];
	}
//	cout << "hhh = " << h[hi] << " \n\n";
	for (int i = hi; i >= 1; i--) {
		z[++zi] = h[i];
		zc[zi] = ch[i];
	}
//	for (int i = 1; i <= zi; i++) {
////		cout << z[i] << " " << zc[i] << "\n";
//		cout << z[i] << " ";
//	}
//	cout << "\n";
//	for (int i = 1; i <= zi / 2; i++) {
//		if (z[i] != z[zi - i + 1]) {
//			cout << "NOOOO!!!";
//			return 0;
//		}
//	}
	l = 1, r = zi;
	while (l < r) {
//		if (z[l] != z[r]) {
//			cout << "NOOOOO!";
//			return 0;
//		}
		if (zc[l] == zc[r]) {
			l++;
			r--;
		} else {
			ans += z[l];
			l++;
			r--;
		}
	}
	cout << ans;
	return 0;
}

/*
3
2 a
2 b
1 c

2
2 a
3 a

4
4 a
1 c
1 d
2 b

out : 4

*/
