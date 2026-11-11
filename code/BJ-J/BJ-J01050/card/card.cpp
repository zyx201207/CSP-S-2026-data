#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5+8, M = 3e5+8;
int n, m, a[N];
int ans[M], cnt[M];
bool vis[M];
vector<int> g[M];

void dfs(int u)
{
    for (int v: g[u])
    {
        dfs(v);
        cnt[u] += cnt[v];
    }
    return;
}

signed main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)cin >> a[i];
    for (int i = n; i >= 1; i--)
    {
        if (vis[a[i]]==0)
        {
            vis[a[i]] = 1;
            cnt[a[i]]++;
            g[a[i+1]].push_back(a[i]);
        }
        else cnt[a[i]]++;
    }
    dfs(a[n]);
    for (int i = 1; i <= m; i++)cout << cnt[i] << ' ';
    cout << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}