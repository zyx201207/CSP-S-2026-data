#include <iostream>
#include <cstdio>

using namespace std;

int head[514514], nxt[514514], val[514514], cnt;
int c, n, m, d, q;//useful: n m q
long long int w[514514], tim[514514];
long long int f[514][514];

int jiabian(int zt, int sub, int ti)//zhantai subway time
{
    cnt++;
    val[cnt] = sub;
    nxt[cnt] = head[zt];
    tim[cnt] = ti;
    head[zt] = cnt;
}

int main()
{
    freopen ("subway.in", "r", stdin);
    freopen ("subway.out", "w", stdout);
    int i, j, k;
    cin >> c >> n >> m >> d >> q;
    for (i = 1; i <= m; i++)
    {
        cin >> w[i];
    }
    for (i = 1; i <= n; i++)
    {
        int flen;
        cin >> flen;
        while (flen--)
        {
            int zhantai, time;
            cin >> zhantai >> time;
            jiabian(zhantai, i, time);
        }
    }
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            f[i][j] = 0x3f3f3f3f3f3f3f3f;
        }
        f[i][i] = 0;
    }
    for (i = 1; i <= m; i++)
    {
        for (j = head[i]; nxt[j] > 0; j = nxt[j])
        {
            for (k = nxt[j]; k > 0; k = nxt[k])
            {
                //cout << tim[j] << " " << tim[k] << endl;
                f[val[j]][val[k]] = min(f[val[j]][val[k]], tim[j] + tim[k]);
                f[val[k]][val[j]] = min(f[val[k]][val[j]], tim[j] + tim[k]);
            }
        }
    }

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            for (k = 1; k <= n; k++)
            {
                f[j][k] = min(f[j][k], f[j][i] + f[i][k]);
            }
        }
    }
    int fq;
    for (fq = 1; fq <= q; fq++)
    {
        int a, b;
        long long int ans = 0x3f3f3f3f3f3f3f3f;
        cin >> a >> b;
        for (i = head[a]; i > 0; i = nxt[i])
        {
            for (j = head[b]; j > 0; j = nxt[j])
            {
                ans = min (ans, f[val[i]][val[j]]   + tim[i] + tim[j] + w[a] + w[b]   );//+ tim[i] + tim[j] + w[a] + w[b]
            }
        }
        cout << ans << endl;
    }
    return 0;
}
