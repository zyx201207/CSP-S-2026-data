#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 505,M = 1e5 + 5;
const int inf = LONG_MAX - 1000000;
int c,n,m,d,q;
int w[M],k[N],a[N][M],t[N][M];//a[i][j] -> i line pass j,time = t[i][j]; k[i] -> i line pass station = k[i]
int dp[2005][2005];
bool vis[2005];
vector<int> v[M];
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> c >> n >> m >> d >> q;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=m;j++)
        {
            dp[i][j] = inf;
        }
    }
    for(int i=1;i<=m;i++)
    {
        cin >> w[i];
        dp[i][i] = 0;
    }
    for(int i=1;i<=n;i++)
    {
        cin >> k[i];
        for(int j=1;j<=k[i];j++)
        {
            cin >> a[i][j] >> t[i][a[i][j]];
            v[a[i][j]].push_back(i);
        }
    }
    for(int i=1;i<=n;i++)
    {
        //dfs(i,i,0);
        for(int j=1;j<=n;j++) vis[j] = false;
        queue<int> q;
        q.push(i);
        while(!q.empty())
        {
            int j = q.front();
            q.pop();
            vis[j] = true;
            //cout << i << " " << j << endl;
            for(int l=1;l<=k[j];l++)
            {
                for(auto it:v[a[j][l]])
                {
                    if(vis[it]) continue;
                    //cout << it << endl;
                    dp[i][it] = min(dp[i][it],dp[i][j] + t[j][a[j][l]] + t[it][a[j][l]]);
                    q.push(it);
                }
            }
        }
    }
    while(q--)
    {
        int x,y;
        cin >> x >> y;
        int ans = inf;
        for(int l1:v[x])
        {
            for(int l2:v[y])
            {
                ans = min(ans,dp[l1][l2] + t[l1][x] + t[l2][y]);
            }
        }
        cout << ans + w[x] + w[y] << endl;
    }
    return 0;
}
