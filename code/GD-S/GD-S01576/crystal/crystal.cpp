
#include <algorithm>
#include <iostream>
using namespace std;

#define MAXN 500005

using ll = long long;

int n;

ll m;
ll a[MAXN], sa[MAXN];

int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++)
    {
        sa[i] = sa[i - 1] + a[i];
    }
    int res = 1;
    for (int i = 2; i <= n; i++)
    {
        int l = 1, r = i;
        while (l < r)
        {
            int mid = (l + r) >> 1;
            if (a[i] * (i - mid + 1) - (sa[i] - sa[mid - 1]) <= m)
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        res = max(res, i - l + 1);
    }
    cout << res << '\n';
    return 0;
}
