#include <bits/stdc++.h>
using namespace std;
long long a[200005];
char s[200005];
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	long long n;
	cin >> n;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i] >> s[i];
	}
	long long ans = 0;
	long long n1 = n;
	for (int i = 1; i <= n1;) {
		if(s[i] != s[n1]) {
			long long m = min(a[i], a[n1]);
			ans += m;
			if (a[i] > a[n1]) {
				a[i] -= a[n1];
				n1 --;
			} else {
				a[n1] -= a[i];
				i ++;
			} 
		} else {
			i ++;
			n1 --;
		}
		
	}
	cout << ans << endl;
	return 0;
}
