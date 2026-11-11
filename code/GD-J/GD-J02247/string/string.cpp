#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6 + 5;

int n, l;
char a[N] = {};

void solve(){
	cin >> n;
	int ind = 0;
	for (int i = 1;i <= n;i ++){
		char c; int x;
		cin >> x >> c;
		l += x;
		while (x --) a[++ ind] = c;
	}
	ll ans = 0;
	for (int i = 1;i <= (l >> 1);i ++){
		if (a[i] != a[l - i + 1]) ans ++;
	}
	cout << ans << "\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int t = 1;
	// cin >> t;
	while (t --){
		solve();
	}
	return 0;
}
/*
2
2 a
3 a
*/
