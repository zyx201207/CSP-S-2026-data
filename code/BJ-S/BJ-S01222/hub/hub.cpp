#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
#define int long long
using namespace std;

const int N = 1005;
int c , t , n , dp[N][N] , k1[N] , vis2[N] , vis[N] , K , ans = 1e18;
vector<int> v[N];
void flood(int x)
{
    vis[x] = 1;
    for(int i = 1; i <= K; i++) if(dp[x][k1[i]] == 1 && !vis[k1[i]]) flood(k1[i]);
}
bool check()
{
    int cnt = 0;
    memset(vis , 0 , sizeof vis);
    for(int i = 1; i <= K; i++)
        if(!vis[k1[i]]) {flood(k1[i]);cnt++;}
    return cnt <= 2;
}
void dfs(int x)
{
    //cout << x << endl;
    if(x > K)
    {
        if(check())
        {
            //(int i = 1; i <= K; i++) cout << k1[i] << " ";
            //cout << endl;
            int maxn = 0;
            for(int i = 1; i <= n; i++)
            {
                int minn = 1e18;
                for(int j = 1; j <= K; j++)
                    minn = min(minn , dp[i][k1[j]]);
                maxn = max(maxn , minn);
            }
            ans = min(ans , maxn);
        }
        return;
    }
    for(int i = 1; i <= n; i++)
    {
        if(!vis2[i])
        {
            k1[x] = i;
            vis2[i] = 1;
            dfs(x + 1);
            k1[x] = 0;
            vis2[i] = 0;
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("hub.in" , "r" , stdin);
    freopen("hub.out" , "w" , stdout);
    cin >> c >> t;
    while(t--)
    {
        cin >> n >> K;
        memset(dp , 0x3f , sizeof dp);
        ans = 1e18;
        for(int i = 1; i < n; i++)
        {
            int x , y;cin >> x >> y;
            dp[x][y] = dp[y][x] = 1;
        }
        for(int i = 1; i <= n; i++) dp[i][i] = 0;
        for(int k = 1; k <= n; k++)
            for(int i = 1; i <= n; i++)
                for(int j = 1; j <= n; j++)
                    dp[i][j] = min(dp[i][j] , dp[i][k] + dp[k][j]);
        dfs(1);
        cout << ans << endl;
    }
    return 0;
}
