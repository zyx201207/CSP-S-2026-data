#include <iostream>
#include <cstring>

using namespace std;
long long c, t, ans;
long long n, d, x[2000005] = {};
long long win[2000005], bfsans[2000005], p1, p2, pp;
bool f[2000005], ff[2000005];

void bfs(int start)
{
    if(p1 >= p2 || p1 >= n)
    {
        return;
    }
    for (int i = 1; i <= n; i ++)
    {
        if(x[i] > x[start] + d)
        {
            break;
        }
        int dd = x[i] - x[start];
        if(dd <= d && dd >= -d && f[i])
        {
            win[p2] = i;
            bfsans[i] ++;
            ff[i] = 0;
            p2 ++;
        }
    }
    p1 ++;
    if(p1 >= pp)
    {
        pp = p2;
        for (int i = 1; i <= n; i ++)
        {
            if(ff[i] = 0)
            {
                f[i] = 0;
            }
        }
    }
    bfs(win[p1]);
}

int sch(int start, int eend)
{
    memset(win, 0, sizeof(win));
    memset(bfsans, 0, sizeof(bfsans));
    memset(f, 1, sizeof(f));
    memset(f, 1, sizeof(f));
    win[1] = start;
    f[start] = 0;
    bfsans[start] = 0;
    p1 = 1;
    p2 = 2;
    pp = 2;
    bfs(start);
    return bfsans[eend];
}

void work()
{
    ans = 0;
    memset(x, 0, sizeof(x));
    cin >> n >> d;
    for (long long i = 1; i <= n; i ++)
    {
        cin >> x[i];
    }
    for (long long i = 1; i < n; i ++)
    {
        for (long long j = i + 1; j <= n; j ++)
        {
            if(sch(i, j) == 2)
            {
                ans ++;
            }
        }
    }
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> c >> t;
    for (int i = 1; i <= t; i ++)
    {
        work();
    }
    return 0;
}
