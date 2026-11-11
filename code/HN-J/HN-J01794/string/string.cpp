#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 2e5 + 5, K = 26 + 5;

int n, ans, L, a[N], sa[N], sum[N][K];
char c[N];
string st;

signed main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	for(int i = 1; i <= n; ++i){
		cin >> a[i] >> c[i];
		sa[i] = sa[i - 1] + a[i];
		L += a[i];
		for(int j = 0; j < 26; ++j){
			sum[i][j] = sum[i - 1][j] + (c[i] - 'a' == j) * a[i];
		}
	}
	for(int i = 1, s = 0; i <= n && s < L / 2; ++i){
		int l = L - min(s + a[i], L / 2) + 1, r = L - s;
		s += a[i];
		int x = lower_bound(sa + 1, sa + n + 1, l) - sa, y = lower_bound(sa + 1, sa + n + 1, r) - sa;
//		cout << i << ' ' << x << ' ' << y << '\n';
		if(x == y){
			if(c[x] == c[i]){
				ans += r - l + 1;
			}
			continue;
		}
		if(x < y){
			ans += sum[y - 1][c[i] - 'a'] - sum[x][c[i] - 'a'];
		}
		if(c[x] == c[i]){
			ans += sa[x] - l + 1;
		}
		if(c[y] == c[i]){
			ans += r - sa[y - 1];
		}
	}
	cout << (L / 2 - ans);
	return 0;
}

