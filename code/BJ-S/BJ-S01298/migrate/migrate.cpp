#include<bits/stdc++.h>
using namespace std;
int n;
long long d;
long long x[5010];
int dis[5010][5010],cnt[5010][5010];
vector<int> G[5010];
queue<int> q;
long long ans=0;
void bfs(int st)
{
    dis[st][st]=0;
    cnt[st][st]=1;
    q.push(st);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(auto v:G[u])
        {
            if(dis[st][v]==1e9)
            {
                dis[st][v]=dis[st][u]+1;
                q.push(v);
            }
            if(dis[st][u]+1==dis[st][v])
            {
                cnt[st][v]+=cnt[st][u];
            }
        }
    }
    for(int i=st+1;i<=n;i++)
    {
        if(cnt[st][i]==2) ans++;
    }
    return ;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int t;
    cin>>t>>t;
    while(t--)
    {
        cin>>n>>d;
        for(int i=1;i<=n;i++)
        {
            cin>>x[i];
            G[i].clear();
        }
        ans=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                dis[i][j]=1e9;
                cnt[i][j]=0;
                if(x[j]-x[i]<=d)
                {
                    G[i].push_back(j);
                }
            }
        }
        for(int i=1;i<=n;i++) bfs(i);
        cout<<ans<<endl;
    }
    return 0;
}
