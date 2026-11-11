#include<bits/stdc++.h>
#define int long long
using namespace std;
const int inf = 1000000000000000018ll;
int c , n , m , d , q , w[500005] , k[505] , dis[505][505] , ta , tt , x , y , ans;
vector<int> a[500005] , t[500005];
signed main()
{
    freopen("subway.in" , "r" , stdin);
    freopen("subway.out" , "w" , stdout);
    ios::sync_with_stdio(0);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1 ; i <= m ; i++)
    {
        cin >> w[i];
    }
    for(int i = 1 ; i <= n ; i++)
    {
        cin >> k[i];
        for(int j = 1 ; j <= k[i] ; j++)
        {
            cin >> ta >> tt;
            a[ta].push_back(i);
            t[ta].push_back(tt);
        }
    }
    for(int i = 1 ; i <= n ; i++)
    {
        for(int j = 1 ; j <= n ; j++)
        {
            if(i == j)
            {
                dis[i][j] = 0;
            }
            else
            {
                dis[i][j] = inf;
            }
        }
    }
    for(int i = 1 ; i <= m ; i++)
    {
        for(int u = 0 ; u < a[i].size() ; u++)
        {
            for(int v = u + 1 ; v < a[i].size() ; v++)
            {
                dis[a[i][u]][a[i][v]] = min(dis[a[i][u]][a[i][v]] , t[i][u] + t[i][v]);
                dis[a[i][v]][a[i][u]] = min(dis[a[i][v]][a[i][u]] , t[i][u] + t[i][v]);
            }
        }
    }
    for(int kk = 1 ; kk <= n ; kk++)
    {
        for(int i = 1 ; i <= n ; i++)
        {
            if(kk == i)
            {
                continue;
            }
            for(int j = 1 ; j <= n ; j++)
            {
                if(kk == j || i == j)
                {
                    continue;
                }
                dis[i][j] = min(dis[i][j] , dis[i][kk] + dis[kk][j]);
            }
        }
    }
    while(q--)
    {
        cin >> x >> y;
        ans = inf;
        for(int i = 0 ; i < a[x].size() ; i++)
        {
            for(int j = 0 ; j < a[y].size() ; j++)
            {
                ans = min(ans , w[x] + w[y] + t[x][i] + t[y][j] + dis[a[x][i]][a[y][j]]);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
/*
0:53 写完，d<=20还是太考验视力了
0:55 测完大样例都过了，发现代码跑 0.7s 比较危险，相信一波。
*/
