#include <bits/stdc++.h>
using namespace std;
int c,T;
int n,k,ans;
int p[1000010];
int fa[1000010],dep[1000010],dis[1000010];
vector<int> edge[1000010];
vector<int> son[1000010];
bool had[1000010],been[1000010];
void bld(int x)
{
    for(int i=0;i<edge[x].size();i++)
    {
        int to=edge[x][i];
        if(to==fa[x])
            continue;
        fa[to]=x;
        dep[to]=dep[x]+1;
        son[x].push_back(to);
        bld(to);
    }
}
bool cmp(int x,int y)
{
    return dep[x]<dep[y];
}
bool chec()
{
    int ret=0;
    sort(p+1,p+k+1,cmp);
    for(int i=1;i<=k;i++)
    {
        if(had[fa[p[i]]]==false)
            ret++;
        if(ret>2)
            return false;
    }
    return true;
}
int cal()
{
    memset(dis,0x3f,sizeof dis);
    memset(been,false,sizeof been);
    int mx=0;
    queue<int> q;
    for(int i=1;i<=k;i++)
    {
        dis[p[i]]=0;
        q.push(p[i]);
    }
    while(q.empty()==false)
    {
        int t=q.front();
        q.pop();
        if(been[t]==true)
            continue;
        been[t]=true;
        for(int i=0;i<edge[t].size();i++)
        {
            int to=edge[t][i];
            if(been[to]==true||dis[to]<dis[t]+1)
                continue;
            dis[to]=dis[t]+1;
            mx=max(mx,dis[to]);
            q.push(to);
        }
    }
    return mx;
}
void dfs(int x,int y)
{
    if(x==k+1)
    {
        if(chec()==true)
        {
            ans=min(ans,cal());
        }
        return;
    }
    if(y+1>n)
        return;
    for(int i=y+1;i<=n;i++)
    {
        p[x]=i;
        had[i]=true;
        dfs(x+1,i);
        had[i]=false;
    }
}
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>T;
    while(T--)
    {
        cin>>n>>k;
        for(int i=1;i<=n-1;i++)
        {
            int u,v;
            cin>>u>>v;
            edge[u].push_back(v);
            edge[v].push_back(u);
        }
        fa[1]=0;
        bld(1);
        ans=n;
        dfs(1,0);
        cout<<ans<<endl;
        for(int i=1;i<=n;i++)
            edge[i].clear();
    }
    return 0;
}
