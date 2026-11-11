#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int maxn = 5e5+10;
ll a[maxn];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	int n; ll m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	
	int j = n; ll c = 0; int ans = 1;
	for(int i = n-1; i >= 1; i--) {
		c += a[j] - a[i];
		while(c > m) {
			c -= (j - i) * (a[j] - a[j-1]);
			j--;
		}
		ans = max(ans, j - i + 1);
	}
	
	cout << ans << "\n";
	return 0;
}
