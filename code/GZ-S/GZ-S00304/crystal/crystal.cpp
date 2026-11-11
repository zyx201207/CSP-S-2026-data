//GZ-S00304 华东师范大学附属贵阳学校 蒋泽赟
#include <bits/stdc++.h>
using namespace std;

long long a[500005], c[500005];
int d[500005];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
	freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    long long n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    sort(a + 1, a + n + 1);
    c[1] = 0;
    for (int i = 2; i <= n; ++i)
    {
        c[i] = c[i - 1] + (i - 1) * (a[i] - a[i - 1]);
    }
    int maxn = 0;
    for (int i = 2; i <= n; ++i)
    {
        if (c[i] <= m) d[i] = i;
        else
        {
            int l = 1, r = i, ans = i;
            while(l < r)
            {
                int mid = (l + r) >> 1;
                if (c[i] - (c[mid - 1] + (mid - 1) * (a[i] - a[mid - 1])) <= m)
                {
                    ans = mid;
                    r = mid;
                }
                else l = mid + 1;
            }
            d[i] = i - ans + 1;
        }
        maxn = max(maxn, d[i]);
    }
    cout << maxn << "\n";
    return 0;
}
