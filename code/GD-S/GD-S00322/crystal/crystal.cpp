#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define unmp unordered_map
#define vc vector
const int N = 5e5 + 5;
ll a[N], n, res[N], sum[N], m;
int ans;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++) 
		sum[i] = sum[i - 1] + a[i];
	for (int i = 1; i <= n; i++) {
		int l = 1, r = i, mid, cnt;
		while (l <= r) {
			mid = (l + r) >> 1;
			if (1ll * mid * a[i] - (sum[i] - sum[i - mid]) <= m) {
				cnt = max(cnt, mid);
				l = mid + 1;
			}
			else
				r = mid - 1;
			ans = max(ans, cnt);
		}
	}
	cout << ans << endl;
	return 0;
}

