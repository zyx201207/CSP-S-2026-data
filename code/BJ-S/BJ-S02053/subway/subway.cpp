# include <bits/stdc++.h>
using namespace std;
# define ll long long
ll ce, n, m, d, qr, x, k, y;
ll g[500100], c[500100], vis[500100];
vector<pair<ll, ll> > v[1500000];
priority_queue<pair<ll, ll>, vector<pair<ll, ll> >, greater<pair<ll, ll> > > q;
int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> ce >> n >> m >> d >> qr;
    for (int i = 1; i <= m; i ++)
    {
        cin >> g[i];
    }
    for (int i = 1; i <= n; i ++)
    {
        cin >> k;
        for (int j = 1; j <= k; j ++)
        {
            cin >> x >> y;
            v[x].push_back({y, m+i});
            v[m+i].push_back({y, x});
        }
    }
    int s, t;
    /*for (int i = 1; i <= n; i ++)
    {
        for (auto j : v[i]) cout << j.first << " " << j.second << endl;
    }*/
    for (int i = 1; i <= qr; i ++)
    {
        cin >> s >> t;
        for (int i = 1; i <= m+n; i ++) {c[i] = 2100000000; vis[i] = false;}
        c[s] = g[s];
        q.push({0, s});
        while (!q.empty())
        {
            int va = q.top().first, pl = q.top().second;
            //cout << pl << endl;
            q.pop();
            vis[pl] = true;
            for (auto i : v[pl])
            {
                //cout << i.first << " " << pl << " " << c[pl] << " " << i.second << " " << c[i.second] << " " << vis[i.second] << endl;
                if ((!vis[i.second]) && (c[pl] + i.first < c[i.second]))
                {
                    q.push({c[pl] + i.first, i.second});
                    c[i.second] = c[pl] + i.first;
                }
            }
        }
        cout << c[t] + g[t] << endl;
    }

    return 0;
}
