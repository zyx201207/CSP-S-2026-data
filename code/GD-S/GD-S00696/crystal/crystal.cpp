#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 500005;
int n, m, a[N], s[N];
bool chk(int x){
	int ans = 2e18;
	for(int i = 1; i <= n - x + 1; i++)
		ans = min(ans, a[i + x - 1] * x - (s[i + x - 1] - s[i - 1]));
	return ans <= m;
}
signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
	int l = 1, r = n;
	while(l < r){
		int mid = l + r + 1 >> 1;
		if(chk(mid)) l = mid;
		else r = mid - 1;
	}
	cout << l << '\n';
	return 0;
}
