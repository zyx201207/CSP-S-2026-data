#include <bits/stdc++.h>
using namespace std;
long long c , n , m , d , q , w[500010] , a[510][510];
pair<int , long long> way[500010][30];
vector<pair<int , long long>> e[500010];
int main()
{
    freopen("subway.in" , "r" , stdin);
    freopen("subway.out" , "w" , stdout);
    memset(a , 0x3f3f , sizeof(a));
    cin >> c >> n >> m >> d >> q;
    for(int i = 1;i <= m;i++) cin >> w[i];
    for(int i = 1;i <= n;i++)
    {
        a[i][i] = 0;
        int k;
        cin >> k;
        for(int j = 1;j <= k;j++)
        {
            int id;
            long long t;
            cin >> id >> t;
            way[id][++way[id][0].first].first = i;
            way[id][way[id][0].first].second = t;
            for(pair<int , long long> u : e[id])
                a[i][u.first] = a[u.first][i] = min(a[i][u.first] , u.second + t);
            e[id].push_back({i , t});
        }
    }
    for(int i = 1;i <= n;i++)
    {
        for(int k = 1;k <= n;k++)
        {
            for(int j = 1;j <= n;j++)
                if(i != j && j != k && i != k) a[i][j] = min(a[i][j] , a[i][k] + a[k][j]);
        }
    }
    while(q--)
    {
        int x , y;
        long long ans = 1e18;
        cin >> x >> y;
        for(int i = 1;i <= way[x][0].first;i++)
        {
            for(int j = 1;j <= way[y][0].first;j++)
            {
                pair<int , long long> s = way[x][i] , t = way[y][j];
                ans = min(ans , w[x] + w[y] + s.second + t.second + a[s.first][t.first]);
            }
        }
        cout << ans << endl;
    }
    return 0;
}