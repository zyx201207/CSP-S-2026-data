#include <iostream>
using namespace std;

const int MAXN = 505; // the number of ways
const int MAXM = 500005; // point

int c, n, m, d, q;

int kou_ting[MAXM];
int mapp[1005][1005];

int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    //line 1
    cin >> c >> n >> m >> d >> q;

    //line 2
    for (int i = 1; i <= m; i++)
    {
        cin >> kou_ting[i];
    }

    //line 3  -  2+n
    for (int i = 1; i <= n; i++) // ditie bianhao
    {
        int ki;
        cin >> ki;
        int ai[1005], ti[1005];

        for (int j = 1; j <= ki; j++) // zhandian
        {

            cin >> ai[j] >> ti[j];

            for (int k = 1; k <= j; k++) // jianli bian
            {
                mapp[ai[j]][ai[k]] = ti[j] + ti[k];
            }
        }
    }

    //dijkstra
    for (int i = 1; i <= m; i++)
    {
        for (int j = i; j <= m; j++)
        {
            for (int k = i; k <= j; k++)
            {
                if (mapp[i][j] != 0)mapp[i][j] = min(mapp[i][k] + mapp[k][j], mapp[i][j]);
                else mapp[i][j] = mapp[i][k] + mapp[k][j];
            }
        }
    }

    for (int i = 1; i <= q; i++)
    {
        int xr, yr;
        cin >> xr >> yr;
        cout << mapp[xr][yr] + kou_ting[xr] + kou_ting[yr] << endl;
    }
    return 0;
}