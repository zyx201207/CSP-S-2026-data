#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 10;
int a[N];
bool cmp(const int x, const int y) {
	return x > y; 
}

signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
  sort(a, a + n, cmp);
  
  int ans = a[0];
  for (int i = 1; i < m; i++) {
  	ans = ans & a[i];
	}
	
	cout << ans;
	return 0;
} 
