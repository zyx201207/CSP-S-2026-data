#include<bits/stdc++.h>
#define endl '\n'
#define pi pair<int, int>
#define ll long long

using namespace std;
const int N = 2e5 + 10;
const int L = 35;
int n, m;
bool a[N][L], f[N];

int main() {
  	freopen("and.in", "r", stdin);
  	freopen("and.out", "w", stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n >> m;
	int mal = 0;
	for (int i = 1; i <= n; i++) {
		ll x;
		cin >> x;
		for (int j = 1; j < L; j++)
			if (x & (1ll << (j - 1))) a[i][j] = true, mal = max(mal, j);
	}
//	for (int i = 1; i <= n; i++, cout << endl)
//		for (int j = 1; j <= mal; j++)
//			cout << a[i][j] << " ";
	memset(f, true, sizeof f);
	ll ans = 0;
	for (int bit = mal; bit >= 1; bit--) {
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (!f[i]) continue;
			if (a[i][bit]) cnt++;
		}
		if (cnt >= m) {
			ans += (1ll << (bit - 1));
			for (int i = 1; i <= n; i++)
				if (f[i] == true && a[i][bit] == false)
					f[i] = false;
		}
	}
	cout << ans << endl;
	return 0;
}
/*
4 2
3 15 12 12
5 3
31 3 1 15 7
*/
