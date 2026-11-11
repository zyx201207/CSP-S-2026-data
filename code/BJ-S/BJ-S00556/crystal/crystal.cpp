#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN = 5e5 + 5;

int n, ans; ll m;
ll a[MAXN], s[MAXN];

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i=1; i<=n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i=1; i<=n; i++) s[i] = s[i - 1] + a[i];
	for (int i=1; i<=n; i++){
		int l = 1, r = i, res = 0;
		while (l <= r){
			int mid = (l + r) / 2;
			ll w = 1ll * (i - mid + 1) * a[i] - (s[i] - s[mid - 1]);
			if (w <= m) res = mid, r = mid - 1;
			else l = mid + 1;
		}
		ans = max(ans, i - res + 1);
	}
	cout << ans << "\n";
	return 0;
}