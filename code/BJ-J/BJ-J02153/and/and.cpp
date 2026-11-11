#include <bits/stdc++.h>
using namespace std;

long long a[200005], ans[200005];
bool on[200005];
stack<long long> st;

int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    int n, m;
    long long maxa = -1, all;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        maxa = max(maxa, a[i]);
        if (i == 1) all = a[i];
        else all &= a[i];
    }
    if (m == 1)
    {
        cout << maxa;
        return 0;
    }
    else if (m == n)
    {
        cout << all;
        return 0;
    }
    else if (m == 2)
    {
        long long ans = -1;
        for (int i = 1; i < n; ++i)
        {
            for (int j = i + 1; j <= n; ++j)
            {
                ans = max(ans, a[i] & a[j]);
            }
        }
        cout << ans;
        return 0;
    }
    return 0;
}
