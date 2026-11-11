#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 5;
int a[N], n, m, ans;
bool check(int x){
	int cnt = 0;
	for(int i = 1; i <= n; i++)
		cnt += ((a[i] & x) == x);
	return cnt >= m;
}
signed main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 31; i >= 0; i--){
		int cnum = (ans | (1 << i));
		if(check(cnum)) ans = cnum;
	}
	cout << ans << endl;
	return 0;
}
