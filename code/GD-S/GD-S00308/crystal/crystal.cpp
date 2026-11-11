#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 5;
int s[N], a[N], n, m, ans;
int se(int x){
	int l = 0, r = x - 1, ans;
	while(l <= r){
		int mid = (l + r) >> 1;
		if(a[x] * (x - mid) - (s[x] - s[mid]) <= m){
			ans = mid;
			r = mid - 1;
		}else l = mid + 1;
	}
	return ans;
}
signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
	for(int i = 1; i <= n; i++){
		int pos = se(i);
		ans = max(ans, i - pos);
	}
	cout << ans << endl;
	return 0;
}
