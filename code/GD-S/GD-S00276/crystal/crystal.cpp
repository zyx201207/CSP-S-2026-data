#include<bits/stdc++.h> 
#define int long long
#define f(i, s, e) for(int i = s; i <= e; ++i)
#define dw(i, e, s) for(int i = e; i >= s; --i)
#define pii pair<int, int>
using namespace std;

int n, m, a[500005], ans, s[500005];

int cl(int l, int r){
	return a[r] * (r - l + 1) - (s[r] - s[l - 1]);
}

signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	f(i, 1, n) cin >> a[i];
	sort(a+1, a+n+1);
	f(i, 1, n) s[i] = s[i - 1] + a[i];
	int l = 1, r = 1, sum = 0;
	while(r <= n){
		while(cl(l, r) > m && l <= r) ++l;
		while(cl(l, r + 1) <= m && r < n) ++r;
		ans = max(r - l + 1, ans);
		++r;
	}
	cout << ans;
	return 0;
}
