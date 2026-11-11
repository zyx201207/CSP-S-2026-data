#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    int n, m, a[500005], b,sum = 0;
    cin >> n >> m;
    for (int i = 1; i <= n;i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        if (a[i] >= a[i - 1])
        {
            b = a[i];
            a[i] = a[i - 1];
            a[i - 1] = b;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (m == 0)
        {
            break;
        }
        else if (a[i] + 1 == a[i + 1])
        {
            a[i] += 1;
            m -= 1;
            a[i + 1] = 0;
            sum += 1;
        }
    }
    cout << sum;
}
