#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M = 5e5 + 10;
int w[M];
int k[M];
int a[510][1010];
int t[510][1010];
struct node
{
    int v , w , id1 , id2;
};
vector<node> g[1010];
int st , ed;
// bool vis[210];
int dis[210];
void dfs(int x , int yid)
{
    if (x == ed)
    {
        return ;
    }
    for (auto i : g[x])
    {
        // if (i.v == ed)
        // {
        //     dis[ed] = min(dis[ed] , dis[x]);
        //     continue;
        // }
        int nd = dis[x] + i.w;
        // if (x == st)
        // {
        //     nd += t[i.id1][i.id2];
        // }
        if (i.id1 != yid)
        {
            nd += t[i.id1][i.id2];
        }
        if (dis[i.v] <= nd)
        {
            continue;
        }
        dis[i.v] = nd;
        // vis[i.v] = 1;
        dfs(i.v , i.id1);
        // vis[i.v] = 0;
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("subway.in" , "r" , stdin);
    freopen("subway.out" , "w" , stdout);
    int c , n , m , d , q;
    cin >> c >> n >> m >> d >> q;
    for (int i = 1 ; i <= m ; i++)
    {
        cin >> w[i];
    }
    for (int i = 1 ; i <= n ; i++)
    {
        cin >> k[i];
        for (int j = 1 ; j <= k[i] ; j++)
        {
            cin >> a[i][j] >> t[i][j];
            for (int kk = 1 ; kk < j ; kk++)
            {
                g[a[i][kk]].push_back({a[i][j] , t[i][j] , i , kk});
                g[a[i][j]].push_back({a[i][kk] , t[i][kk] , i , j});
            }
        }
    }
    while (q--)
    {
        cin >> st >> ed;
        // memset(vis , 0 , sizeof vis);
        memset(dis , 0x3f , sizeof dis);
        // vis[st] = 1;
        dis[st] = 0;
        dfs(st , 0);
        cout << dis[ed] + w[st] + w[ed] << endl;
    }
    return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7 
1 3
1 2

*/