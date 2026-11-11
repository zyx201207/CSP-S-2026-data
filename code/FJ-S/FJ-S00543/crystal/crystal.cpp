// CCF LET ME AK CSP-S	
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 5e5 + 10;
int n;
LL m, a[N], c[N], s[N];
int ans = 0;
bool A = true, B = true;
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++) {
		cin >> a[i];
		if(a[i] != i) A = false;
		c[i] = a[i] - a[i - 1];
		if(i >= 3) {
			if(a[i] - a[i - 1] != a[i - 1] - a[i - 2]) {
				B = false;
			}
		}
	}
	
	if(n == 1) {
		cout << 1;
	}
	else if(n == 2){
		if(abs(a[2] - a[1]) <= m) 
			cout << 2;
		else
			cout << 1;
	}
	else if(A) {
		LL l = 1;
		while(m > l) {
			m -= l;
			l ++;
		}
		cout << l;
	}
	else if(B){
		LL l = a[2] - a[1], cha = a[2] - a[1];
		while(m > l) {
			m -= l;
			l += cha;
		}
		cout << l;
	}
	else {
		c[1] = 0;
		int timeing = 0;
		for(int i = 1; i <= n; i ++) 
			s[i] = s[i - 1] + c[i];
		for(int i = 1; i < n; i ++) {
//			for(int j = 1; j <= n; j ++) {
//				if(s[j] - s[i - 1] <= m)
//					ans = max(ans, j - i + 1);
//					
//			}
			int l = 1, r = n;
			while(l <= r) {
				int mid = l + (r - l) / 2;
				if(s[mid] - s[i - 1] <= m) {
					ans = max(ans, mid - i + 1);
					l = mid + 1;
				}
				else {
					r = mid - 1;
				}
			}
		}
		cout << ans;
	} 
	return 0;
} 
