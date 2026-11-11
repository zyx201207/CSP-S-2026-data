#include <bits/stdc++.h>
using namespace std;
const int N = 15, INF = 0x3f3f3f3f;
int C, T, n, k, ans;
int e[N * 2], ne[N * 2], h[N], idx;
int p[N], st[N];

void init()
{
    idx = 0;
    for (int i = 1; i <= n; i ++ ) h[i] = -1;
}

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

int find(int u)
{
    if (p[u] != u) p[u] = find(p[u]);
    return p[u];
}

int dfs1(int u, int fa)
{
    if (st[u]) return 0;
    int res = INF;
    for (int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];
        if (j == fa) continue;
        res = min(res, 1 + dfs1(j, u));
    }
    return res;
}

void dfs(int x, int cnt)
{
    if (n - x + 1 + cnt < k) return;
    if (cnt == k)
    {
        int res = 0;
        for (int i = 1; i <= n; i ++ ) p[i] = i;
        for (int i = 1; i <= n; i ++ )
            if (st[i])
            {
                for (int j = h[i]; j != -1; j = ne[j])
                {
                    int k = e[j];
                    if (st[k])
                    {
                        int px = find(k), py = find(i);
                        if (px != py) p[px] = py;
                    }
                }
            }
        int o = 0;
        for (int i = 1; i <= n; i ++ ) if (st[i] && find(i) == i) o ++ ;
        if (o > 2) return; 
        for (int i = 1; i <= n; i ++ ) res = max(res, dfs1(i, -1));
        ans = min(ans, res);
        return;   
    }
    st[x] = 1;
    dfs(x + 1, cnt + 1);
    st[x] = 0;
    dfs(x + 1, cnt);
}

int main()
{
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    cin >> C >> T;
    while (T -- )
    {
        ans = INF;
        cin >> n >> k;
        init();
        for (int i = 1; i <= n - 1; i ++ ) 
        {
            int a, b;
            cin >> a >> b;
            add(a, b), add(b, a);
        }
        dfs(1, 0);
        cout << ans << '\n';
    }

    return 0;
}
