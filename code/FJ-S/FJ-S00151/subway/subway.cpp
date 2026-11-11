#include <bits/stdc++.h>
using namespace std;
struct node
{
    int t, to;
};
vector<int> w(100005);// 地铁口到地铁站的时间
vector<node> a[20];//第i条线路中到j需要的时间
int sum = 0;
int c, n, m, d, q;
void dfs(int x, long long t, int y)
{
    if(x == y)
    {
        sum = t;
        return ;
    }
    int ans = 0;
    ans += w[x];
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j < a[i].size();j++)
        {
            int res = 0;
            if(a[i][j].to == x)
            {
                res += a[i][j].t;
                for(int k = 0;k < a[i].size();k++)
                {
                    dfs(a[i][k].to, ans + res + t, y);
                }
            }
        }
    }
    return ;
}
int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1;i <= m;i++)
    {
        cin >> w[i];
    }
    for(int i = 1;i <= n;i++)
    {
        int k;
        cin >> k;
        for(int j = 1;j <= k;j++)
        {
            int b, t;
            cin >> b >> t;
            a[i].push_back({t, b});
        }
    }
    for(int i = 1;i <= q;i++)
    {
        w.clear();
        memset(a, 1e9, sizeof(a));
        int x, y;
        cin >> x >> y;
        dfs(x, 0, y);
        cout << sum << endl;
    }
    return 0;
}
