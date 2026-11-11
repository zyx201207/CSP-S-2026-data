#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5+5;
int n, m, ans, a[N], s[N];
signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a+1, a+n+1);
	for(int i = 1; i <= n; i++) s[i] = s[i-1]+a[i];
	int l = 1, r = 1;
	while(r <= n){
		while(a[r]*(r-l+1)-(s[r]-s[l-1]) > m) l++;
		if(a[r]*(r-l+1)-(s[r]-s[l-1]) <= m && l <= r) ans = max(ans, r-l+1);
		r++;
	}
	cout << ans;
	return 0;
} 
