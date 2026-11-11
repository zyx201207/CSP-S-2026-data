#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5+5;
long long w[MAXN],k[505],f[505][505],a[505],t[505];

int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin >> c >> n >> m >> d >> q;
    for(int i = 1;i <= m;i++) cin >> w[i];
    memset(f,0x3f,sizeof(f));
    for(int i = 1;i <= m;i++) f[i][i] = 0;
    for(int i = 1;i <= n;i++)
    {
        int k;
        cin >> k;
        for(int j = 1;j <= k;j++)
        {
            cin >> a[j] >> t[j];
            for(int l = 1;l < j;l++)
            {
                f[a[l]][a[j]] = min(f[a[l]][a[j]],t[l]+t[j]);
                f[a[j]][a[l]] = f[a[l]][a[j]];
            }
        }
    }
    /*for(int i = 1;i <= m;i++)
    {
        for(int j = 1;j <= m;j++)
        {
            if(f[i][j] > 100) cout << -1 << " ";
            else cout << f[i][j] << " ";
        }
        cout << endl;
    }*/
    for(int k = 1;k <= m;k++)
    {
        for(int i = 1;i <= m;i++)
        {
            for(int j = 1;j <= m;j++)
            {
                f[i][j] = min(f[i][j],f[i][k]+f[k][j]);
            }
        }
    }
    while(q--)
    {
        int x,y;
        cin >> x >> y;
        cout << w[x]+w[y]+f[x][y] << endl;
    }
    return 0;
}
