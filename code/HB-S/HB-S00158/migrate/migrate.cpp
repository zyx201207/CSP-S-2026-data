#include <bits/stdc++.h>
using namespace std;
#define int long long
int x[2000005], n, d;
signed main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int c, t;
    cin >> c >> t;
    while (t--)
    {
        int n, d;
        cin >> n >> d;
        for (int i = 1; i <= n; i++) cin >> x[i];
        if (x[1] >= 0)
        {
            if (d >= x[n] - x[1])
            {
                int sum = 0, cnt = 0, num = 1;
                for (int i = 4; i <= n; i++)
                {
                    sum += num;
                    if (cnt == 2)
                    {
                        sum++;
                        num++;
                        cnt = 0;
                    }
                    cnt++;
                }
                cout << sum << endl;
            }
            else
            {
                int s = 0;
                for (int i = 1; i <= n; i++)
                {
                    if (x[i] - x[1] <= d) s = i;
                    else break;
                }
                int sum = 0, cnt = 0, num = 1;
                for (int i = 4; i <= n; i++)
                {
                    sum += num;
                    if (cnt == 2)
                    {
                        sum++;
                        num++;
                        num = min(num, s);
                        cnt = 0;
                    }
                    cnt++;
                }
                cout << sum << endl;

            }
        }
        else
        {
            int cnt1 = 0, cnt2 = 0;
            for (int i = 1; i <= n; i++)
            {
                if (x[i] < 0) cnt1++;
                else cnt2++;
            }
            cout << (int)(abs(cnt1 - cnt2)) / 2 << endl;
        }
    }
    return 0;
}
