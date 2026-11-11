#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a[200005];
char c[200005];

int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, h = 1, t;
    ll ans = 0;
    cin >> n;
    t = n;
    for (int i = 1; i <= n; i++) cin >> a[i] >> c[i];
    while (h < t)
    {
        if (c[h] != c[t]) ans += min(a[h], a[t]);
        if (a[h] > a[t]) a[h] -= a[t--];
        else if (a[h] < a[t]) a[t] -= a[h++];
        else h++, t--;
    }
    cout << ans;
}