#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;

typedef long long ll;

ll m;
int n;
ll a[N];

bool cmp(ll x, ll y)
{
    return x <= y;
}

int main()
{
    freopen ("crystal.in", "r", stdin);
    freopen ("crystal.out", "w", stdout);

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    sort(a+1, a+n+1, cmp);

    int cnt = 1;

    while (m > 0)
    {
        if (cnt == n)
            break;

        if (m < cnt * (a[cnt+1] - a[cnt]))
            break;

        m -= cnt * (a[cnt+1] - a[cnt]);

        a[cnt] = a[cnt+1];

        for (int i = cnt; i <= n; i++)
        {
            if (a[cnt+1] != a[cnt])
                break;
            
            cnt++;
        }
    }

    cout << cnt;

    return 0;
}