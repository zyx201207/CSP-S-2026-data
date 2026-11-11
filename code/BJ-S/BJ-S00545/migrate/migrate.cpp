#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,T;
const int N = 5005;
int d[N][N];
int f[N][N];
int n,D;
int x[N];
vector<int> g[N];
int dis[N];
int vis[N];
void dfs(int st,int u,int ed,int len)
{
    if(d[st][ed] < len) return;
    if(u == ed)
    {
        if(d[st][ed] == len) f[st][ed]++;
        return;
    }
    if(f[st][ed] >= 3) return;
    for(auto v : g[u])
    {
        if(v > u && len == d[st][u])
        {
            dfs(st,v,ed,len + 1);
        }
    }
    return;
}
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> c >> T;
    while(T--)
    {
        cin >> n >> D;
        int ans = 0;
        for(int i = 1;i <= n;i++)
        {
            for(int j = 1;j <= n;j++)
            {
                f[i][j] = 0;
                d[i][j] = 1e8;
            }
            x[i] = 0;
            g[i].clear();
            vis[i] = 0;
        }
        for(int i = 1;i <= n;i++)
        {
            cin >> x[i];
        }
        for(int i = 1;i <= n;i++)
        {
            for(int j = i + 1;j <= n;j++)
            {
                if(abs(x[j] - x[i]) <= D)
                {
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
                else break;
            }
        }
        for(int i = 1;i <= n;i++)
        {
            for(int j = 1;j <= n;j++)
            {
                vis[j] = 0;
                dis[j] = 1e8;
            }
            dis[i] = 0;
            vis[i] = 0;
            priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
            pq.push(make_pair(dis[i],i));
            while(!pq.empty())
            {
                int u = pq.top().second;
                pq.pop();
                if(vis[u]) continue;
                vis[u] = 1;
                for(auto v : g[u])
                {
                    if(dis[v] > dis[u] + 1)
                    {
                        dis[v] = dis[u] + 1;
                        if(!vis[v])
                        {
                            pq.push(make_pair(dis[v],v));
                        }
                    }
                }
            }
            for(int j = 1;j <= n;j++)
            {
                d[i][j] = dis[j];
            }
        }

        for(int i = 1;i <= n;i++)
        {
            for(int j = i + 1;j <= n;j++)
            {
                dfs(i,i,j,0);
            }
        }
        for(int i = 1;i <= n;i++)
        {
            for(int j = i + 1;j <= n;j++)
            {
                if(f[i][j] == 2) ans++;
            }
        }
        cout << ans << '\n';
        /*for(int i = 1;i <= n;i++)
        {
            /*for(int j = i + 1;j <= n;j++)
            {
                cout << i << " " << j << " " << d[i][j] << '\n';
            }
            for(auto v : g[i]) f[i][v] = 1;
            f[i][i] = 1;
        }
        for(int l = 2;l < n;l++)
        {
            for(int a = 1;a + l <= n;a++)
            {
                int b = a + l;
                //if(!f[a][b]) continue;
                int calc = 0;
                for(int k = a + 1;k < b;k++)
                {
                    if(f[a][k] == 0 || f[k][b] == 0) continue;
                    if(d[a][k] + d[k][b] == d[a][b])
                    {
                        calc += f[k][b] * f[a][k];
                        //if(calc >= 3) calc = 3;
                        //cout << a << " " << k << " " << b << " " << f[k][b] * f[a][k] << '\n';
                    }
                }
                if(calc >= 3) calc = 3;
                f[a][b] += calc;
                if(f[a][b] == 2) ans++;
                //cout << a << " " << b << " " << f[a][b] << '\n';
            }
        }
        cout << ans << '\n';
        */

    }
    return 0;
}
