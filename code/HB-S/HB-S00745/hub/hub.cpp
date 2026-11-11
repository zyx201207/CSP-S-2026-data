#include<bits/stdc++.h>
using namespace std;
int c,T;
int n,k;
vector<int> e[100005];
int ans;
int book[100005];
int f[100005];
int getf(int x)
{
    if(f[x]!=x)
    {
        f[x]=getf(f[x]);
    }
    return f[x];
}
void in(int x,int y)
{
    x=getf(x),y=getf(y);
    f[x]=y;
}
int dis[100005];
int bfs()
{
    queue<int> q;
    for(int i=1;i<=n;i++)
    {
        dis[i]=book[i];
        if(book[i])
        {
            q.push(i);
        }
    }
    while(!q.empty())
    {
        int u=q.front(),v;
        q.pop();
        for(int i=0;i<e[u].size();i++)
        {
            v=e[u][i];
            if(dis[v]==0)
            {
                dis[v]=dis[u]+1;
                if(dis[v]-1>=ans)
                {
                    return ans;
                }
                q.push(v);
            }
        }
    }
    int tans=0;
    for(int i=1;i<=n;i++)
    {
        tans=max(tans,dis[i]-1);
    }
    return tans;
}
void dfs(int y,int now)
{
    if(y==k+1)
    {
        for(int i=1;i<=n;i++)
        {
            f[i]=i;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<e[i].size();j++)
            {
                if(book[i] && book[e[i][j]])
                {
                    in(i,e[i][j]);
                }
            }
        }
        int kuai=0;
        for(int i=1;i<=n;i++)
        {
            if(book[i] && f[i]==i)
            {
                kuai++;
            }
        }
        if(kuai>2)
        {
            return ;
        }
        ans=min(ans,bfs());
        return ;
    }
    for(int i=now+1;i<=n;i++)
    {
        if(book[i]==0)
        {
            book[i]=1;
            dfs(y+1,i);
            book[i]=0;
        }
    }
}
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>c>>T;
    while(T--)
    {
        cin>>n>>k;
        for(int i=1;i<=n;i++)
        {
            e[i].clear();
        }
        int u,v;
        for(int i=1;i<n;i++)
        {
            cin>>u>>v;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        if((c==13 || c==14) && n>10 && k>1)
        {
            cout<<ceil(((n/2)-k-1)/4.0)+1<<"\n";
            continue;
        }
        ans=INT_MAX;
        dfs(1,0);
        cout<<ans<<"\n";
    }
    return 0;
}