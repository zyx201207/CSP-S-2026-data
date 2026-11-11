#include <bits/stdc++.h>
using namespace std;

long long n, m, a[200005], maxn = -1e18;
bool vis[200005];

void dfs(long long ge, long long ans)
{
    if(ge > m - 1)
    {
        maxn = max(maxn, ans);
        return;
    }
    for(int i = 1; i <= n; i++)
    {
        if(vis[i] == true) continue;
        vis[i] = true;
        dfs(ge + 1, ans & a[i]);
        vis[i] = false;
    }
}

int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++)
    {
        vis[i] = true;
        dfs(1, a[i]);
        vis[i] = false;
    }
    cout << maxn << endl;
    return 0;
}
