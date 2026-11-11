#include <bits/stdc++.h>
using namespace std;

long long x[2000005];
bool fly[5005][5005];
long long dis[5005][5005];
long long cnt[5005][5005];

int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);

    long long c, t;
    cin >> c >> t;
    while (t--)
    {
        memset(x, 0, sizeof(x));
        memset(fly, 0, sizeof(fly));
        memset(cnt, 0, sizeof(cnt));

        long long n, d, ans = 0;
        cin >> n >> d;

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                dis[i][j] = 1e18;

        for (long long i = 1; i <= n; i++)
            cin >> x[i];

        for (long long i = 1; i <= n; i++)
            fly[i][i] = true, dis[i][i] = 0;
        for (long long i = 1; i <= n; i++)
            for (long long j = i + 1; j <= n;j++)
                if (x[j] - x[i] <= d)
                    fly[i][j] = true, dis[i][j] = 1;

        for (long long i = 1; i <= n; i++)
        {
            for (long long j = i + 1; j <= n; j++)
            {
                for (long long k = i + 1; k < j; k++)
                {
                    if (fly[i][k] && fly[k][j])
                    {
                        dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                        fly[i][j] = true;
                    }
                    /*
                    cout << "----------\nDebug:\n";
                    cout << i << " " << k << " " << j << endl;
                    cout << fly[i][k] << " " << fly[k][j] << endl;
                    cout << dis[i][j] << " " << dis[i][k] << " " << dis[k][j] << endl;
                    */
                }
            }
        }
        for (long long i = 1; i <= n; i++)
        {
            for (long long j = i + 1; j <= n; j++)
            {
                for (long long k = i + 1; k < j; k++)
                {
                    if (fly[i][j] && fly[i][k] && fly[k][j])
                    {
                        if ((dis[i][j] == (dis[i][k] + dis[k][j])) && (dis[i][k] + dis[k][j]) != (j - i))
                        {
                            /*
                            cout << "Min Dis:" << i << " " << k << " " << j;
                            cout << "\n";
                            cout << dis[i][j] << " " << dis[i][k] << " " <<  dis[k][j] << endl;
                            */
                            cnt[i][j]++;
                        }
                    }
                }
            }
        }
        for (long long i = 1; i <= n; i++)
        {
            for (long long j = i + 1; j <= n; j++)
            {
                if (cnt[i][j] == 2)
                {
                    //cout << "\nFind Ans:" << i << " " << j;
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
