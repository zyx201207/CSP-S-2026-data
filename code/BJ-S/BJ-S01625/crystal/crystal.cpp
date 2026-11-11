#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000005;
long long a[MAXN];
long long d[MAXN];

int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long n, m;
    cin >> n >> m;

    for (long long i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    sort(a + 1, a + n + 1);

    for (long long i = 1; i <= n; i++)
    {
        d[i] = a[i] - a[i - 1];
    }

    long long ans = 0;
    for (long long i = 1; i <= n; i++)
    {
        m -= (i - 1) * 1ll * d[i];

        //ceshi
        //cout << m << endl;



        if (m < 0)
        {
            cout << i - 1 << endl;
            return 0;
        }
    }

    if (m >= 0)
    {
        cout << n << endl;
        return 0;
    }
    return 0;
}