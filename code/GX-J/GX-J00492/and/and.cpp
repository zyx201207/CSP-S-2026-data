#include <bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005],num[200005],ans;
bool vis[200005];
void dfs(int u)
{
    if (u == m + 1)
    {
        long long sum = num[1];
        for (int i = 2;i <= m;i++)
        {
            sum &= num[i];
        }
        ans = max(sum,ans);
        return;
    }
    for (int i = 1;i <= n;i++)
    {
        if (!vis[i])
        {
            vis[i] = 1;
            num[u] = a[i];
            dfs(u + 1);
            vis[i] = 0;
        }
    }
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for (int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    if (m == 1)
    {
        sort(a + 1,a + n + 1);
        cout << a[n];
        return 0;
    }
    dfs(1);
    cout << ans;
    return 0;
}
