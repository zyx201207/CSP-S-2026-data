#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 5;
long long n, m, ans;
int a[N], s[N];
bool ok(int p, int i){
	int len = i - p + 1;
	int sum = s[i] - s[p-1];
	return a[i] * len - sum <= m;
}
signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin.tie(nullptr) -> sync_with_stdio(false);
	cin >> n >> m;
	for(int i=1; i<=n; i++) cin >> a[i];
	sort(a + 1, a + 1 + n);
	for(int i=1; i<=n; i++){
		s[i] = s[i-1] + a[i];
		int l = 0, r = i;
		while(l + 1 < r){
			int mid = (l + r) >> 1;
			if(ok(mid, i)) r = mid;
			else l = mid;
		}
		ans = max(ans, i - r + 1);
	}
	cout << ans;
	return 0;
}

