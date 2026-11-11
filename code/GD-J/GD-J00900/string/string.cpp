#include <bits/stdc++.h>
using namespace std;
int a[200005];
char c[200005];
string s;
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	long long sum = 0;
	for(int i = 1; i <= n; i ++) {
		cin >> a[i] >> c[i];
		sum += a[i]; 
	}
	long long ans = 0;
	if(sum <= 1e8) {
		for(int i = 1; i <= n; i ++) {
			for(int j = 1; j <= a[i]; j ++) {
				s += c[i];
			}
		}
		s = ' ' + s;
		for(int i = 1; i <= (sum + 1) / 2; i ++) {
			if(s[i] != s[sum - i + 1]) ans ++;
		}
		cout << ans;
	} else {
		long long i = 0, j = n;
		while(i != j && abs(i - j) != 1) {
			if(c[i] == c[j]) {
				if(a[i] == a[j]) {
					i ++;
					j --;
				} else if(a[i] > a[j]) {
					a[i] -= a[j --];
				} else {
					a[j] -= a[i ++];
				}
			} else {
				if(a[i] == a[j]) {
					ans += a[i];
					c[i] = c[j];
				} else if(a[i] > a[j]) {
					ans += a[j];
					a[i] -= a[j];
					j --;
				} else {
					ans += a[i];
					a[j] -= a[i];
					i ++;
				}
			}
		}
		cout << ans;
	}
	return 0;
}
