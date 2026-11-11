#include <iostream>
#include <vector>
#include <cstring>
#include <map>
using namespace std;
int c, n, m, d, q, x[500005], k[500005];
long long dis[5005][5005];
vector<pair<long long, long long>> g[500005];
#define val first
#define w second
void init()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int k = 1; k <= n; k++)
            {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[j][k]);
            }
        }
    }
}
map<long long, long long> flag[500005], pos[500005];
int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++)
    {
        cin >> x[i];
    }
    memset(dis, 0x3f, sizeof(dis));
    vector<long long> a[500005], t[500005], line[500005];
    for (int i = 1; i <= n; i++)
    {
        cin >> k[i];
        a[i].resize(k[i]);
        t[i].resize(k[i]);
        for (int j = 0; j < k[i]; j++)
        {
            cin >> a[i][j] >> t[i][j];
            line[j].push_back(i);
            flag[i][a[i][j]] = 1;
            pos[i][a[i][j]] = j;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < k[i]; j++)
        {
            for (int k = 1; k <= n; k++)
            {
                if (i == k)
                    continue;
                if (flag[k][a[k][j]])
                    dis[i][k] = min(dis[i][k], 2 * t[i][j]);
            }
        }
    }
    init();
    while (q--)
    {
        int start, end;
        cin >> start >> end;
        long long ans = 0x3f3f3f3f3f3f3f3f;
        for (int i = 0; i < line[start].size(); i++)
        {
            for (int j = 0; j < line[end].size(); j++)
            {
                if ((line[i] == line[j]))
                {
                    ans = 0;
                    break;
                }
                ans = min(ans, dis[line[start][i]][line[start][j]] + t[line[start][i]][pos[line[start][i]][start]] + t[line[start][j]][pos[line[start][j]][end]]);
            }
        }
        cout << ans + x[start] + x[end];
    }
    return 0;
}
