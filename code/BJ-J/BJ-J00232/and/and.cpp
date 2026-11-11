#include <bits/stdc++.h>
using namespace std;

bool vis[25];
long long n,m,a[202020],maxn = -1,ans,mx;

void dfs(int step,int cnt)
{
    if (cnt > m || step > n + 1)
    {
        return;
    }
    //cout << step << " www " << cnt << endl;
    if (step > n && cnt == m)
    {
        ans = 0;
        bool f = 1;
        for (int i = 1; i <= n; ++i)
        {
            if (vis[i])
            {
                if(f)
                {
                    f = 0;
                    ans = a[i];
                }
                else
                {
                    ans = ans & a[i];
                }
                //cout << i << " " << a[i] << endl;
            }
        }
        //cout << ans << endl;
        maxn = max(maxn,ans);
        return;
    }
    vis[step] = 1;
    dfs(step + 1,cnt + 1);
    vis[step] = 0;
    dfs(step + 1,cnt);
}

int main ()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        maxn = max(maxn,a[i]);
        if (i == 1)
        {
            ans = a[i];
        }
        else
        {
            ans = ans & a[i];
        }
    }
    if (m == 1)
    {
        cout << maxn << endl;
        return 0;
    }
    if (m == 2)
    {
        for (int i = 1; i <= n; ++i)
        {
            for (int j = i + 1; j <= n; ++j)
            {
                mx = max(mx,a[i] & a[j]);
            }
        }
        cout << mx << endl;
        return 0;
    }
    if (m == n)
    {
        cout << ans << endl;
        return 0;
    }
    maxn = -1;
    if (n <= 20)
    {
        dfs(1,0);
        cout << maxn << endl;
        return 0;
    }
    sort(a + 1,a + n + 1);
    cout << a[n - m + 1] << endl;
    return 0;
}
/*
5 3
31 3 1 15 7
*/
