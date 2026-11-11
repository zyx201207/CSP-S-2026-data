#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e5;
int a[N];
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	sort(a, a + n);
	
	cout << m / (a[1] - a[0]);
	return 0;
} 
