#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 10;
int a[N], n, sum[N], m;
bool check(int x){
	for(int i = 1; i + x - 1 <= n; i++){
		int nmx = a[i + x - 1];
		if(nmx * x - (sum[i + x - 1] - sum[i - 1]) <= m) return 1;
	}
	return 0;
}
signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];

	sort(a + 1, a + 1 + n);
	for(int i = 1; i <= n; i++) sum[i] = a[i] + sum[i - 1];
	int tl = 1, tr = n, ans = 1;
	while(tl <= tr){
		int tm = (tl + tr) / 2;
		if(check(tm)) tl = tm + 1, ans = tm;
		else tr = tm  - 1;
	} 
	cout << ans;
}
