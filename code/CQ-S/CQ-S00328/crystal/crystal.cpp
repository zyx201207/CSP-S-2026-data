#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 5;
int a[N];
int n, m, val;
int sum[N];
bool check(int l, int r) {
	int num = sum[r] - sum[l - 1];
	int need = (r - l + 1) * val - num;
	return need <= m;
}
int solve(int pos) {
	int l = 1, r = pos;
	int res = pos;
	while(l <= r) {
		int mid = (l + r) >> 1;
		if(check(mid, pos)) {
			res = mid;
			r = mid - 1;
		} 
		else l = mid + 1;
	}
	return res;
}
signed main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		sum[i] = sum[i - 1] + a[i];
		val = a[i];
		int pos = solve(i);
//		cout << i <<" " << pos << '\n';
		ans = max(ans, i - pos + 1);
	}
	cout << ans << '\n';
}
