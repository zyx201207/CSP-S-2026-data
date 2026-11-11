#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
typedef long long ll;

ll n, m, a[500005], s[500005], ans=0;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	cin >> n >> m;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
	}
	sort(a+1, a+n+1);
	for (int i=1; i<=n; i++) {
		s[i] = a[i] + s[i-1];
	}
	for (int i=1; i<=n; i++) {
		for (int j=i; j<=n; j++) {
			if (s[j]-s[i-1]+m>=a[j]*(j-i+1)) ans = max(ans, 1ll+j-i);
		}
	}
	
	cout << ans;
	
	return 0;
}

