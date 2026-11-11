#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5;

int n, m;
int a[N] = {};
bool flg[N] = {};

void solve(){
	cin >> n >> m;
	for (int i = 1;i <= n;i ++) cin >> a[i];
	int ans = 0;
	for (int i = 30;i >= 0;i --){
		int cnt = 0;
		for (int j = 1;j <= n;j ++){
			if (!flg[j] && (a[j] & (1 << i))) cnt ++;
		}
		if (cnt < m) continue;
		for (int j = 1;j <= n;j ++){
			if (!flg[j] && !(a[j] & (1 << i))) flg[j] = true;
		}
		ans |= (1 << i);
	}
	cout << ans << "\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int t = 1;
	// cin >> t;
	while (t --){
		solve();
	}
	return 0;
}
/*
5 3
31 3 1 15 7
*/ 
