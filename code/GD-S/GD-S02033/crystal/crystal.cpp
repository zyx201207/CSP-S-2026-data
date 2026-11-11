#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 500010;
int a[N], sum[N], n, m;
bool duan(int l, int r) {
	int num = r - l;
	int shu1 = num * a[r];
	int shu2 = sum[r - 1] - sum[l - 1];
	if(shu1 - shu2 <= m) return true;
	return false;
}
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int ans = 1; cin >> n >> m;
	for(int i = 1;i <= n;i ++) cin >> a[i];
	sort(a + 1, a + 1 + n);
	for(int i = 1;i <= n;i ++) sum[i] = sum[i - 1] + a[i];
	for(int i = 2;i <= n;i ++) {
		int l = 1, r = i, mid = i;
		while(l < r) {
			mid = (l + r) / 2;
			if(r - l == 1) {
				if(duan(l, i)) mid = l;
				else mid = r;
				break;
			} else if(duan(mid, i)) r = mid;
			else l = mid;
			//cout << l << " " << r << endl;
		}
		//cout << mid << " " << i << endl;
		ans = max(ans, i - mid + 1);
	}
	cout << ans << endl;
	return 0;
}
