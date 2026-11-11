#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 5;
int n,m,a[N],sum[N];
bool check(int k){
	for(int l = 1; l + k - 1 <= n; l++){
		int r = l + k - 1,tot = sum[r] - sum[l - 1];
		if(k * a[r] - tot <= m) return true;
	}
	return false;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1,a + n + 1);
	for(int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
	int l = 1,r = n,ans = 1;
	while(l <= r){
		int mid = (l + r) >> 1;
		if(check(mid)){
			ans = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	cout << ans << '\n';
	return 0;
}
