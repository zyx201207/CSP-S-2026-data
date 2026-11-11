#include <bits/stdc++.h>
#define int long long

using namespace std;

int n;
const int N = 1E6 + 66;

int a[N], ans;
char c[N];

signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	cin >> n;
	for(int i = 1; i <= n; i ++) {
		cin >> a[i] >> c[i];
	}
	
	int l = 1, r = n;
	int nowl = a[1], nowr = a[n];
	
	while(l < r) {
		if(c[l] != c[r]) {
			if(nowl == nowr) {
				ans += nowl;
				l ++, r --;
				nowl = a[l], nowr = a[r]; 
			} else if(nowl < nowr) {
				ans += nowl;
				nowr -= nowl;
				l ++; nowl = a[l];
			} else {
				ans += nowr;
				nowl -= nowr;
				r --; nowr = a[r];
			}
		} else {
			if(nowl == nowr) {
				l ++, r --;
				nowl = a[l], nowr = a[r]; 
			} else if(nowl < nowr) {
				nowr -= nowl;
				l ++; nowl = a[l];
			} else {
				nowl -= nowr;
				r --; nowr = a[r];
			}
		}
	}
	
	cout << ans;
	return 0;
}
