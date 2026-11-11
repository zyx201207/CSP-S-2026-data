#include <iostream>
#include <algorithm>
using namespace std;
#define int long long

int n , m , a[500005] , ans = 0;

signed main()
{
    ios::sync_with_stdio(false);
    freopen("crystal.in" , "r" , stdin);
    freopen("crystal.out" , "w" , stdout);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int f = 1;
    for (int i = 2; i <= n; i++)
    {
        if (a[i] - a[i - 1] != a[2] - a[1])
        {
            f = 0;
        }
    }
    if (f)
    {
        int d = 0;
        for (int i = 1; i <= n; i++)
        {
            if (m >= d)
            {
                m -= d;
                ans++;
                d += abs(a[2] - a[1]);
            }
            else
            {
                break;
            }
        }
        cout << ans << endl;
        return 0;
    }
    sort(a + 1 , a + n + 1);
    for (int i = 1; i <= n; i++)
    {
        int cnt = 0 , t = m;
        for (int j = 1; j <= i; j++)
        {
            if (t >= a[i] - a[j])
            {
                t -= a[i] - a[j];
                cnt++;
            }
            else
            {
                break;
            }
        }
        ans = max(ans , cnt);
    }
    cout << ans << endl;
    return 0;
}
