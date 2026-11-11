#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
long long a[500005], b[500005];

int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    int n;
    long long m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++)
    {
        b[i] = b[i - 1] + (a[i] - a[i - 1] * (i - 1));
    }
    long long maxn = -1e9;
    for (int i = 1; i <= n; i++)
    {
        //if (a[i] > m)
        //{
        //    break;
        //}
        long long sum = 0, cnt = 0;
        if (b[i] <= m)
        {
            maxn = max(maxn, i * 1ll);
        }
    }
    if (maxn == 0)
    {
        cout << 1;
    }
    else
    {
        cout << maxn;
    }
    return 0;
}
