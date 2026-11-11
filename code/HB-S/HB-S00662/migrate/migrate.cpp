#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 2e6 + 2;

struct node
{
    int l, r;
};

ll read()
{
    ll sum = 0, f = 1;
    char ch = getchar_unlocked();
    while(ch < '0' || ch > '9')
    {
        if(ch == '-')
            f = -1;
        ch = getchar_unlocked();
    }
    while(ch >= '0' && ch <= '9')
    {
        sum = (sum << 3) + (sum << 1);
        sum += ch - '0';
        ch = getchar_unlocked();
    }
    return sum * f;
}

ll c, t, n, m, x[N], ans;

bool check(int i)
{
    if(x[i + 2] > x[i] + m)
        return 0;
    if(x[i + 3] <= x[i] + m)
        return 0;
    if(x[i + 3] > x[i + 1] + m)
        return 0;
    if(i + 4 <= n && x[i + 4] <= x[i + 1] + m)
        return 0;
    return true;
}

int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    c = read();
    t = read();
    while(t--)
    {
        ans = 0;
        n = read();
        m = read();
        for(int i = 1; i <= n; i++)
            x[i] = read();
        vector <node> p;
        for(int i = 1; i <= n - 3; i++)
            if(check(i))
                p.push_back({i, i + 3});
        for(int i = 0; i < p.size(); i++)
        {
            if(!i)
                ans += p[i].l;
            else
            {
                if(p[i - 1].r <= p[i].l)
                    ans += p[i].l - p[i - 1].r + 3;
                else
                    ans += p[i].l - p[i - 1].l;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
