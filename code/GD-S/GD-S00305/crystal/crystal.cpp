#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e5 + 7;
int n, m, a[N], s[N];

int sum(int l, int r){
	return s[r] - s[l - 1];
}

signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i ++) cin >> a[i];
	sort(a + 1, a + n + 1);
	
	for(int i = 1; i <= n; i ++) s[i] = s[i - 1] + a[i];
	int ans = 0;
	
	for(int i = 1, j = 1; i <= n; i ++){
		while(j <= i && a[i] * (i - j + 1) - sum(j, i) > m) j ++;
		ans = max(ans, i - j + 1);
	}
	cout << ans << "\n";
	
	return 0;
}

