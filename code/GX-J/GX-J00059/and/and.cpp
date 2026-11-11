#include<bits/stdc++.h>
using namespace std;
int n, m, a[200010], vis[200010], ans = -1e9;
void dfs(int len, int last)
{
    if(len == m)
    {
        int cnt = a[vis[1]];
        for(int i = 2; i <= m; i++)
        {
            cnt &= a[vis[i]];
        }
        ans = max(ans, cnt);
        return;
    }
    for(int i = last+1; i <= n-m+len+1; i++)
    {
        vis[len+1] = i;
        dfs(len+1, i);
        vis[len+1] = 0;
    }
}
int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    if(m == 1)
    {
        int maxn = -1e9;
        for(int i = 1; i <= n; i++) maxn = max(maxn, a[i]);
        cout << maxn;
        return 0;
    }
    dfs(0, 0);
    cout << ans;
    return 0;
}
