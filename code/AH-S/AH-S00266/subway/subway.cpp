#include <bits/stdc++.h>
using namespace std;

const int M = 5e5 + 5 ,N = 1;
int c ,n ,m ,d ,q ,x ,y;
long long w[M] ,k[N] ,a[N][M] ,t[N][M];

int main ()
{
    freopen ("subway.in","r" ,stdin);
    freopen ("subway.out" ,"w" ,stdout);
    scanf ("%d%d%d%d%d" ,&c ,&n ,&m ,&d ,&q);
    for (int i = 1;i <= m;i++)
        scanf ("%lld" ,&w[i]);
    for (int i = 1;i <= n;i++)
    {
        scanf ("%lld" ,&k[i]);
        for (int j = 1;j <= k[i];j++)
            scanf ("%lld%lld" ,&a[i][j] ,&t[i][j]);
    }
    if (n == 1)
    {
        int p[M];
        for (int i = 1;i <= k[1];i++)
            p[a[1][i]] = i;
        for (int i = 1;i <= q;i++)
        {
            scanf ("%d%d" ,&x ,&y);
            printf ("%lld\n" ,w[x] + w[y] + t[1][p[x]] + t[2][p[y]]);
        }
        return 0;
    }
    return 0;
}
