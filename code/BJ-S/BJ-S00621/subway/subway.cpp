#include <iostream>
#include <vector>
using namespace std;

int c, n, m, d, q;
vector <int> a[500010];
vector <int> t1[500010];
vector <int> b[500010];
vector <int> t2[500010];
int w[500010];
int aa[1010][1010];

void l(int x)
{
    for (int i = 0; i < a[x].size(); i++)
    {
        int g = a[x][i];
        for (int j = 0; j < b[g].size(); j++)
        {
            int h = b[g][j];
            aa[x][h] = min(aa[x][h], t1[x][i] + t2[g][j]);
            aa[h][x] = aa[x][h];
        }
    }
}

int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++) cin >> w[i];
    for (int i = 1; i <= n; i++)
    {
        int k;
        cin >> k;
        for (int j = 1; j <= k; j++)
        {
            int x, y;
            cin >> x >> y;
            a[x].push_back(i);
            t1[x].push_back(y);
            b[i].push_back(x);
            t2[i].push_back(y);
        }
    }
    for (int i = 1; i <= m; i++) for (int j = 1; j <= m; j++) aa[i][j] = 1e9;
    for (int i = 1; i <= m; i++) l(i);
    for (int i = 1; i <= m; i++) for (int j = 1; j <= m; j++) for (int k = 1; k <= m; k++) aa[i][j] = min(aa[i][j], aa[i][k] + aa[k][j]);
    for (int i = 1; i <= q; i++)
    {
        int x, y;
        cin >> x >> y;
        int ans = w[x] + w[y];
        ans += aa[x][y];
        cout << ans << endl;
    }
    return 0;
}