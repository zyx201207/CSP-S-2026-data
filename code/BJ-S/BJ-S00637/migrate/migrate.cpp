#include <bits/stdc++.h>
#define int long long
using namespace std;
int c,t;
int a[305];
int dis[305][305];
int way[305][305];
signed main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> c >> t;
    while(t--)
    {
        memset(dis, 0x3f, sizeof dis);
        memset(way, 0, sizeof way);
        int n,d;
        cin >> n >> d;
        for(int i=1; i<=n; i++)
        {
            cin >> a[i];
        }
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(abs(a[i]-a[j]) <= d)
                {
                    dis[i][j] = 1;
                    dis[j][i] = 1;
                    way[i][j] = 1;
                    way[j][i] = 1;
                }
            }
        }
        for(int i=1; i<=n; i++) dis[i][i] = 0;
        for(int k=1; k<=n; k++)
        {
            for(int i=1; i<=n; i++)
            {
                for(int j=1; j<=n; j++)
                {
                    if(dis[i][j] > dis[i][k] + dis[k][j])
                    {
                        dis[i][j] = dis[i][k] + dis[k][j];
                        way[i][j] = way[i][k] * way[k][j];
                    }
                    else if(dis[i][j] == dis[i][k] + dis[k][j])
                    {
                        //cout << dis[i][j] << ' ' << dis[i][k] << ' ' << dis[k][j] << endl <<
                        //way[i][j] << ' ' << way[i][k] << ' ' << way[k][j] << endl << endl;
                        if(i != j && i != k && k != j)
                        way[i][j] += way[i][k] * way[k][j];
                    }
                }
            }
        }
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                cout << way[i][j] << ' ';
            }
            cout << endl;
        }
        int ans = 0;
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(i != j && way[i][j] == 2) ans++;
            }
        }
        cout << ans/2 << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
