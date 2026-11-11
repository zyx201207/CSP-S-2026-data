#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
#define ll long long
int ans;
int a[N], s[N];
int main() {
	//freopen("crystal.in", "r", stdin);
	//freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	} 
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		s[i] = s[i - 1] + a[i];
	}	
	int l = 1, r = n;
	for (int i = n; i > 1; i--) {
		
	}
	cout << ans << '\n';
	return 0;
} 
