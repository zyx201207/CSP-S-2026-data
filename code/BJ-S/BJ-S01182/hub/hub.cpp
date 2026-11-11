#include<bits/stdc++.h>
using namespace std;
int dep[1000002],f[1000002][22];
bool vis[1000002],shi[1000002];
vector<int> g[1000002];
int n,k,minn=1e9;
void DFS3(int x,int fa)
{
    dep[x]=dep[fa]+1;
    f[x][0]=fa;
    for(int i=1;i<=20;i++)
        f[x][i]=f[f[x][i-1]][i-1];
    for(auto y:g[x])
    {
        if(y!=fa)
            DFS3(y,x);
    }
}
void DFS2(int x)
{
    vis[x]=true;
    for(auto y:g[x])
    {
        if(!vis[y]&&shi[y])
            DFS2(y);
    }
}
int LCA(int aa,int bb)
{
    if(dep[aa]<dep[bb])
        swap(aa,bb);
    for(int i=20;i>=0;i--)
    {
        if(dep[f[aa][i]]>=dep[bb])
            aa=f[aa][i];
    }
    if(aa==bb)
        return aa;
    for(int i=20;i>=0;i--)
    {
        if(f[aa][i]!=f[bb][i])
            aa=f[aa][i],bb=f[bb][i];
    }
    return f[aa][0];
}
void DFS1(int x,int yi)//每个点选不选
{
    if(x==n+1)
    {
        if(yi!=k)
            return;
        for(int i=1;i<=n;i++)
            vis[i]=false;
        int ji=0;
        for(int i=1;i<=n;i++)
        {
            if(!vis[i]&&shi[i])
            {
                ji++;
                if(ji>2)
                    return;
                DFS2(i);
            }
        }
        if(ji>2)
            return;
        int maxn=0;
        for(int i=1;i<=n;i++)//判断每个城市的通勤距离
        {
            int dmin=1e9;
            for(int j=1;j<=n;j++)
            {
                if(shi[j])
                {
                    int lca=LCA(i,j);
                    dmin=min(dmin,dep[i]+dep[j]-2*dep[lca]);
                }
            }
            maxn=max(maxn,dmin);
        }
        minn=min(minn,maxn);
        return;
    }
    if(yi>=k)//不能选
    {
        shi[x]=false;
        DFS1(x+1,yi);
    }
    else if(n-x+1<=k-yi)//必须选
    {
        shi[x]=true;
        DFS1(x+1,yi+1);
    }
    else
    {
        shi[x]=false;
        DFS1(x+1,yi);
        shi[x]=true;
        DFS1(x+1,yi+1);
    }
}
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int c,t;
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>k;
        for(int i=1;i<=n;i++)
            g[i].clear();
        for(int i=1;i<n;i++)
        {
            int u,v;
            cin>>u>>v;
            g[u].push_back(v),g[v].push_back(u);
        }
        DFS3(1,0);
        minn=1e9;
        DFS1(1,0);
        cout<<minn<<"\n";
    }
    return 0;
}