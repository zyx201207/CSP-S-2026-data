#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define inl __attribute((always_inline)) inline
typedef pair<int, pair<int, int>> pii;
const int N = 5e5 + 10, M = 510;
inl int read()
{
    int x = 0, f = 1;
    char c = getchar();
    while (!isdigit(c))
    {
        if (c == '-')
            f = -1;
        c = getchar();
    }
    while (isdigit(c))
    {
        x = x * 10 + (c - '0');
        c = getchar();
    }
    return x * f;
}
int c, n, m, d, q; // 測試點，地鐵站數，地鐵綫數，一地鐵站最多被幾條綫經過，詢問數
int val[N], t[N][21];
int w[M << 1], e[M << 1], ne[M << 1], h[N], idx;
int dist[N], id[N];
bool st[N];
inl void add(int a, int b, int c)
{
    w[idx] = c, e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
inl int dij(int root, int des)
{
    memset(st, 0, sizeof st);
    memset(dist, 0x3f, sizeof dist);
    priority_queue<pii, vector<pii>, greater<pii>> q;
    dist[root] = 0;
    q.push({0, {root, -1}});
    int state = 0;
    while (q.size())
    {
        auto r = q.top();
        q.pop();
        int val = r.first, u = r.second.first, state = r.second.second;
        if (st[u])
            continue;
        st[u] = true;
        for (int i = h[u]; ~i; i = ne[i])
        {
            int v = e[i];
            int idu = id[v];
            int cost = w[i];
            if (idu == state)
                cost -= t[id[u]][u] * 2;
            else
                state = idu;
            if (dist[v] > dist[u] + w[i])
            {
                dist[v] = dist[u] + w[i];
                q.push({dist[v], {v, id[v]}});
            }
        }
    }
    return dist[des];
} // 將站厛設置為點
vector<int> line[N];
signed main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    memset(h, -1, sizeof h);
    c = read(), m = read(), n = read(), d = read(), q = read();
    for (int i = 1; i <= n; i++)
        cin >> val[i];

    for (int i = 1; i <= m; i++)
    {
        int k = read();
        line[i].push_back(-1);
        for (int j = 1; j <= k; j++)
        {
            int x = read(), v = read();
            line[i].push_back(x);
            t[i][x] = v;
        }
    }
    for (int i = 1; i <= m; i++)
    {
        for (int x : line[i])
            cout << x << ' ';
        cout << '\n';
    }
    // cout << t[1][1] << ' ' << t[1][2] << '\n';

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j < line[i].size() - 1; j++)
        {
            int a = line[i][j], b = line[i][j + 1];
            cout << a << ' ' << b << ' ';
            int v1 = t[i][a], v2 = t[i][b];
            int val = v1 + v2;
            cout << val << '\n';
            add(a, b, val), add(b, a, val);
            id[a] = id[b] = i;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = h[i]; ~j; j = ne[j])
        {
            int k = e[j];
            cout << i << ' ' << k << ' ' << w[i] << '\n';
        }
    }
    while (q--)
    {
        int a = read(), b = read();
        cout << val[a] + val[b] + dij(a, b) << '\n';
    }
    return 0;
}
