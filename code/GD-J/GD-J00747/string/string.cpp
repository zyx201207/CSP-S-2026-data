#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll len,ans;
int a[200005];
char c[200005];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
		len += a[i];
	}
	len /= 2;
	for(int i = 1, j = n; len > 0;) {
		if(a[i] >= a[j]) {
			if(c[i] != c[j]) ans += a[j];
			len -= a[j];
			a[i] -= a[j];
			j--;
		} else {
			if(c[i] != c[j]) ans += a[i];
			len -= a[i];
			a[j] -= a[i];
			i++;
		}
	}
	cout << ans << '\n';

	return 0; 
} 
