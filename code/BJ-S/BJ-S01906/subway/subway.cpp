#include<bits/stdc++.h>
using namespace std;
int tt,n,m,d,q,k;
long long w[500005];
vector<long long> sj[500005];
vector<int> che[500005],v[505],c[505];
long long dis[505][505];
bool vis[505];
inline void bfs(int st)
{
    queue<int> q;
    q.push(st);
    for(int i=1;i<=n;i++)
    {
        dis[st][i]=1e18;
        vis[i]=0;
    }
    dis[st][st]=0;
    while(!q.empty())
    {
        int now=q.front();q.pop();
        vis[now]=0;
        for(int i=0;i<v[now].size();i++)
        {
            if(dis[st][v[now][i]]>dis[st][now]+c[now][i])
            {
                dis[st][v[now][i]]=dis[st][now]+c[now][i];
                if(!vis[v[now][i]])
                {
                    vis[v[now][i]]=1;
                    q.push(v[now][i]);
                }
            }
        }
    }
    return;
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>tt>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
        cin>>w[i];
    }
    int a,t;
    for(int i=1;i<=n;i++)
    {
        cin>>k;
        for(int j=1;j<=k;j++)
        {
            cin>>a>>t;
            sj[a].push_back(t);
            che[a].push_back(i);
        }
        for(int j=1;j<=n;j++)
        {
            dis[i][j]=1e18;
        }
    }
    for(int i=1;i<=m;i++)
    {
        for(register int j=0;j<sj[i].size();j++)
        {
            for(register int k=j+1;k<sj[i].size();k++)
            {
                dis[che[i][j]][che[i][k]]=dis[che[i][k]][che[i][j]]=min(dis[che[i][j]][che[i][k]],sj[i][j]+sj[i][k]);
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            //cout<<dis[i][j]<<' ';
            if(dis[i][j]==1e18)continue;
            //cout<<'('<<i<<' '<<j<<' '<<dis[i][j]<<')'<<'\n';
            v[i].push_back(j);
            c[i].push_back(dis[i][j]);
            v[j].push_back(i);
            c[j].push_back(dis[i][j]);
        }
        //cout<<'\n';
    }
    for(int i=1;i<=n;i++)
    {
        bfs(i);
    }
    int x,y;
    long long ans=1e18;
    while(q--)
    {
        cin>>x>>y;
        ans=1e18;
        for(int i=0;i<che[x].size();i++)
        {
            for(int j=0;j<che[y].size();j++)
            {
                ans=min(ans,dis[che[x][i]][che[y][j]]+sj[x][i]+sj[y][j]);
            }
        }
        cout<<ans+w[x]+w[y]<<'\n';
    }
}
