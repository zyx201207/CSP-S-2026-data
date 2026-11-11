// Accepted? at 15:24
// difference:yellow
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 10;
int a[N], ans = 1, n, m, pre[N];
bool check(int x){
	for(int i = x; i <= n; i++){
		if((x - 1) * a[i] - (pre[i - 1] - pre[i - x]) <= m) return true;
		// i - x + 1 to i - 1
	}
	return false;
} 
signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	int minn = 9e18;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	} 
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++){
		if(i!=1)minn = min(minn, a[i] - a[i - 1]);
		pre[i] = pre[i - 1] + a[i];
	}
	if(minn > m){
		cout <<1;
		return 0;
	}
	int l = 1, r = n;
	while(l <= r){
		int mid = (l + r) >> 1;
		if(check(mid)) l = mid + 1, ans = mid;
		else r = mid - 1;
	}
	cout << ans;
}
