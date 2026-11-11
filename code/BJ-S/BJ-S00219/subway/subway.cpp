#include <bits/stdc++.h>
using namespace std;

long long a[1010][1010],t[1010][1010],b[505050];
long long c,n,m,d,q,w[512],k[512],T,s,e,minn = 1e12;

int main ()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; ++i)
    {
        cin >> w[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        cin >> k[i];
        for (int j = 1; j <= k[i]; ++j)
        {
            cin >> a[i][j] >> t[i][j];
            b[a[i][j]] += i;
            if (i == 1 && j == 1)
            {
                T = t[i][j];
            }
            else
            {
                if (T != t[i][j])
                {
                    T = -1;
                }
            }
        }
    }
    while(q--)
    {
        cin >> s >> e;
        if (n == 1)
        {
            cout << w[s] + w[e] + t[1][s] + t[1][e] << endl;
            continue;
        }
        if (n == 2)
        {
            int x = b[s],y = b[e],d = 0;
            if (x == y)
            {
                cout << w[s] + w[e] + t[x][s] + t[y][e] << endl;
                continue;
            }
            for (int i = 1; i <= m; ++i)
            {
                if (b[i] < 3)
                {
                    continue;
                }
                if (minn > t[x][i] + t[y][i])
                {
                    minn = t[x][i] + t[y][i];
                    d = i;
                }
            }
            //cout << d << " " << t[x][d] << " " << t[y][d] << " " << minn << endl;
            cout << minn + w[s] + w[e] + t[x][s] + t[y][e] << endl;
            continue;
        }
    }
    return 0;
}
