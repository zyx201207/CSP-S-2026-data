#include <iostream>
#include <vector>
using namespace std;
#define int long long

int c , n , m , d , q , w[505] , v[500005] , t[500005][505] , vis[500005] , ans = 1e9;
struct stu
{
    int v , id , idk;
};
vector<stu> e[505];
void dfs(int cnt , int u , int s , int last_id , int last_idk , int sum)
{
    if (sum >= ans)
    {
        return;
    }
    if (u == s)
    {
        ans = min(ans , sum);
    }
    for (int i = 0; i < e[u].size(); i++)
    {
        if (vis[e[u][i].v])
        {
            continue;
        }
        vis[e[u][i].v] = 1;
        if (e[u][i].id == last_id)
        {
            dfs(cnt + 1 , e[u][i].v , s , e[u][i].id , e[u][i].idk , sum - t[last_id][last_idk] + t[e[u][i].id][e[u][i].idk]);
        }
        else
        {
            dfs(cnt + 1 , e[u][i].v , s , e[u][i].id , e[u][i].idk , sum + t[e[u][i].id][e[u][i].idk]);
        }
        vis[e[u][i].v] = 0;
    }
}

signed main()
{
    freopen("subway.in" , "r" , stdin);
    freopen("subway.out" , "w" , stdout);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++)
    {
        cin >> w[i];
    }
    for (int i = 1; i <= n; i++)
    {
        int k;
        cin >> k;
        for (int j = 1; j <= k; j++)
        {
            cin >> v[j] >> t[i][j];
            e[v[j - 1]].push_back({v[j] , i , j});
            e[v[j]].push_back({v[j - 1] , i , j});
        }
    }
    for (int i = 1; i <= q; i++)
    {
        int x , y;
        cin >> x >> y;
        dfs(0 , x , y , -1 , -1 , 0);
        cout << ans + w[x] + w[y] << endl;
    }
    return 0;
}
