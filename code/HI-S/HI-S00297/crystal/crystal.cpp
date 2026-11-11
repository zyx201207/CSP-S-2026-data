#include <bits/stdc++.h>
#define int long long

using namespace std;

const int maxn = 5 * 1e5 + 5;
int n,m,a[maxn];
int pre[maxn];

signed main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(0),cin.tie(0);
	
	cin >> n >> m;
	for(int i = 1;i <= n;i ++) {
		cin >> a[i];
	}
	
	sort(a + 1,a + n + 1);
	for(int i = 1;i <= n;i ++) {
		pre[i] = pre[i - 1] + a[i];
	}
	
	int l = 1,ans = 1;
	for(int i = 1;i <= n;i ++) {
		while(a[i] * (i - l + 1) - pre[i] + pre[l - 1] > m) {
			l ++;
		}
		ans = max(ans,i - l + 1);
	}
	
	cout << ans << '\n';
	
	
	return 0;
}
