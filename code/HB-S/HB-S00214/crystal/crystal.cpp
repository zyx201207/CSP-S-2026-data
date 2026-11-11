#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;

using ll = long long;

ll n, m, a[N], perfix[N], res = 0;

int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    cin >> n >> m;

    for(int i = 1;i <= n;++ i)
    {
        cin >> a[i];
    }

    sort(a + 1, a + 1 + n);

    for(int i = 1;i <= n;++ i)
    {
        perfix[i] = perfix[i - 1] + a[i];
    }

    ll l = 0, r = 1;

    while(r <= n)
    {
        ll temp = a[r] * (r - l) - perfix[r] + perfix[l];
        if(temp <= m)
        {
            res = max(res, ll(r - l));
            r ++;
        }
        else
        {
            l ++;
        }
        if(l == r)
        {
            r ++;
        }
    }

    cout << res;

    return 0;
}
