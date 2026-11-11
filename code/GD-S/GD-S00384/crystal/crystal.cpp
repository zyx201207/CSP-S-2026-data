#include <bits/stdc++.h>
// #define int long long
// #define lson (id << 1)
// #define rson (id << 1 | 1)
#define endl '\n'

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

constexpr int N = 5e5 + 5;
constexpr int INF = 1e9;
constexpr ll INFF = 1e18;

int n;
ll m, a[N], s[N];

bool check(int mid) {
	for (int i = mid; i <= n; i ++) {
		if (a[i] * (mid - 1) - (s[i - 1] - s[i - mid]) <= m) return 1;
	}
	return 0;
}

signed main()
{
     freopen("crystal.in", "r", stdin);
     freopen("crystal.out", "w", stdout);
     ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++)
        s[i] = s[i - 1] + a[i];
    int l = 1, r = n, res = 0;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (check(mid))
            l = mid + 1, res = mid;
        else
            r = mid - 1;
    }
    cout << res << endl;
    return 0;
}
