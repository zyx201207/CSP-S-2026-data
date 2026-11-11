#include <bits/stdc++.h>
using namespace std;
long long t[500005], sum[500005];
int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    int n;
    long long m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> t[i];
    }
    sort(t + 1, t + n + 1);
    for (int i = 1; i <= n; i++)
    {
        sum[i] = sum[i - 1] + t[i];
    }
    int maxn = -1e9;
    for (int i = 1; i <= n; i++)
    {
        int l = 1, r = i, ans = i + 1;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (t[i] * (i - mid + 1) - sum[i] + sum[mid - 1] <= m)
            {
                r = mid - 1;
                ans = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        maxn = max(maxn, i - ans + 1);
    }
    cout << maxn << endl;
    return 0;
}
