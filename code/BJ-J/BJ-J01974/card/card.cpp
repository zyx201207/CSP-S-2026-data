#include <bits/stdc++.h>
#define int long long
using namespace std;

int a[1000005];
int f[1000005];
int ans[1000005];
int de[1000005];
int n,m;

void dfs(int w)
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    memset(f,0,sizeof(f));
    for (int i = w; i <= n; i++)
    {
        if (f[a[i]] != 0)
        {
            for (int j = f[a[i]] + 1; j <= i - 1; j++)
            {
                f[a[j]] = 0;
            }
            f[a[i]] = i;
        }
        else
        {
            f[a[i]] = i;
        }
    }
    for (int i = 1; i <= m; i++)
    {
        if (f[i] != 0)
        {
            ans[i]++;
        }
    }
}

signed main()
{

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        dfs(i);
    }
    for (int i = 1; i <= m; i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}
