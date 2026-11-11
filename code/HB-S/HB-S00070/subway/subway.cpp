#include <bits/stdc++.h>

using namespace std;

const int K = 21;
const int N = 505;
const int M = 5e5 + 5;

int c;
int n;
int m;
int D;
int q;
int f[N];
int k[N];
int w[M];
int d[N][N];
int a[N][K];
int t[N][K];
vector<int> la[M];

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    freopen ("subway.in", "r", stdin);
    freopen ("subway.out", "w", stdout);

    cin >> c >> n >> m >> D >> q;

    for (int i = 1; i <= m; i++)
        cin >> w[i];

    for (int i = 1; i <= n; i++)
    {
        cin >> k[i];

        for (int j = 1; j <= k[i]; j++)
        {
            cin >> a[i][j] >> t[i][j];

            la[a[i][j]].push_back(i);
        }
    }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i != j)
                d[i][j] = 0x3f3f3f3f;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= k[i]; j++)
            for (int x = i+1; x <= n; x++)
                for (int y = 1; y <= k[x]; y++)
                    if (i != x)
                        if (a[i][j] == a[x][y])
                            d[i][x] = d[x][i] = min(t[i][j]+t[x][y], d[i][x]);

    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

    while (q--)
    {
        int x;
        int y;

        cin >> x >> y;

        int ans = w[x] + w[y];

        int tot = 0x3f3f3f3f;

        for (int l1 : la[x])
            for (int l2 : la[y])
            {
                int t1 = 0;
                int t2 = 0;

                for (int i = 1; i <= k[l1]; i++)
                    if (a[l1][i] == x)
                    {
                        t1 = t[l1][i];

                        break;
                    }

                for (int i = 1; i <= k[l2]; i++)
                    if (a[l2][i] == y)
                    {
                        t2 = t[l2][i];

                        break;
                    }

                tot = min(tot, d[l1][l2] + t1 + t2);
            }

        cout << tot + ans << "\n";
    }

    return 0;
}