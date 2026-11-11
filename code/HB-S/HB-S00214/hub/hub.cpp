#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

int c, t, n, k, res = 0;
vector<vector<int> > e(N);
bool vis[N];

void dfs(int dep, int pos)
{
    res = max(res, dep);
    int len = e[pos].size();
    for(int i = 0;i < len;++ i)
    {
        if(!vis[e[pos][i]])
        {
            vis[e[pos][i]] = true;
            dfs(dep + 1, e[pos][i]);
            vis[e[pos][i]] = false;
        }
    }
}

int main()
{
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);

    cin >> c >> t;

    while(t --)
    {
        res = 0;

        cin >> n >> k;

        for(int i = 1;i <= n;++ i) e[i].clear();

        for(int i = 1, u, v;i < n;++ i)
        {
            cin >> u >> v;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        for(int i = 1;i <= n;++ i)
        {
            vis[i] = true;
            dfs(1, i);
            vis[i] = false;
        }

        if(k == 1)
        {
            cout << res / 2 << endl;
        }else
        {
            cout << (res + 1) / 4 << endl;
        }
    }

    return 0;
}
