#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n, d;
    scanf("%lld %lld", &n, &d);
    //cout << n << ' ' << d << endl;
    vector<int> a(n+1);
    vector<vector<int> > g(n+1);
    for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    //cout << 1 << endl;
    for(int l = 1; l <= n; l++)
    {
        for(int r = l + 1; r <= n; r++)
        {
            if(a[l] + d >= a[r])
            {
                g[l].push_back(r);
                g[r].push_back(l);
            }
        }
    }
    /*
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j < g[i].size(); j++) cout << g[i][j] << ' ';
        cout << endl;
    }
    */
    int res = 0;
    for(int i = 1; i <= n; i++)
    {
        vector<int> dep(n+1, 0), sum(n+1, 0);
        dep[i] = 1;
        queue<int> q;
        q.push(i);
        while(q.size())
        {
            int u = q.front();
            q.pop();
            for(int _ = 0; _ < g[u].size(); _++)
            {
                int k = g[u][_];
                if(dep[k] != 0 && dep[k] < dep[u] + 1) continue;
                dep[k] = dep[u] + 1;
                if(sum[k] > 2) continue;
                sum[k]++;
                q.push(k);
            }
        }
        for(int j = 1; j <= n; j++)
        {
            //cout << i << ' ' << j << ' ' << dep[j] << ' ' << sum[j] << endl;
            if(sum[j] == 2) res++;
        }
    }
    cout << res / 2 << endl;
}
signed main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int c, t;
    scanf("%lld %lld", &c, &t);
    while(t--) solve();
    return 0;
}
