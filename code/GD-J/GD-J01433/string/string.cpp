#include<bits/stdc++.h>
using namespace std;
struct node {
	long long n;
	char c;
}a[2000010];
int n;
long long ans = 0;
int main () {
	freopen ("string.in" , "r", stdin);
	freopen ("string.out" , "w", stdout);
    cin >> n;
    long long k = 0;
    for (int i = 1; i <= n; i++) {
    	long long x;
    	cin >> x >> a[i].c;
    	k += x, a[i].n = x;
    }
    long long m = n / 2, l = 1, r = n;
    k = k / 2; 
    long long x = 0;
    while (x < k) {
    	if (a[l].c == a[r].c) {
    		if (a[l].n > a[r].n) {
    			a[l].n -= a[r].n, x += a[r].n, r--;
			} else if (a[l].n == a[r].n) {
				x += a[r].n, l++, r--;
			} else {
				a[r].n -= a[l].n, x += a[l].n, l--;
			}
		} else {
    		if (a[l].n > a[r].n) {
    			x += a[r].n, ans += a[r].n, a[l].n -= a[r].n, r--;
			} else if (a[l].n == a[r].n) {
				x += a[l].n, ans += a[l].n, l++, r--;
			} else {
				a[r].n -= a[l].n, x += a[l].n, ans += a[l].n, l--;
			}
		}
	}
	cout << ans;
	return 0;
} 
