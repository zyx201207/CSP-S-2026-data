//GZ-S00022 云岩区实验中学 向子睿 
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 500010, inf = 0x3f3f3f3f3f3f3f3fll;
int n, m, a[maxn], ans, l, r, c;

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)cin >> a[i];
	sort(a+1, a+1+n);
	l = 1, r = 1;
	while(r <= n){
		while(l <= r && c > m){
			c -= a[r] - a[l];
			l++;
		}ans = max(ans, r - l + 1);
		c += (r - l + 1) * (a[r+1] - a[r]);
		r++;
	}cout << ans;
	return 0;
}
