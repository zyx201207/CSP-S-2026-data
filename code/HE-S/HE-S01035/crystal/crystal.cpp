#include <bits/stdc++.h>
#define int long long
using namespace std;

const int Inf = 1e18;

int n, m, ans;
vector<int> a;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    cin >> n >> m;
    a.resize(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a.begin() + 1, a.end());
    int cur = a[1], k = 0;
	for (int i = 1, j = 1; i <= n; i++) {
		k += (i - j) * (a[i] - cur);
    	cur = a[i];
		while (j < i && k > m) {
			k -= (cur - a[j]);
			j++;
		}
		ans = max(ans, i - j + 1);
	}
    cout << ans << '\n';

    return 0;
}

/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/ 
