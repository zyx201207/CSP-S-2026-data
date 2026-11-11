#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long n, m, a[200005];
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    if (m == 1)
    {
        cout << a[n];
        return 0;
    }
    else if (m == n)
    {
        for (int i = n - 1; i >= 1; i--)
            a[n] &= a[i];
        cout << a[n];
        return 0;
    }
    else
    {
        long long k = pow(2, (int)floor(log2(a[n])));
        bool flag = true;
        int n1 = n;
        while (k)
        {
            flag = true;
            for (int i = n1; i >= n1 - m + 1; i--)
            {
                if (a[i] < k)
                {
                    flag = false;
                    n1 = n1 - i + 1;
                    break;
                }
            }
            if (!flag)
                k /= 2;
            else
                break;
        }
        if (!flag)
        {
            for (int i = n - 1; i >= n - m + 1; i--)
                a[n] &= a[i];
            cout << a[n];
            return 0;
        }
        int ind;
        for (int i = n; i >= 1; i--)
        {
            if (a[i] >= k && a[i] <= k * 2)
            {
                ind = i;
                break;
            }
        }
        for (int i = ind - 1; i >= ind - m + 1; i--)
            a[ind] &= a[i];
        cout << a[ind];
    }
    return 0;
}
