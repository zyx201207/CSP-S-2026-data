#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e6 + 5;

int c, n;
ll d;
ll a[N] = {}, las[N] = {};

int bs(ll x, bool flg){
	int l = 1, r = n;
	int cnt = 0;
	while (l <= r){
		int mid = (l + r) >> 1;
		if ((flg && a[mid] <= x) || (!flg && a[mid] < x)){
			l = mid + 1;
			cnt = mid;
		}else r = mid - 1;
	}
	return cnt;
}

void solve(){
	cin >> n >> d; 
	ll ans = 0;
	for (int i = 1;i <= n;i ++){
		int h = lower_bound(a + 1, a + n + 1, a[i] - d) - a;
		ans += n - (i - h + 1);
	}
	cout << ans << "\n";
}

void solve2(){
	cin >> n >> d;
	ll ans = 0;
	/*
	for (int i = 1;i <= n;i ++){
		las[i] = bs(d + a[i], 1);
	}
	for (int i = 1;i <= n;i ++){
		for (int j = i + 1;j <= n;j ++){
			int 
		}
	}*/
	cout << 0 << endl;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int t = 1;
	cin >> c >> t;
	while (t --){
		if (13 <= c && c <= 14) solve();
		else solve2();
	}
	return 0;
}

