#include<iostream>
using namespace std;
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n, a[200005];
	char c[200005];
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i] >> c[i];
	int h = 1, t = n;
	long long ans = 0;
	while(h <= t) {
		if(a[h] > a[t]) {
			if(c[h] != c[t]) ans += a[t];
			a[h] -= a[t];
			t--;
		} else if(a[h] < a[t]) {
			if(c[h] != c[t]) ans += a[h];
			a[t] -= a[h];
			h++;
		} else {
			if(c[h] != c[t]) ans += a[h];
			h++;
			t--;
		}
	}
	cout << ans << "\n";
	return 0;
} 
