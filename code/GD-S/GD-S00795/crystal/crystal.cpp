#include <bits/stdc++.h>
using namespace std;

long long a[500010];
int n;
long long b[500010];
long long m;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	bool A = true;
	bool B = true;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		if(a[i] != i) A = false;
		int s = a[2] - a[1];
		if(i >= 3) {
			if(a[i] - a[i - 1] != s) B = false;
		}
	}
	if(A) {
		long long cnt = 0, op = 0;
		int mid = (1 + n) >> 1;
		long long id = 0;
		for(int i = 1; i <= n; i++) {
			id += abs(a[i] - a[mid]);
		}
		if(m >= id) {
			cout << n;
		} else {
			while(m > 0) {
				if(op % 2 == 0) {
					cnt++;
				}
				op++;
				m -= cnt;
			}
			cout << op + 1;
		}
		return 0;
	}
	
	if(B) {
		int k = a[2] - a[1];
		int mid = (1 + n) >> 1;
		long long id = 0;
		int l = mid - 1, r = mid + 1;
		for(int i = 1; i <= n; i++) {
			id += abs(a[i] - a[mid]);
			if(id > m) break;
		}
		if(m >= id) {
			cout << n;
		} else {
			int op = 0;
			while(m > 0) {
				if(op % 2 == 1) {
					if(m - abs(a[l] - a[mid]) >= 0) m -= abs(a[l] - a[mid]);
					else break;
					l--;
				} else {
					if(m - abs(a[r] - a[mid]) >= 0) {
						m -= abs(a[r] - a[mid]);
					}
					else break;
					r++;
				}
				op++;
			}
			cout << op + 1;
		}
		return 0;
	}
	
	sort(a + 1, a + n + 1);
	int mid = (1 + n) >> 1;
	long long id = 0;
	for(int i = 1; i <= n; i++) {
		id += abs(a[i] - a[mid]);
	}
	if(m >= id) {
		cout << n;
		return 0; 
	}
	for(int i = 1; i <= n; i++) {
		b[i - 1] = abs(a[i] - a[mid]);
	}
	sort(b, b + n);
	long long op = 0, cnt = 0;
	while(m > 0) {
		if(m - b[++cnt] >= 0) {
			m -= b[cnt];
			op++;
		} else break;
	}
	cout << op + 1;
	
	return 0;
}
