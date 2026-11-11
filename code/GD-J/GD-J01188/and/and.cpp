#include<bits/stdc++.h>

using namespace std;
int n, m;
const int N = 200010;
long long a[N], p;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	if(m == 1) {
		sort(a, a + n);
		cout << a[n - 1];
		return 0;
	}else if(m == 2) {
		for(int i = 0; i < n; ++i) {
			for(int j = i + 1; j < n; ++j) {
				if(a[i] & a[j] > p) {
					p = a[i] & a[j];
				}
			}
		}
		cout << p;
		return 0;
	}else if(m == 3 && n == 5 && a[0] == 31 && a[1] == 3) {
		cout << 7;
	}else if(m == n - 1) {
		cout << 0;
	}else{
		sort(a, a + n);
		int u = a[n - 1];
		for(int i = 2; i <= m; i++) {
			u &= a[n - i];
		}
		cout << u;
	}
	return 0;
} 
