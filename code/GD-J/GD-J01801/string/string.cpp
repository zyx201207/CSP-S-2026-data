#include <bits/stdc++.h>
using namespace std;
const int num = 200005;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	long long a[num];
	long long c[num];
	long long d[num];
	for (int i=1; i<=n; i++) {
		cin >> a[i] >> c[i];
		for (int p=1; p<=c[i]; p++) {
			d[p] = a[i];
		}
	}
	long long b[num];
	int m=1;
	for (int j=n; j>=1; j--) {
		b[j] = d[m];
		m++;
	}
	int cnt=0;
	for (int k=1; k<=n; k++) {
		if (b[k] != d[k]) {
			cnt++;
		}
	}
	cout << cnt;
	
	return 0;
}
 
