#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
	int n, m;
	cin >> n >> m;
	vector<int> a(n + 1), pre(n + 1);
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a.begin() + 1, a.end());
	for(int i = 1; i <= n; i++) pre[i] = pre[i - 1] + a[i];
	int ans = 0;
	for(int i = 1; i <= n; i++){
		int lo = 1, hi = i, t;
		while(lo <= hi){
			int mid = (lo + hi) >> 1;
			if((i - mid + 1) * a[i] - (pre[i] - pre[mid - 1]) <= m){
				hi = mid - 1;
				t = mid;
			}
			else lo = mid + 1;
		}
		ans = max(ans, i - t + 1);
	}
	cout << ans << '\n';
}

signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T = 1;
	while(T--) solve();
	return 0;
}
