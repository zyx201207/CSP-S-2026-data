#include <bits/stdc++.h>
using namespace std;
#define eb emplcae_back
typedef long long ll;
typedef pair<int, int> pii;

#define file(a) freopen(#a ".in", "r", stdin), freopen(#a ".out", "w", stdout)

const int N = 5e5 + 5;
int n; ll m, a[N], s[N];

int main() {
	file(crystal);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		s[i] = s[i - 1] + a[i];
		int l = 1, r = i, pos = 0;
		while(l <= r) {
			int mid = l + r >> 1;
			ll t = (i - mid) * a[i] - s[i - 1] + s[mid - 1];
			if(t <= m) pos = mid, r = mid - 1;
			else l = mid + 1; 
		} ans = max(ans, i - pos + 1);
	} cout << ans << endl;
	return 0;
} /*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/
