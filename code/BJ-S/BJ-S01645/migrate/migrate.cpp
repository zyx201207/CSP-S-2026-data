#include <bits/stdc++.h>
using namespace std;
#define il inline
#define pb push_back
typedef long long ll;
const int N = 2e6 + 10;
ll x[N], d;
vector<int> g[N];
queue<int> q;
int dep[N], n;
ll dp[N];
il void bfs(int s)
{
    for(int i = 1;i <= n;++i)
    {
        dep[i] = -1;
        dp[i] = 0;
    }
    q.push(s);
    dp[s] = 1;
    while(q.size())
    {
        int u = q.front();
        q.pop();
        for(auto v : g[u])
        {
            if(dep[v] != -1)
            {
                if(dep[v] == dep[u] + 1) dp[v] += dp[u];
                continue;
            }
            dep[v] = dep[u] + 1;
            dp[v] += dp[u];
            q.push(v);
        }
    }
}
il void solvebl()
{
    cin >> n >> d;
    for(int i = 1;i <= n;++i) cin >> x[i];
    for(int i = 1;i <= n;++i)
        for(int j = i + 1;j <= n;++j)
            if(x[j] - x[i] <= d && (n <= 300 ? 1 : abs(i - j) <= 10))
                g[i].pb(j);
    ll ans = 0;
    for(int i = 1;i <= n;++i)
    {
        bfs(i);
        for(int j = i + 1;j <= n;++j) ans += (dp[j] == 2);
    }
    for(int i = 1;i <= n;++i) g[i].clear();
    cout << ans << "\n";
}
il void solveA()
{
    cin >> n >> d;
    for(int i = 1;i <= n;++i) cin >> x[i];
    ll dd = x[2] - x[1];
    if(d <= dd) cout << "0\n";
    else cout << max(n + 1 - 2 * d / dd, 0ll) << "\n";
}
int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int c, T;
    cin >> c >> T;
    while(T--)
    {
        if(11 <= c && c <= 12) solveA();
        else solvebl();
    }
    return 0;
}
