#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int N = 2e6 + 10;

ll func(){
	ll x, f = 0;
	char c = getchar();
	while (c < 0 || c > 9){
		if (c == '-'){
			f = -1;
			c = getchar();
		}
	}
	while (c >= '0' && c <= '9'){
		x = (x << 3) + (x << 1) + int(c - '0');
		c = getchar();
	}
	cout << endl;
	return x * f;
	
}
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c, t, n;
	cin >> c >> t;
	if (c != 0 && c != 11 && c != 12) return 0;
	while (t != 0){
		ll a, b, d, ans = 0;
		cin >> n >> d >> a >> b;
		a = func();
		b = func();
		ll len = b - a;
		for (int i = 3; i <= n; i++){
			a = func();
		}
		int cnt = d / len;
		if (cnt <= 1 || cnt * 2 > n){
			cout << 0;
			continue;
		}
		ans = n - cnt * 2 + 1;
		cout << ans;
		t--;
	}
	
	return 0;
}
