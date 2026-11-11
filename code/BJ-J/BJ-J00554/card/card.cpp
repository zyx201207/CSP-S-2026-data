#include <bits/stdc++.h>
using namespace std;

int a[50005];
int pos[50005];
int l[5005];
int r[5005];
bool f[50005];
int tmp[50005];
int sum[500005];
bool tg[5005];
int n, m;

void solve()
{
    for(int i = 1; i <= n;)
    {
        int pos = upper_bound(a + 1, a + n + 1, a[i]) - a - 1;
        sum[a[i]] += pos;
        i = pos + 1;
    }
}

void build(int ll, int rr)
{
    int lng = sqrt(n);
    int cnt = 0;
    while(1)
    {
        cnt++;
        l[cnt] = ll + (cnt - 1) * lng;
        r[cnt] = ll + cnt * lng - 1;
        if(r[cnt] >= rr)
        {
            r[cnt] = rr;
            break;
        }
    }
    for(int i = 1; i <= cnt; i++)
    {
        for(int j = l[i]; j <= r[i]; j++)
        {
            pos[j] = i;
        }
    }
}

void chg(int ll, int rr)
{
    if(pos[ll] == pos[rr])
    {
        for(int i = ll; i <= rr; i++)
        {
            f[i] = true;
        }
        return;
    }
    int rpos = r[pos[ll]];
    int lpos = l[pos[rr]];
    for(int i = ll; i <= rpos; i++)
    {
        f[i] = true;
    }
    for(int i = lpos; i <= rr; i++)
    {
        f[i] = true;
    }
    for(int i = pos[ll] + 1; i < pos[rr]; i++)
    {
        tg[i] = true;
    }
}

bool chk(int x)
{
    if(f[x] || tg[pos[x]])
    {
        return false;
    }
    return true;
}

int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    bool fff = true;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if(a[i] < a[i - 1])
        {
            fff = false;
        }
    }
    if(fff)
    {
        solve();
        for(int i = 1; i <= m; i++)
        {
            cout << sum[i] << ' ';
        }
        cout << "\n";
        return 0;
    }
    for(int i = 1; i <= n; i++)
    {
        build(i, n);
        memset(tmp, 0, sizeof(tmp));
        memset(f, false, sizeof(f));
        memset(tg, false, sizeof(tg));
        for(int j = i; j <= n; j++)
        {
            if(tmp[a[j]])
            {
                if(chk(tmp[a[j]]))
                {
                    chg(tmp[a[j]], j - 1);
                }
                tmp[a[j]] = j;
            }
            else
            {
                tmp[a[j]] = j;
            }
        }
        for(int j = i; j <= n; j++)
        {
            if(chk(j))
            {
                sum[a[j]]++;
            }
        }
    }
    for(int i = 1; i <= m; i++)
    {
        cout << sum[i] << ' ';
    }
    cout << "\n";
    return 0;
}