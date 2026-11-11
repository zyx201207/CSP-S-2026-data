#include <iostream>
#include <vector>
using namespace std;

const int N = 1e6;
int n, k;
vector<int> tree[N + 5];

int dist(int u, int fa, int w)
{
    if (u == w) return 0;
    for (int v : tree[u])
    {
        if (v != fa)
        {
            int res = dist(v, u, w);
            if (res != -1) return res + 1;
        }
    }
    return -1;
}

int find(int u, int w)
{
    for (int v : tree[u])
        if (dist(v, u, w) != -1)
            return v;
    return -1;
}

int spread(int u, int fa, int len, int &cnt)
{
    // cout << u << " " << fa << endl;
    int h = 0;
    for (int v : tree[u])
    {
        if (v != fa)
        {
            int curh = spread(v, u, len, cnt);
            if (curh >= len)
            {
                // cout << v << endl;
                ++cnt;
            }
            h = max(h, curh + 1);
        }
    }

    return h;
}

bool check(int len)
{
    for (int i = 1; i <= n; ++i)
    {
        // for (int j = i + 1; j <= n; ++j)
        {
            // if (dist(i, 0, j) > 2 * len + 1) continue;
            // int i_to_j = find(i, j);
            // int j_to_i = find(j, i);

            int cnt = 1;
            spread(i, 0, len, cnt);
            // spread(j, j_to_i, len, cnt);

            // cout << i << " " << j << ": " << cnt << endl;
            if (cnt <= k) return true;
        }
    }

    return false;
}

int main()
{
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int c, t;
    cin >> c >> t;
    while (t--)
    {
        cin >> n >> k;
        for (int i = 1; i <= n; ++i) tree[i].clear();

        for (int i = 1; i <= n - 1; ++i)
        {
            int u, v;
            cin >> u >> v;
            tree[u].push_back(v);
            tree[v].push_back(u);
        }

        // check(1);
        int l = 0;
        int r = n;
        while (l < r)
        {
            int mid = l + r >> 1;
            if (check(mid)) r = mid;
            else l = mid + 1;
        }
        cout << l << endl;
    }

    return 0;
}