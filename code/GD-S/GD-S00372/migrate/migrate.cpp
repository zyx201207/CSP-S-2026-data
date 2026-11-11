#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2000010;
int n;
ll d, x[N];
ll f[N][2][2];
int nex[N];
void slove()
{
    scanf("%d%lld", &n, &d);
    for(int i = 1; i <= n; i++)
    {
        scanf("%lld", x + i);
        memset(f[i], 0, sizeof f[i]);
    }
    int sr = n;
    for(int i = n; i; i--)
    {
        while(x[sr] - x[i] > d)sr--;
        nex[i] = sr;
    }
    ll ans = 0;
    for(int i = n; i; i--)
    if(nex[i] != i)
    {
        ans += f[nex[i]][1][0] + f[nex[i]][1][1];
        for(int x = 0; x < 2; x++)
            for(int y = 0; y < 2; y++)
            {
                int z = (nex[i - 1] >= nex[i] - y);
                if((i > 2 && nex[i - 2] >= nex[i] - y) || x + z >= 2)continue;
                f[i][x + z][z] += f[nex[i]][x][y];
            }
        f[i][0][0] += max(nex[i] - max(nex[i - 1], i), 0);
        if(i > 2)
        f[i][1][1] += max(nex[i - 1] - max(nex[i - 2], i), 0);
    }
    printf("%lld\n", ans);
}
int main()
{
    freopen("migrate.in", "r", stdin); freopen("migrate.out", "w", stdout);
    int c, t;
    scanf("%d%d", &c, &t);
    while(t--)slove();
    return 0;
}
