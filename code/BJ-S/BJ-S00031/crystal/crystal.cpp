#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 5e5 + 7;
int n, ans;
ll m, a[N], pre[N];

int main(){
	ios::sync_with_stdio(false);
	freopen("crystal.in", "r", stdin); freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; ++i) cin >> a[i];
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; ++i) pre[i] = pre[i-1] + a[i];
	for(int i = 1; i <= n; ++i){
		int l = 1, r = i, mid, res = i;
		while(l <= r){
			mid = l + r >> 1;
			if(1ll * (i - mid + 1) * a[i] - (pre[i] - pre[mid - 1]) <= m) r = mid - 1, res = mid;
			else l = mid + 1;
		}
		ans = max(ans, i - res + 1);
	}
	cout << ans << "\n";
	return 0;
}