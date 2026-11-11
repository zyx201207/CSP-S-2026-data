#include<cmath>
#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 20;

int ans;
int n,k;
bool f[N];
bool vis[N];
int d[N][N];
vector<int> v[N];

void flood(int x)
{
    vis[x] = 1;
    for(int i = 0; i < v[x].size(); i++)
    {
        int y = v[x][i];
        if(!vis[y] && f[y]) flood(y);
    }
}

void dfs(int x,int cnt)
{
    if(cnt + n - x + 1 < k) return;
    if(cnt > k) return;
    if(cnt == k)
    {
        for(int i = 1; i <= n; i++)
            vis[i] = 0;
        int tot = 0;
        for(int i = 1; i <= n; i++)
        {
            if(!vis[i] && f[i])
            {
                flood(i);
                tot++;
                if(tot > 2) return;
            }
        }
        int w = 0;
        for(int i = 1; i <= n; i++)
        {
            if(f[i]) continue;
            int t = n + 1;
            for(int j = 1; j <= n; j++)
                if(f[j]) t = min(t,d[i][j]);
            w = max(w,t);
        }
        ans = min(ans,w);
    }
    if(x > n) return;
    dfs(x + 1,cnt);
    f[x] = 1;
    dfs(x + 1,cnt + 1);
    f[x] = 0;
}

void solve(int c)
{
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
            d[i][j] = n + 1;
        d[1][1] = 0;
    }
    for(int i = 1; i < n; i++)
    {
        int x,y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
        d[x][y] = 1;
        d[y][x] = 1;
    }
    for(int k = 1; k <= n; k++)
    {
        for(int i = 1; i <= n; i++)
        {
            if(d[i][k] == n + 1 || i == k) continue;
            for(int j = 1; j <= n; j++)
                if(d[i][k] + d[k][j] < d[i][j]) d[i][j] = d[i][k] + d[k][j];
        }
    }
    ans = n + 1;
    dfs(1,0);
    cout << ans << "\n";
    for(int i = 1; i <= n; i++)
        v[i].clear();
}

int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int c,t;
    cin >> c >> t;
    while(t--) solve(c);
    return 0;
}
