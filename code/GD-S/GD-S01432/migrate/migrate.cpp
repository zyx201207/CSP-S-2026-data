#include <bits/stdc++.h>

using namespace std;

const int N = 2e6 + 5;

long long a[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	int c, t;
	cin >> c >> t ;
	
	if(c == 11 || c == 12) {
		while(t--) {
			int n;
			unsigned long long d;
			cin >> n >> d ;
			if(n <= 2) {
				cout << 0 << endl ;
				continue;
			}
			for(int i = 1;i <= n;i++) {
				cin >> a[i] ;
			}
			long long x = a[2] - a[1];
			if(d <= x) {
				cout << 0 << endl ;
				continue;
			} 
			
			int m = d / x;
			
			long long ans = 0;
			for(int i = 1;i < n - m;i++) {
				if(i + 2 * m > n) {
					ans += (n - i - m);
				} else {
					ans += m - 1;
				}
			}
			cout << ans << endl ;
		}
	} else if(c == 13 || c == 14) {
		while(t--) {
			int n;
			long long d;
			cin >> n >> d ;
			if(n <= 2) {
				cout << 0 << endl ;
				continue;
			}
			int x = 0;
			bool f = 0;
			for(int i = 1;i <= n;i++) {
				cin >> a[i] ;
				if(a[i] - a[1] > d && !f) {
					f = 1;
					x = i - 1;
				}
			}
			
			int l = 1;
			for(;l < x;l++) {
				if(a[l] + d >= a[x + 1]) break;
			}
			int r = x + 1;
			for(;r <= n;r++) {
				if(a[r] <= a[x - 1] + d) break;
			}
			
			cout << l * (n - r) << endl ;
		}
	} else {
		while(t--) {
			cout << 0 ;
		}
	}
	
	return 0;
}
