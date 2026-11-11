//Òª¼ÇµÃÐ´ 
//freopen(" .in", "r", stdin);
//freopen(" .out", "w", stdout);

#include <bits/stdc++.h>
using namespace std;

int n, m, ans;
int a[200005];

int main() {
	
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	cin >> n >> m;
	for (int i=1;i<=n;i++) {
		cin >> a[i];
	}
	if (m == 1) {
		for (int i=1;i<=n;i++) {
			ans = max(ans, a[i]);
		}
	}
	else if (m == 2) {
		for (int i=1;i<=n;i++) {
			for (int j=1;j<=n;j++) {
				if (i != j) {
					ans = max(ans, a[i] & a[j]);
				}
			}
		}
	}
	else if (m == n) {
		for (int i=1;i<=n;i++) {
			ans = ans & a[i];
		}
	}
	else {
		for (int i=1;i<=n;i++) {
			ans = max(ans, a[i]);
		}
	}
	cout << ans;
	
	return 0;
} 
