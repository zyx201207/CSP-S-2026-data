#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, m, maxx, a[N], maxa;
int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        maxa = max(maxa, a[i]);
    }
    if (m == 1)
    {
        cout << maxa;
        return 0;
    }
    if (m == 2)
    {
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (i != j) maxx = max(maxx, (a[i] & a[j]));
            }
        }
        cout << maxx;
        return 0;
    }
    if (m == n)
    {
        maxx = a[1];
        for (int i = 2; i <= n; ++i)
        {
            maxx = (maxx & a[i]);
        }
        cout << maxx;
        return 0;
    }
    cout << 9178;
    return 0;
}