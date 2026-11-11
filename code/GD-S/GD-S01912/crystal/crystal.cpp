#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 5;
int n, m, a[N], cnt[N];
bool check(int x){
	for(int i = x; i <= n; i++){
		if(a[i] * x - cnt[i] + cnt[i - x] <= m) return 1;
	}
	return 0;
}
signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++) cnt[i] = cnt[i - 1] + a[i];
	int l = 0, r = n, mid;
	while(l <= r){
		mid = (l + r) >> 1;
		if(check(mid)) l = mid + 1;
		else r = mid - 1;
	}
	cout << l - 1;
	return 0;
}
//二分答案+贪心？ 
//22min过了大样例，应该没啥事 
