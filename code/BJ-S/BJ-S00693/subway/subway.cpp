#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 505, MAXM = 5e5 + 5, MAXD = 25, INF = 1e18;
int c, n, m, d, q, c1, c2, w[MAXM], k[MAXN], cnt[MAXM], sub[MAXM][MAXD], a[MAXM][MAXD], dis[MAXN][MAXN], dis2[MAXN][MAXN];
bool inq[MAXN];
vector<int> v[MAXN];
inline void scan(int &x)
{
    x = 0;
    char c = getchar();
    while (!isdigit(c)) c = getchar();
    while (isdigit(c)) x = x * 10 + c - 48, c = getchar();
}
void print(int x)
{
    if (x > 9) print(x / 10);
    putchar(x % 10 + 48);
}
signed main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    scan(c), scan(n), scan(m), scan(d), scan(q);
    for (int i = 1; i <= m; i++) scan(w[i]);
    for (int i = 1; i <= n; i++)
    {
        scan(k[i]);
        for (int j = 1; j <= k[i]; j++) scan(c1), scan(c2), cnt[c1]++, sub[c1][cnt[c1]] = i, a[c1][cnt[c1]] = c2;
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i != j)
                dis[i][j] = INF;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= cnt[i]; j++)
            for (int l = j + 1; l <= cnt[i]; l++)
                dis[sub[i][j]][sub[i][l]] = dis[sub[i][l]][sub[i][j]] = min(dis[sub[i][j]][sub[i][l]], a[i][j] + a[i][l]);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (dis[i][j] != INF)
                v[i].push_back(j), v[j].push_back(i);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i != j)
                dis2[i][j] = INF;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++) inq[j] = 0;
        queue<int> que;
        dis2[i][i] = 0, inq[i] = 1, que.push(i);
        while (!que.empty())
        {
            int x = que.front(); que.pop();
            for (auto &j : v[x])
                if (dis2[i][x] + dis[x][j] < dis2[i][j])
                {
                    dis2[i][j] = dis2[i][x] + dis[x][j];
                    if (!inq[j]) inq[j] = 1, que.push(j);
                }
        }
    }
    while (q--)
    {
        scan(c1), scan(c2);
        int ans = INF;
        for (int i = 1; i <= cnt[c1]; i++)
            for (int j = 1; j <= cnt[c2]; j++)
                ans = min(ans, w[c1] + w[c2] + a[c1][i] + a[c2][j] + dis2[sub[c1][i]][sub[c2][j]]);
        print(ans), putchar('\n');
    }
    return 0;
}