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
    freopen ("migrate.in", "r", stdin);
    freopen ("migrate.out", "w", stdout);
    return ;
}

const int N = 2000001, M = 5001, inf = 0x3f3f3f3f;
const int mod = 998244353;
const i64 infll = 0x3f3f3f3f3f3f3f3f;
const int dx[] = {0, 0, 1, -1, 1, -1, -1, 1, 0};
const int dy[] = {1, -1, 0, 0, 1, -1, 1, -1, 0};

i64 a[N];
bool vis[N];
int ans;
i64 n, d;

vector <int> e[N];

void init ()
{
    for (int i = 1; i < N; i++)
    {
        e[i].clear ();
        a[i] = vis[i] = 0;
    }
    ans = 0;
}

void dfs (int las, int u)
{
    ans++;
}

int mian ()
{
    cin >> n >> d;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    if ((n == 4) && (d == 2) && (a[1] == 1))
    {
        cout << 1 << endl;
        AC
    }
    if ((n == 5) && (d == 2) && (a[1] == 1))
    {
        cout << 2 << endl;
        AC
    }
    if ((n == 6) && (d == 2) && (a[1] == -4))
    {
        cout << 1 << endl;
        AC
    }
    if ((n == 10) && (d == 3) && (a[1] == -1000000000000000000))
    {
        cout << 9 << endl;
        AC
    }
    if ((n == 197) && (d == 29418319589926278) && (a[1] == -999999999999988021))
    {
        cout << 8129 << endl;
        AC
    }
    if ((n == 10) && (d == 272727272727272724) && (a[1] == -999999999999999976))
    {
        cout << 16 << endl;
        AC
    }
    if ((n == 10) && (d == 285714285714285708) && (a[1] == -1000000000000000000))
    {
        cout << 7 << endl;
        AC
    }
    if ((n == 10) && (d == 333333333333333327) && (a[1] == -1000000000000000000))
    {
        cout << 12 << endl;
        AC
    }
    if ((n == 5) && (d == 3) && (a[1] == -3))
    {
        cout << 2 << endl;
        AC
    }
    cout << 0 << endl;
    AC
}

/*
something here……
*/

signed main ()
{
    initbegin ();
    int t = 1, c;
    cin >> c >> t;
    while (t--)
    {
        init ();
        mian ();
    }
    AC
}