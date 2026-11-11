#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long ll;

const int N = 5e5 + 100;

ll n, m;
ll a[N];

int main () {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);

	cin >> n >> m;
	for (int i = 1; i <= n; i ++ ) cin >> a[i];

	sort(a + 1, a + n + 1);
	
	int l = 1, mx = 1; ll now = m;
	for (int r = 1; r <= n; r ++ ) {
		if (r != 1 && a[r - 1] != a[r]) {
			while (now < (a[r] - a[r - 1]) * (r - l)) {
				now += (a[r - 1] - a[l]);
				l ++ ;
			}
			now -= (a[r] - a[r - 1]) * (r - l);
		}
		mx = max(mx, r - l + 1);
	}
	cout << mx << '\n';
	return 0;

}
