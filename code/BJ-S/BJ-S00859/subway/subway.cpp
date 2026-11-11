#include <bits/stdc++.h>
using namespace std;
const int maxn = 505, maxm = 5e5 + 5;
int c, n, m, d, q, w[maxm], dp[maxn];
int G[maxn][maxn];
vector<pair<int, int>> t[maxm];
vector<int> xian[maxm];
int shortest_distance(int s, int t)
{
    memset(dp, 0x3f, sizeof(dp));
    set<int> se;
    for(auto i : xian[t]) se.insert(i);
    dp[s] = 0;
    queue<int> q;
    q.push(s);
    do
    {
        int top = q.front(); q.pop();
        for(int i = 1; i <= n; i++)
        {
            if(G[top][i])
            {
                q.push(i);
                dp[i] = min(dp[i], dp[top] + G[top][i]);
            }
        }
    }
    while(se.find(q.front()) == se.end());
    for(int i = 1; i <= n; i++) if(G[i][q.front()]) dp[q.front()] = min(dp[q.front()], dp[i] + G[i][q.front()]);
    return q.front();
}
int bfs(int s, int t)
{
    memset(dp, 0x3f, sizeof(dp));
    dp[s] = 0;
    queue<int> q;
    q.push(s);
    do
    {
        int top = q.front(); q.pop();
        for(int i = 1; i <= n; i++)
        {
            if(G[top][i])
            {
                q.push(i);
                dp[i] = min(dp[i], dp[top] + G[top][i]);
            }
        }
    }
    while(q.front() != t);
    for(int i = 1; i <= n; i++) if(G[i][t]) dp[t] = min(dp[t], dp[i] + G[i][t]);
    return dp[t];
}
int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> c >> n >> m >> d >> q;
    if(12 <= c && c <= 19)
    {
        int ans;
        for(int i = 1; i <= m; i++) cin >> w[i];
        for(int i = 1; i <= n; i++)
        {
            int k;
            cin >> k;
            while(k--)
            {
                int a, b;
                cin >> a >> b;
                ans = b;
                pair<int, int> p = make_pair(i, b);
                t[a].push_back(p);
            }
        }
        for(int i = 1; i <= m; i++)
        {
            for(int j = 0; j < t[i].size(); j++)
            {
                for(int k = 0; k < t[i].size(); k++)
                {
                    if(j == k || t[i][j].first == 0 || t[i][k].first == 0 )continue;
                    G[t[i][j].first][t[i][k].first] = 2 * t[i][j].second;
                }
            }
        }
        while(q--)
        {
            int x, y;
            cin >> x >> y;
            cout << w[x] + w[y] + bfs(x, y) + 2 * ans;
        }
        return 0;
    }
    for(int i = 1; i <= m; i++) cin >> w[i];
    for(int i = 1; i <= n; i++)
    {
        int k;
        cin >> k;
        while(k--)
        {
            int a, b;
            cin >> a >> b;
            xian[a].push_back(i);
            pair<int, int> p = make_pair(i, b);
            t[a].push_back(p);
        }
    }
    memset(G, 0x3f, sizeof(G));
    for(int i = 1; i <= m; i++)
    {
        for(int j = 0; j < t[i].size(); j++)
        {
            for(int k = 0; k < t[i].size(); k++)
            {
                if(j == k || t[i][j].first == 0 || t[i][k].first == 0 )continue;
                G[t[i][j].first][t[i][k].first] = min(G[t[i][j].first][t[i][k].first], t[i][j].second + t[i][k].second);
            }
        }
    }
    for(int i = 1; i <= n ; i++) for(int j = 1; j <= n; j++) if(G[i][j] == 0x3f3f3f3f) G[i][j] = 0;
    while(q--)
    {
        int x, y;
        cin >> x >> y;
        int ans = 0x3f3f3f3f, tot1, tot2;
        for(auto i : xian[x])
        {
            int tem = shortest_distance(i, y);
            if(ans > dp[tem])
            {
                ans = dp[tem];
                tot1 = i, tot2 = tem;
            }
        }
        cout << w[x] + w[y] + t[x][tot1].second + t[y][tot2].second + ans << "\n";
    }
    return 0;
}
