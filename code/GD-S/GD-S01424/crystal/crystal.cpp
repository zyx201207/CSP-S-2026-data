#include<bits/stdc++.h>
using namespace std;
#define int long long
int n, m, a[500005], cnt, ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for(int i = 1;i <= n;i ++){
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	int l = 1, r = 1;
	ans = 1;
	while(r <= n){
		r ++;
		if(a[r] != a[r - 1]){
			cnt += (a[r] - a[r - 1]) * (r - l);
			while(cnt > m) cnt -= (a[r] - a[l]), l ++;
		}
		ans = max(ans, r - l + 1);
	}
	cout << ans << "\n";
	return 0;
}
