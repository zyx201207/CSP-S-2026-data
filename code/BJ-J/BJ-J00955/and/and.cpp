#include <bits/stdc++.h>
using namespace std;

int n,m,ans;
int a[200005];
bool vis[200005];

void dfs(int step,int tmp,int pos)
{
    if (step == m + 1)
    {
        ans = max(ans,tmp);
        return;
    }

    if (n - pos < m - step)
    {
        return;
    }

    for (int i = 1;i <= n;i ++)
    {
        if (!vis[i])
        {
            vis[i] = true;
            if (step == 1)
            {
                dfs(step + 1,a[i],i);
            }
            else
            {
                dfs(step + 1,tmp & a[i],i);
            }
            vis[i] = false;
        }
    }
}

int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for (int i = 1;i <= n;i ++)
    {
        cin >> a[i];
    }
    dfs(1,0,0);
    cout << ans;
    return 0;
}
