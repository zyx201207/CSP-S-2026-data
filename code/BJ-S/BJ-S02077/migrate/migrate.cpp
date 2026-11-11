#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
long long a[200010],m;
int dis[5010][5010],n;
long long cnt[5010][5010],maxnn=1e18;
vector <int> g[5010];
void bfs(int st)
{
    queue <int> q;
    for(int i=1;i<=n;i++)
    {
        dis[st][i]=1e9;
        cnt[st][i]=0;
    }
    dis[st][st]=0;
    cnt[st][st]=1;
    q.push(st);
    while(q.size())
    {
        int x=q.front();
        q.pop();
        for(int i=0;i<g[x].size();i++)
        {
            int y=g[x][i];
            if(dis[st][y]>dis[st][x]+1)
            {
                dis[st][y]=dis[st][x]+1;
                cnt[st][y]=cnt[st][x];
                q.push(y);
            }
            else if(dis[st][y]==dis[st][x]+1)   cnt[st][y]=min(maxnn,cnt[st][y]+cnt[st][x]);
        }
    }
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int C,t;
    cin >> C >> t;
    while(t--)
    {
        cin >> n >> m;
        for(int i=1;i<=n;i++)   cin >> a[i];
        for(int i=1;i<=n;i++)
        {
            //cout << i << " " << a[i+1]-a[i] << endl;
            g[i].clear();
            for(int j=i+1;j<=n&&a[j]-a[i]<=m;j++)
            {
                g[i].push_back(j);
                //cout << i << " " << j << endl;
            }
        }
        long long ans=0;
        for(int i=1;i<=n;i++)
        {
            bfs(i);
            for(int j=i+1;j<=n;j++)
            {
                //cout << i << " " << j << " " << dis[i][j] << " " << cnt[i][j] << endl;
                if(cnt[i][j]==2)    ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
