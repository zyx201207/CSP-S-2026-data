#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAX = 5e5 + 5;
int n, m;
int a[MAX];
bool check(int k){
	int diff = 0;
	for(int i = 1; i <= k; i++) diff += a[k] - a[i];
	if(diff <= m) return true;
	for(int i = k + 1; i <= n; i++){
		diff += (a[i] - a[i - 1]) * k;
		diff -= (a[i] - a[i - k]);
		if(diff <= m) return true;
	}
	return false;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + 1 + n);
	int l = 1, r = n, ans;
	while(l <= r){
		int mid = (l + r) / 2;
		if(check(mid)) l = mid + 1, ans = mid;
		else r = mid - 1;
	}
	cout << ans << '\n';
	return 0;
}
