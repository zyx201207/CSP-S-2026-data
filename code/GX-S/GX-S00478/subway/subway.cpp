#include<bits/stdc++.h>
using namespace std;
int w[500010];
int k[510];
int a[500][5000];
int t[500][5000];
struct st
{
    bool way[3] = {0};
    int t[5] = {0};
};
st sts[510];

int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    int c, n, m, d, q;
    cin >> c >> n >> m >> d >> q;
    for(int i = 1;i <= m;i ++)
    {
        cin >> w[i];
    }
    for(int i = 1;i <= n;i ++)
    {
        cin >> k[i];

        for(int j = 1;j <= k[i];j ++)
        {
            cin >> a[i][j] >> t[i][j];
            sts[a[i][j]].way[i] = 1;
            sts[a[i][j]].t[i] = t[i][j];
        }
    }
    for(int i = 1;i <= q;i ++)
    {
        int x, y;
        cin >> x >> y;
        int minn = INT_MAX;
        if(sts[x].way[1] && sts[y].way[1])
        {
            minn = min(sts[x].t[1] + sts[y].t[1], minn);
        }
        if(sts[x].way[2] && sts[y].way[2])
        {
            minn = min(sts[x].t[2] + sts[y].t[2], minn);
        }
        if(sts[x].way[1] && sts[y].way[2])
        {
            for(int i = 1;i <= k[1];i ++)
            {
                int s = a[1][i];
                if(sts[s].way[2])
                {
                    minn = min(minn, sts[x].t[1] + sts[s].t[1] + sts[s].t[2] + sts[y].t[2]);
                }
            }
        }
        if(sts[x].way[2] && sts[y].way[1])
        {
            for(int i = 1;i <= k[2];i ++)
            {
                int s = a[2][i];
                if(sts[s].way[1])
                {
                    minn = min(minn, sts[x].t[2] + sts[s].t[2] + sts[s].t[1] + sts[y].t[1]);
                }
            }
        }
        cout << minn + w[x] + w[y] << endl;
    }
    if(n > 200)
    {
        cout << "bu_shi_da_ge_wo_hua_560_kuai_guo_lai_kao_shi, ni_chu_zhe_me_nan_bu_rang_wo_guo,zhe_bu_nao_ma";
    }
    return 0;
}
