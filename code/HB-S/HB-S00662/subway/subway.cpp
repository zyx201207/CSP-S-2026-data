#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 5e5 + 2;

struct sta
{
    int t1;
    vector <int> b, t2;
    void push(int x, int y)
    {
        b.push_back(x);
        t2.push_back(y);
    }
    int size()
    {
        return b.size();
    }
};
sta s[N];

struct node
{
    int v, w;
};
vector <node> e[502];

vector <int> l[502];
int c, n, m, d, q;
ll dis[502][502];

void floyed()
{
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            if(i != j) dis[i][j] = (ll)0x7fffffff;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j < e[i].size(); j++)
        {
            for(int k = 1; k <= n; k++)
            {
                if(i == k || e[i][j].v == k)
                    continue;
                if(dis[i][k] + dis[k][e[i][j].v] < dis[i][e[i][j].v])
                    dis[i][e[i][j].v] = dis[i][k] + dis[k][e[i][j].v];
            }
        }
    }
}

int main()
{
    // freopen("subway.in", "r", stdin);
    // freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1; i <= m; i++)
        cin >> s[i].t1;
    for(int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        for(int j = 1; j <= x; j++)
        {
            int a, b;
            cin >> a >> b;
            l[i].push_back(a);
            for(int k = 0; k < s[a].size(); k++)
            {
                e[i].push_back({s[a].b[k], s[a].t2[k] + b});
                e[s[a].b[k]].push_back({i, s[a].t2[k] + b});
                dis[i][s[a].b[k]] = s[a].t2[k] + b;
                dis[s[a].b[k]][i] = s[a].t2[k] + b;
            }
            s[a].push(i, b);
        }
    }
    floyed();
    for(int i = 1; i <= q; i++)
    {
        int a, b;
        cin >> a >> b;
        ll ans = 0x7fffffff;
        for(int j = 0; j < s[a].size(); j++)
            for(int k = 0; k < s[b].size(); k++)
                ans = min(ans, dis[j][s[b].b[k]]);
        cout << ans << '\n';
    }
    return 0;
}