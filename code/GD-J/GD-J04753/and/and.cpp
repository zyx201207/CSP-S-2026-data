#include <bits/stdc++.h>

#define int long long 

using namespace std;
const int N = 2e5 + 10; 
int n, m, a[N], ans;
void dfs (int p, int x, int val) {
	if (x == m) {
	   ans = max (ans, val);
	   return;
	}
	if (p == n) return;
	dfs (p + 1, x + 1, val & a[p + 1]);
	dfs (p + 1, x, val);
}
signed main() {
	
	freopen ("and.in", "r", stdin);
	freopen ("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	if (n <= 20) {
	   for (int i = 1; i <= n - m + 1; i++)
	       dfs (i, 1, a[i]);
	   cout << ans;
	} else {
	   if (m == 1) {
	   	  for (int i = 1; i <= n; i++) ans = max (ans, a[i]);
	   	  cout << ans;
	   }
	   if (m == 2) {
	   	  for (int i = 1; i <= n; i++)
	   	    for (int j = 1; j <= n; j++)
	   	        if (i != j) ans = max (ans, a[i] & a[j]);
	   	  cout << ans;
	   }
	   if (m == n - 1) {
	   	  for (int i = 1; i <= n; i++) {
	   	  	int sum = -114514;
	   	  	for (int j = 1; j <= n; j++) {
	   	  		 if (i == j) continue;
	   	        if (sum == -114514) sum = a[j];
	   	        else sum &= a[j];
			}
			ans = max (ans, sum); 
		  }   
		  cout << ans;
	   }
	   if (m == n) {
	   	  ans = a[1];
	   	  for (int i = 2; i <= n; i++) ans &= a[i];
	   	  cout << ans;
	   }
	}
	return 0;
}
