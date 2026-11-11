#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 7;
int n, ret = 1;
long long m, a[N], s[N];
int main() {
	freopen("crystal3.in", "r", stdin);
//	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	int M = m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + 1 + n);
	bool flag = true;
	long long T = a[2] - a[1];
	for (int i = 2; i <= n; i++) 
		if (a[i] - a[i - 1] != T) flag = false;
	if (flag) {
		for (int i = 1; i < n; i++) 
			if (m >= (a[i + 1] - a[i]) * (long long)i)
				ret++, m -= (a[i + 1] - a[i]) * (long long)i;
		cout << ret;
		return 0;
	}
	for (int i = 1; i < n; i++) 
		if (m >= (a[i + 1] - a[i]) * (long long)i) 
			ret++, m -= (a[i + 1] - a[i]) * (long long)i;
	m = M;
	int posa, posb;
	long long minn = 1e18;
	for (int i = 1; i < n; i++) {
		if (minn > a[i + 1] - a[i]) {
			posa = i + 1, posb = i;
			minn = a[i + 1] - a[i];
		}
	}
	swap(a[1], a[posb]);
	swap(a[2], a[posa]);
	if (minn == m) {
		cout << 2;
		return 0;
	}
	if (minn > m) {
		cout << 1;
		return 0;
	}
	m -= minn;
	M = m;
	int cnta = 2, cntb = 2;
	for (int i = 3; i <= n; i++) {
		long long minn = 1e12;
		int pos;
		for (int j = i; j <= n; j++)
			if (minn > abs(a[j] - a[i - 1])) 
				minn = abs(a[j] - a[i - 1]), pos = j;
		swap(a[i], a[pos]);
		long long tot = abs(a[i] - a[i - 1]) * (long long)(i - 1);
		if (m < tot) break;
		else m -= tot;
		cnta++;
	}
	m = M;
	swap(a[1], a[2]);
	for (int i = 3; i <= n; i++) {
		long long minn = 1e18;
		int pos;
		for (int j = i; j <= n; j++)
			if (minn > abs(a[j] - a[i - 1])) 
				minn = abs(a[j] - a[i - 1]), pos = j;
		swap(a[i], a[pos]);
		long long tot = abs(a[i] - a[i - 1]) * (long long)(i - 1);
		if (m < tot) break;
		else m -= tot;
		cntb++;
	}
	cout << ret << " " << cnta << " " << cntb;
	return 0;
}
