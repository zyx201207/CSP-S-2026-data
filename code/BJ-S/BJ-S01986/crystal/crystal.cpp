//80pts?
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

long long a[500005];
long long b[500005];

int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    if (m > 100000000)
    {
        long long sum = 0, cnt = 0;
        for (int j = 1; j <= n; ++j)
        {
            b[j] = a[n] - a[j];
        }
        for (int j = n; j >= 1; --j)
        {
            if (b[j] >= 0)
            {
                if (b[j] + sum <= m)
                {
                    sum += b[j];
                    cnt++;
                }
            }
        }
        cout << cnt;
        return 0;
    }
    long long ans = 0;
    for (long long i = a[1]; i <= a[n]; ++i)
    {
        long long sum = 0, cnt = 0;
        for (int j = 1; j <= n; ++j)
        {
            b[j] = i - a[j];
        }
        for (int j = n; j >= 1; --j)
        {
            if (b[j] >= 0)
            {
                if (b[j] + sum <= m)
                {
                    sum += b[j];
                    cnt++;
                }
            }
        }
        ans = max(ans, cnt);
    }
    cout << ans;
    return 0;
}
