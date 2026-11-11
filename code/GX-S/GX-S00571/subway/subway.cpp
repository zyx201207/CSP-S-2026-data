#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define len1 500005
#define len2 505

int n, m, c, d, q;
int w[len1], a[len2][len1], t[len2][len1], k[len2];

int read()
{
    int k_ = 0, p = 1;
    char c_ = getchar();
    while (c_ < '0' || c_ > '9')
    {
        if (c == '-')
            p = -1;
        c_ = getchar();
    }
    while (c_ >= '0' && c_ <= '9')
    {
        k_ = k_ * 10 + (c_ - '0');
        c = getchar();
    }
    return k_ * p;
}

int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    scanf("%d %d %d %d %d", &c, &n, &m, &d, &q);
    c = read();
    n = read();
    m = read();
    d = read();
    q = read();
    for (int i = 1; i <= m; i++)
        w[i] = read();
    for (int i = 1; i <= n; i++)
    {
        k[i] = read();
        for(int j = 1; j <= k[i]; j++)
        {
            a[i][j] = read();
            t[i][a[i][j]] = read();
        }
    }
    while (q--)
    {
        int x, y, ans = 0;
        x = read();
        y = read();
        ans += w[x] + w[y];
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= k[i]; j++)
            {
                if (a[i][j] == x)
                {

                }
            }
        }

    }

    return 0;
}
