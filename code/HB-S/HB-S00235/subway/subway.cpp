#include <bits/stdc++.h>
using namespace std;
int c, n, m, d, q;
int e = 0;
int u[1000005], v[1000005], w[1000005];
int s[505];
int dis[1000005];
void build_edge(int n1, int n2, int value)
{
    u[++e] = n1; v[e] = n2; w[e] = value;
    u[++e] = n2; v[e] = n1; w[e] = value;
}
void bellman(int l)
{
    memset(dis, 0x3f, sizeof dis);
    dis[l] = 0;
    for(int i = 1; i < n * d; i++)
    {
        bool flag = 1;
        for(int j = 1; j <= e; j++)
        {
            if(dis[u[j]] < 0x3f3f3f3f / 2 && dis[v[j]] > w[j] + dis[u[j]])
            {
                dis[v[j]] = w[j] + dis[u[j]];
                flag = 0;
            }
        }
        if(flag)
            break;
    }
}
int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> c >> m >> n >> d >> q;
    for(int i =1; i <= n; i++)
    {
        cin >> s[i];
    }
    for(int i = 1; i <= m; i++)
    {
        int k;
        cin >> k;
        int prev = 0;
        for(int j = 1; j <= k; j++)
        {
            int a, t;
            cin >> a >> t;
            if(prev != 0)
                build_edge(a+n*(i), prev, 0);
            prev = a+n*(i);
            build_edge(a, a+n*(i), t);
        }
    }
    while(q--)
    {
        int l, r;
        cin >> l >> r;
        bellman(l);
        cout << s[l] + s[r] + dis[r] << '\n';
    }
    return 0;
}