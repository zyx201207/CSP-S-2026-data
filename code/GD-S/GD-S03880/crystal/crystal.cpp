#include<bits/stdc++.h>
#define int long long
#define N 500005
#define dbg(x) cerr<<#x<<" "<<x<<endl
using namespace std;
int n, m, a[N], pre[N], ans;
bool check(int L, int R){
	int sum = a[R] * (R - L + 1) - (pre[R] - pre[L - 1]);
	return sum <= m;
}
int bs(int R){
	int l = 1, r = R, ans = R;
	while(l <= r){
		int mid = (l + r) >> 1;
		if(check(mid, R)) r = mid - 1, ans = mid;
		else l = mid + 1;
	}
	return ans;
}
signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out","w", stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++) pre[i] = pre[i - 1] + a[i];
	for(int r = 1; r <= n; r++){
		int l = bs(r);
		ans = max(ans, r - l + 1);
	}
	cout << ans << endl;
	return 0;
}
