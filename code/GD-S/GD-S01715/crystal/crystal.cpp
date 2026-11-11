#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ri register int
#define rep(i,l,r) for(ri i=l;i<=r;i++)
#define per(i,r,l) for(ri i=r;i>=l;i--)
#define inl inline
int n, m;
#define N 500005
int a[N];
int s[N];
int ans = 1;
signed main(){
  freopen("crystal.in","r",stdin);
  freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n >> m;
	rep(i, 1, n) cin >> a[i];
	sort(a + 1, a + 1 + n);
	int l = 1, r = 1, cnt = 0, tot = 0, maxn = -1e18;
	maxn = a[1];
	rep(i, 2, n){
		while(l <= r && m < abs(a[i] - maxn) * (r - l + 1) + cnt) cnt -= maxn - a[l ++];
		cnt += abs(a[i] - maxn) * (r - l + 1);
		r ++;
		ans = max(ans, r - l + 1);
		maxn = a[i];
//		cout << l << " " << r << " " << ans << " " << maxn << endl;
	}
	cout << ans;
	return 0;
}

