#include <bits/stdc++.h>
using namespace std;
#define ll long long
void quickio()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
}
signed main()
{
    quickio();
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &a[i]);
    }
    sort(a.begin(), a.end());
    ll l = 0, r = 0, now = 0, ans = LLONG_MIN;
    while (l <= r)
    {
        if (r == n - 1)
        {
            break;
        }
        if (now >= m)
        {
            l++;
            if (l == r)
            {
                now = 0;
            }
        }
        else if (now < m)
        {
            r++;
            now += (r - l) * (a[r] - a[r - 1]);
            if (now <= m)
                ans = max(ans, r - l + 1);
        }
    }
    if (ans == LLONG_MIN)
    {
        cout << 1;
        return 0;
    }
    cout << ans;
    return 0;
}
/*
5 3
1 8 9 10 10 
 7 1 1  0
4

5 6
-3 -1 6 8 10

3

5 5 
1 2 4 8 9 
 1 2 4 1

3


5 5
-100 -50 1 4 5
    50  50 3 1
3

n^2logn

1 + 2 + 4 + 8 + 9 = 24 / 5 = 4.8  -> 4
-3 -1 + 2 + 2 + 7 = 7 / 5 = 1.4

5 8 
-3 -1 2 2 7
*/