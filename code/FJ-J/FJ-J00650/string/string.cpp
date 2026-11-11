#include<bits/stdc++.h>
#define int long long
using namespace std;

const int max_n = 1e6 + 5;

int n, ans = 0;
int a[max_n];
char b[max_n];

signed main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> b[i];
	}
	
	int i = 1, j = n;
	
	while (i < j) {
		if (a[i] < a[j]) {
			if (b[i] != b[j]) ans += a[i];
			a[j] -= a[i];
			i++;
		}
		else {
			if (b[i] != b[j]) ans += a[j];
			a[i] -= a[j];
			j--;
		}
	}
	
	cout << ans;
	
	return 0;
}