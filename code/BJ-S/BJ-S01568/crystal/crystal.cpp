#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
const int N = 500000 + 10;
long long n, m, a[N], s[N];
int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    bool A = true, B = true, C = true;
    long long k = 0;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        if (A && a[i] != i) A = false;
        if (i == 2) k = a[2] - a[1];
        if (B && i >= 3 && a[i] - a[i - 1] != k) B = false;
        if (C && a[i] > 100000) C = false;
    }
    if (A)
    {
        long long ansa = 1, cur = 1;
        if (n % 2 == 1)
        {
            if (m >= (n * n - 1) / 4)
            {
                cout << n;
                return 0;
            }
        }
        else if (n % 2 == 0)
        {
            if (m >= n * n / 4)
            {
                cout << n;
                return 0;
            }
        }
        while (m >= cur)
        {
            m -= cur;
            ++ansa;
            if (ansa == n) break;
            if (m >= cur)
            {
                m -= cur;
                ++ansa;
                if (ansa == n) break;
            }
            ++cur;
        }
        cout << ansa;
        return 0;
    }
    else if (B)
    {
        long long ansb = 1, cur = k;
        if (n % 2 == 1)
        {
            if (m >= (n * n - 1) * k / 4)
            {
                cout << n;
                return 0;
            }
        }
        else if (n % 2 == 0)
        {
            if (m >= n * n * k / 4)
            {
                cout << n;
                return 0;
            }
        }
        while (m >= cur)
        {
            m -= cur;
            ++ansb;
            if (ansb == n) break;
            if (m >= cur)
            {
                m -= cur;
                ++ansb;
                if (ansb == n) break;
            }
            cur += k;
        }
        cout << ansb;
        return 0;
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i) s[i] = s[i - 1] + a[i];

    return 0;
}
