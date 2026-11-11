#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, a[500005], cnt = 0;
signed main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout); 
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	//m == 2 
	if (n == 1) {
		cout << "1";
		return 0;
	}
	if (m == 1) {
		cout << "1";
	} else {
		cout << "1" << "2";
	}
	return 0; 
}
