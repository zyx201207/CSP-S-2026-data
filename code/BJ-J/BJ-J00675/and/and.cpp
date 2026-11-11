#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans,tmp,itmp;
int a[200005];
bool b[200005][35];
int vis1[200005];
int vis[200005];
signed main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for(int i=1; i<=n; i++) cin >> a[i];
    for(int i=1; i<=n; i++)
    {
        int cnt = 0;
        int x = a[i];
        while(x != 0)
        {
            b[i][++cnt] = x % 2;
            x /= 2;
        }
    }
    for(int i=30; i>=1; i--)
    {
        int num = 0;
        for(int j=1; j<=n; j++)
        {
            if(b[j][i] != 0)
            {
                num++;
            }
        }
        if(num >= m)
        {
            tmp = i;
            break;
        }
    }
    for(int i=1; i<=n; i++)
    {
        if(b[i][tmp] == 1) vis[i] = 1;
    }
    for(int i=tmp-1; i>=1; i--)
    {
        memset(vis1, 0, sizeof vis1);
        int cnt = 0;
        int num = 0;
        for(int j=1; j<=n; j++)
        {
            if(vis[j] == 1 && b[j][i] != 0)
            {
                num++;
                vis1[j] = 1;
            }
        }
        if(num >= m)
        {
            for(int i=1; i<=n; i++)
            {
                vis[i] = vis1[i];
            }
        }
    }
    for(int i=1; i<=n; i++)
    {
        if(vis[i] == 1)
        {
            ans = a[i];
            itmp = i;
            break;
        }
    }
    for(int i=itmp+1; i<=n; i++)
    {
        if(vis[i] == 1)
        {
            ans = ans & a[i];
        }
    }
    cout << ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
