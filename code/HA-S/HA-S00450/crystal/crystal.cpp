#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N = 5e5 + 5;

int n;
ll m, a[N];
__int128 s[N];

int main() {
	cin.tie(0) -> sync_with_stdio(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) cin >> a[i];
	sort(a + 1, a + n + 1);
	int ans = 0;
	for (int i = 1; i <= n; i ++) {
		s[i] = s[i - 1] + a[i];
		int l = 1, r = i, mid = 0;
		while (l < r) {
			mid = l + (r - l) / 2;
			if ((__int128)(a[i]) * (i - mid + 1) - (s[i] - s[mid - 1]) > m) l = mid + 1;
			else r = mid; 
		}
//		cout << l << " ";
		ans = max(ans, i - l + 1);
	}
	cout << ans << "\n";
	
	return 0;
}

