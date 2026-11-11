#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[2000010],vis[2000010],maxndfs = 0;
int dfs(int x,int ans)
{
    if(x == m) maxndfs = max(maxndfs,ans);
    for(int i = 1;i <= n;i++)
    {
        if(vis[i] == 0)
        {
            vis[i] = 1;
            dfs(x + 1,ans & a[i]);
            vis[i] = 0;
        }
    }
}
signed main()
{
    //freopen("and.in","r",stdin);
    //freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    if(m == 1)
    {
        int maxn = 0;
        for(int i = 1;i <= n;i++)
        {
            maxn = max(maxn,a[i]);
        }
        cout << maxn;
        return 0;
    }
    if(m == 2)
    {
        int maxn1 = 0;
        for(int l = 1;l <= n;l++)
        {
            for(int r = l + 1;r <= n;r++)
            {
                maxn1 = max(maxn1,a[l] & a[r]);
            }
        }
        cout << maxn1;
        return 0;
    }
    if(m == n)
    {
        int maxn2 = a[1];
        for(int i = 2;i <= n;i++)
        {
            maxn2 = maxn2 & a[i];
        }
        cout << maxn2;
        return 0;
    }
    if(m == n - 1)
    {
        int ans = 0;
        for(int i = 1;i <= n;i++)
        {
            int cnt;
            if(i != 1)
            {
                cnt = a[1];
                for(int j = 2;j <= n;j++)
                {
                    if(j != i) cnt = (cnt & a[j]);
                }
            }
            if(i == 1)
            {
                cnt = a[2];
                for(int j = 3;j <= n;j++)
                {
                    if(j != i) cnt = (cnt & a[j]);
                }
            }
            ans = max(ans,cnt);
        }
        cout << ans;
        return 0;
    }
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    dfs(0,1024 * 1024 * 1024 - 1);
    cout << maxndfs;
    return 0;
}