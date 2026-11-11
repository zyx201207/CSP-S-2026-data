#include<bits/stdc++.h>
using namespace std;

const int N = 2e6 + 5;
long long c, t, n, d, x[N];
struct node
{
    long long t, l;
};
node cnt[N];

long long read()
{
    long long w = 1, x = 0; char ch;
    ch = getchar();
    while(ch < '0' || ch > '9')
    {
        if(ch == '-') w *= -1;
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9')
    {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * w;
}

void dfs1(int p)
{
    if(p >= n) return;
    int pp = p + 1;
    while(x[pp] - x[p] <= d && pp <= n) pp++;
    for(int i = p + 1; i < pp; i++)
        cnt[i].l = cnt[p].l + 1;
    if(pp > p + 1)dfs1(pp - 1);
}

void dfs2(int p, int cntl)
{
    if(cntl > 2) return;
    for(int i = p + 1; i <= n; i++)
        if(x[i] - x[p] <= d && cnt[i].l >= cntl + 1)
        {
            cnt[i].t++;
            dfs2(i, cntl + 1);
        }
}

int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    c = read(); t = read();
    for(int tt = 1; tt <= t; tt++)
    {
        n = read(); d = read();
        for(int i = 1; i <= n; i++)
            x[i] = read();
        long long ans = 0;
        for(int i = 1; i < n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                cnt[j].t = 0;
                cnt[j].l = 1e18;
            }
            cnt[i].t = 1;
            cnt[i].l = 0;
            dfs1(i);
            dfs2(i, 0);
            for(int j = 1; j <= n; j++)
                if(cnt[j].t == 2)
                    ans++;
        }
        cout << ans << endl;
    }
    return 0;
}
