#include <iostream>
#include <cstring>
#define ll long long
using namespace std;

const int M = 1e3+5, N = 505, Q = 1e5+5, MN = M+N;
int c, n, m, d, q, a[N][M], kt[N];
ll wt[M], t[N][M];

ll dis[MN][MN];

void floyd()
{
    for (int k = 1; k <= m+n; k++)
        for (int i = 1; i <= m+n; i++)
            for (int j = i+1; j <= m+n; j++)
                if (dis[i][k] + dis[k][j] < dis[i][j])
                    dis[i][j] = dis[j][i] = dis[i][k] + dis[k][j];
}

int main()
{
    //input
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++) cin >> wt[i];
    for (int i = 1; i <= n; i++)
    {
        cin >> kt[i];
        for (int j = 1; j <= kt[i]; j++) cin >> a[i][j] >> t[i][j];
    }

    //build map station->line->station
    memset(dis, 0x3f, sizeof(dis));
    for (int i = 1; i <= m+n; i++) dis[i][i] = 0;
    for (int i = 1; i <= n; i++) // line i
    {
        for (int j = 1; j <= kt[i]; j++) // station a[i][j]
        {
            dis[m+i][a[i][j]] = dis[a[i][j]][m+i] = t[i][j];
        }
    }

    floyd();

    for (int r = 1; r <= q; r++)
    {
        int x, y;
        cin >> x >> y;
        cout << dis[x][y] + wt[x] + wt[y] << endl;
    }
    return 0;
}
