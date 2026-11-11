#include <bits/stdc++.h>
#define ll long long
#define INF 1000000

using namespace std;

int c,T;
int n;
ll d;
ll x[5010];
vector <int> G[5010];
ll cnt[5010];
ll dis[5010];
queue <int> Q;
ll ans;

void bfs(int u)
{
    for(int i = 1; i <= n; i++)
        cnt[i] = 0, dis[i] = INF;

    dis[u] = 0;
    cnt[u] = 1;
    Q.push(u);

    while(!Q.empty())
    {
        int u = Q.front();
        Q.pop();

        for(int v : G[u])
        {
            if(dis[v] > dis[u] + 1)
            {
                dis[v] = dis[u] + 1;
                cnt[v] = cnt[u];
                Q.push(v);
            }
            else if(dis[v] == dis[u] + 1)
                cnt[v] += cnt[u];
        }
    }
}

void solve()
{
    cin >> n >> d;

    ans = 0;
    for(int i = 1; i <= n; i++)
        G[i].clear();

    for(int i = 1; i <= n; i++)
        cin >> x[i];

    for(int i = 2; i <= n; i++)
    {
        for(int j = 1; j <= i - 1; j++)
        {
            if(x[i] - x[j] <= d)
                G[i].push_back(j);
        }

        bfs(i);

        for(int j = 1; j <= i; j++)
            ans += (cnt[j] == 2 ? 1 : 0);
    }

    cout << ans << "\n";
}

int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);

    cin >> c >> T;

    while(T--)
        solve();

    return 0;
}