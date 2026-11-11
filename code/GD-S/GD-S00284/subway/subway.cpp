#include <bits/stdc++.h>
#define i64 long long
#define ull unsigned i64
#define AC return 0;
using namespace std;

void initbegin ()
{
    ios::sync_with_stdio (0);
    cin.tie (0);
    cout.tie (0);
    freopen ("subway.in", "r", stdin);
    freopen ("subway.out", "w", stdout);
    return ;
}

const int N = 1919810, M = 5001, inf = 0x3f3f3f3f;
const int mod = 998244353;
const i64 infll = 0x3f3f3f3f3f3f3f3f;
const int dx[] = {0, 0, 1, -1, 1, -1, -1, 1, 0};
const int dy[] = {1, -1, 0, 0, 1, -1, 1, -1, 0};

int w[N], k[N];

struct S {
    int a, t;
} s[M][M];

struct SS {
    int v, w;
};

vector <SS> e[N];

// vector <S> mp[N];
vector <int> mp[N];

int dfs (int a, int b, int la)
{
    if (a == b)
    {
        return 0;
    }
    int ans = inf;
    for (int i = 0; i < e[a].size (); i++)
    {
        int v = e[a][i].v, t = e[a][i].w;
        if (v == la)
        {
            continue;
        }
        ans = min (ans, dfs (v, b, a) + t);
    }
    return ans;
}

int mian ()
{
    int c, n, m, d, q;
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++)
    {
        cin >> w[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> k[i];
        for (int j = 1; j <= k[i]; j++)
        {
            cin >> s[i][j].a >> s[i][j].t;
            mp[s[i][j].a].push_back (i);
        }
        // for (int j = 1; j < k[i]; j++)
        // {
        //     e[s[i][j].a].push_back ((SS){s[i][j + 1].a, s[i][j].t});
        // }
    }
    // cout << 1;
    // for (int kkk = 1; kkk <= m; kkk++)
    // {
        // for (int i = 0; i < mp[kkk].size (); i++)
        // {
            // e[kkk].push_back ((SS){e[mp[kkk][i].a][mp[kkk][i].t].v, e[mp[kkk][i].a][mp[kkk][i].t].w});
        // }
    // }
    // for (int i = 0; i < e[1].size (); i++)
    // {
        // cout << e[1][i].v << " " << e[1][i].w << "\n";
    // }
    while (q--)
    {
        int x, y, ans = 0;
        cin >> x >> y;
        int id = mp[x][0];
        for (int i = 1; i <= k[id]; i++)
        {
            ans += s[id][i].t;
        }
        cout << ans + w[x] + w[y] << endl;
        // cout << w[x] + w[y] + ;
    }
    AC
}

/*
something here……
*/

signed main ()
{
    initbegin ();
    int t = 1;
    // cin >> t;
    while (t--)
    {
        mian ();
    }
    AC
}



















/*
#include <bits/stdc++.h>
#define i64 long long
#define ull unsigned i64
#define AC return 0;
using namespace std;

void initbegin ()
{
    ios::sync_with_stdio (0);
    cin.tie (0);
    cout.tie (0);
    // freopen ("subway.in", "r", stdin);
    // freopen ("subway.out", "w", stdout);
    return ;
}

const int N = 1919810, M = 5001, inf = 0x3f3f3f3f;
const int mod = 998244353;
const i64 infll = 0x3f3f3f3f3f3f3f3f;
const int dx[] = {0, 0, 1, -1, 1, -1, -1, 1, 0};
const int dy[] = {1, -1, 0, 0, 1, -1, 1, -1, 0};

int w[N], k[N];

struct S {
    int a, t;
} s[M][M];

vector <int> e[N];

int dfs (int a, int b, int la, int ii)
{
    if (a == b)
    {
        AC
    }
    int ans = 0, cc = 0;
    for (int kk = 0; kk < e[a].size (); kk++)
    {
        int id = e[a][kk];
        if (id != ii)
        {
            cc = s[id][kk].t + s[ii][kk].t;
        }
        for (int i = 1; i <= k[id]; i++)
        {
            if (s[id][i].a == a)
            {
                if (s[id][i - 1].a != la)
                {
                    ans = min (ans, dfs (s[id][i - 1].a, b, a, ii) + s[id][i - 1].t + cc);
                }
                if (s[id][i + 1].a != la)
                {
                    ans = min (ans, dfs (s[id][i + 1].a, b, a, ii) + s[id][i + 1].t + cc);
                }
            }
        }
    }
    return ans;
}

int mian ()
{
    int c, n, m, d, q;
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++)
    {
        cin >> w[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> k[i];
        for (int j = 1; j <= k[i]; j++)
        {
            cin >> s[i][j].a >> s[i][j].t;
            e[s[i][j].a].push_back (i);
        }
    }
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        for (int i = 0; i < e[x].size (); i++)
        {
            cout << w[x] + dfs (x, y, 0, e[x][i]) + w[y] << endl;
        }
    }
    AC
}

signed main ()
{
    initbegin ();
    int t = 1;
    // cin >> t;
    while (t--)
    {
        mian ();
    }
    AC
}
*/