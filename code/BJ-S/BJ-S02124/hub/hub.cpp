#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int N = 100010;
vector<int> g[N];
int n, k;
int cnt;
void dfs(int u, int fa. int lim)
{
    if(d == 0)
    {
        cnt++;
        return;
    }
    for(int v : g[u])
    {
        if(v == fa){
            continue;
        }
        dfs(v, u, d - 1, lim);
    }

    high[u] = -le9;
    have[u] = -le9;
    for(int v : g[u])
    {
        if(v == fa)
        dfs(v, u);
        high[u] = max(high[u], high[v] + 1);
        have[u] = max(have[u], have[v] - 1);
    }
    if(high[u] == R)
    {

        have[u] = R;
        high[u] = -1le9;
    }
    if(have[u] < 0 && high[u] < 0){
        high[u] = 0;
    }
}
bool check(int mid)
{
    int maxl = 0;
    for(int i = 1; i<=n; i++)
    {
        cnt = 0;
        dfs(i, 0, mid, mid);
        maxl = max(maxl, cnt);
    }
    if(maxl >= k){
        return true;
    }
    for(int u = 1; u <= n; u++)
    {
        for (int v : g[u])
        {
            int c1 = 0; c2 = 0;
            dfs(u, v, mid, mid);
            c1 = cnt;
            dfs(v, u, mid, mid);
            c2 = cnt;
            if(c1 + c2 >= k){
                return true;
            }
        }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("hup.in", "r",stdin);
    freopen("hup.out", "w",stdout);
    int c, t;
    cin >> c >> t;
    while(t--)
    {

        cin >> n >>k;
        for(int int i = 1; i <= n; i++){
            g[i].clear;
        }
        for(int i = 1; i <= n - 1; i++)
        {

            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        int l = 0, r = n, ans = n;
        while(l <= r)
        {
            int m = (l + r) / 2;
            if(ok(m))
            {

                ans = m;
                r = m - 1;
            }
            else
            {
                l = m + 1;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
