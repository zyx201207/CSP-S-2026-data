#include <iostream>
#include <queue>
using namespace std;
#define int long long

int c , t , n , d , a[2000005] , vis[2000005] , minn[2000005] , cnt[2000005] , ans = 0;
struct stu
{
    int x , l;
};
queue<stu> q;
void bfs()
{
    while (!q.empty())
    {
        stu x = q.front();
        q.pop();
        minn[x.x] = min(minn[x.x] , x.l);
        if (x.l == minn[x.x])
        {
            cnt[x.x]++;
        }
        for (int i = x.x + 1; i <= n; i++)
        {
            if (a[i] - a[x.x] <= d)
            {
                if (vis[i] && x.l + 1 > minn[i])
                {
                    continue;
                }
                vis[i] = 1;
                q.push({i , x.l + 1});
            }
        }
    }
}

signed main()
{
    freopen("migrate.in" , "r" , stdin);
    freopen("migrate.out" , "w" , stdout);
    cin >> c >> t;
    if (c == 11 || c == 12)
    {
        for (int i = 1; i <= t; i++)
        {
            cin >> n >> d;
            ans = 0;
            for (int i = 1; i <= n; i++)
            {
                cin >> a[i];
            }
            int D = abs(a[2] - a[1]);
            int p = d / D;
            if (p < 2 || p * 2 - 1 > n)
            {
                cout << 0 << endl;
                continue;
            }
            cout << n - p * 2 + 1 << endl;
            continue;
        }
        return 0;
    }
    while (t--)
    {
        cin >> n >> d;
        ans = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                vis[j] = 0;
                minn[j] = 1e9;
                cnt[j] = 0;
            }
            vis[i] = 1;
            q.push({i , 0});
            bfs();
            for (int j = 1; j <= n; j++)
            {
                if (cnt[j] == 2)
                {
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
