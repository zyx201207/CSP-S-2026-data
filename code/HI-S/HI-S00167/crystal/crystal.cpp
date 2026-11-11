#include<bits/stdc++.h>
using namespace std;
#define ll long long 

int const N = 5e5 + 5;
int n, m, a[N], s[N], ans;

int calc(int k, int i) {
	return a[k] * (k - i + 1) - (s[k] - s[i - 1]);
}

int bound(int k) {
	int l = 1, r = k, mid, ans = k;
	while(l <= r) {
		mid = (l + r) >> 1;
		if(calc(k, mid) <= m) r = mid - 1, ans = mid;
		else l = mid + 1;
	}
	return k - ans + 1;
}

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + 1 + n);
	for(int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
	for(int i = 1; i <= n; i++) ans = max(ans, bound(i));
	cout << ans;
	return 0;
}

