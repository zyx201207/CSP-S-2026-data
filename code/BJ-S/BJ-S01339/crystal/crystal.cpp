#include <bits/stdc++.h>
#include <cassert>

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;

using namespace std;

const int MAXN = 5e5 + 10;

int n; ll m, a[MAXN];

int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    ll s = 0; int mx = 1;
    for (int l = 1, r = 1; r <= n; r++)
    {
        s += a[r];
        while (l < r && a[r] * (r - l + 1) - s > m) s -= a[l++];
        mx = max(mx, r - l + 1);
    }
    cout << mx << "\n";
    return 0;
}