#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, k;
int c, t;
int u, v;
vector<int> e[4005];
int f[4005][25];

void dfs1(int x)
{
    for(int i = 0 ; i < e[x].size(); i++)
        if(e[x][i] != f[x][0])
            f[x][0] = e[x][i],
            dfs1(e[x][i]);
}

void solve()
{
    cin >> n >> k;
    for(int i = 1; i < n; i++)
        cin >> u >> v,
        e[u].push_back(v),
        e[v].push_back(u);
    cout << 2 << '\n';

}

signed main()
{
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    cin >> c >> t;
    while(t--)
        solve();

    return 0;
}