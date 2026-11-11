#include <bits/stdc++.h>
using namespace std;

long long n, m, a[500005], ans, vs[500005];
bool flag=1;

void dfs(long long x, long long y, long long z, long long cnt)
{
    ans = max(ans, cnt);
    if (y == n || y <= vs[x])
    {
        return ;
    }
    vs[x] = y;
    if (y < n && z >= cnt*(a[y+1]-a[y]))
    {
        dfs(x, y+1, z-cnt*(a[y+1]-a[y]), cnt+1);
    }
    if (x < y)
    {
        dfs(x+1, y, z+a[x+1]-a[x], cnt-1);
    }
    if (y < n && x == y)
    {
        dfs(x+1, y+1, m, cnt);
    }
}

int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for (int i=1; i<=n; i++)
    {
        cin >> a[i];
    }
    sort(a+1, a+n+1);
    a[0] = a[2]-a[1];
    for (int i=3; i<=n; i++)
    {
        if (a[i]-a[i-1] != a[0])
        {
            flag = false;
        }
    }
    if (flag)
    {
        ans = 1;
        for(int i=2; i<=n; i++)
        {
            if (m >= a[i]-a[1])
            {
                m -= (a[i]-a[1]);
                ans++;
            }
            else
            {
                break;
            }
        }
        cout << ans;
        return 0;
    }
    dfs(1, 1, m, 1);
    cout << ans << endl;
    return 0;
}
