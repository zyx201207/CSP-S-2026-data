#include<bits/stdc++.h>
using namespace std;
int n,k;
int fa[10006][21],dep[10006];
vector<int> mp[10006];
void dfs(int u,int father)
{
    dep[u]=dep[father]+1;
    fa[u][0]=father;
    for(int i=1;i<=20;i++)
    {
        fa[u][i]=fa[fa[u][i-1]][i-1];
    }
    for(auto v:mp[u])
    {
        if(v==father) continue;
        dfs(v,u);
    }
}
int LCA(int x,int y)
{
    if(x==y) return x;
    if(dep[x]<dep[y]) swap(x,y);
    for(int i=20;i>=0;i--)
    {
        if(dep[fa[x][i]]>=dep[y]) x=fa[x][i];
    }
    if(x==y) return x;
    for(int i=20;i>=1;i--)
    {
        if(fa[x][i]!=fa[y][i]) x=fa[x][i],y=fa[y][i];
    }
    return fa[x][0];
}
int len(int x,int y)
{
    return dep[x]+dep[y]-2*dep[LCA(x,y)];
}
int bcj[10006];
inline void init(){for(int i=1;i<=n;i++) bcj[i]=i;}
int fi(int x)
{
    return (bcj[x]==x?x:bcj[x]=fi(bcj[x]));
}
void dfs2(int u,int father,int xx)
{
    for(auto v:mp[u])
    {
        if(v==father) continue;
        if(((xx>>(v-1))&1)==1&&((xx>>(u-1))&1)==1)
        {
            // cout<<"xxkan\n";
            int fav=fi(v),fau=fi(u);
            if(fav!=fau) bcj[fav]=fau;
        }
        dfs2(v,u,xx);
    }
}
bitset<1000006> vis;
bool checkk(int xx)
{
    // cout<<xx<<"\n";
    // for(int i=1;i<=n;i++) cout<<i<<" "<<bcj[i]<<" ";
    // cout<<"\n";
    vis=0;
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(((xx>>(i-1))&1)==0) continue;
        if(vis[fi(i)]==0) cnt++;
        vis[fi(i)]=1;
    }
    // cout<<xx<<" "<<cnt<<"\n";
    return cnt<=2;
}
void subtaskk2()
{
    int ans=n+1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            int maxn=0;
            if(i==j) continue;
            for(int k=1;k<=n;k++)
            {
                maxn=max(maxn,min(len(k,i),len(k,j)));
            }
            ans=min(maxn,ans);
        }
    }
    cout<<ans<<"\n";
}
signed main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,T;
    cin>>c>>T;
    while(T--)
    {
        cin>>n>>k;
        int ans=n+1;
        for(int i=1;i<=n;i++)
        {
            dep[i]=0,mp[i].clear();
            for(int j=0;j<=20;j++)
            {
                fa[i][j]=0;
            }
        }
        for(int i=1;i<n;i++)
        {
            int u,v;
            cin>>u>>v;
            mp[u].push_back(v);
            mp[v].push_back(u);
        }
        dfs(1,0);
        // cout<<len(1,10)<<"\n";
        if(c==7)
        {
            subtaskk2();
            continue;
        }
        for(int xx=0;xx<(1ll<<n);xx++)
        {
            if(__builtin_popcountll(xx)!=k) continue;
            init();
            dfs2(1,0,xx);
            if(!checkk(xx)) continue;
            // cout<<"xx "<<xx<<"\n";
            int maxn=0;
            for(int i=1;i<=n;i++)
            {
                int mnn=n+1;
                for(int j=1;j<=n;j++)
                {
                    if((xx>>(j-1))&1) mnn=min(mnn,len(i,j));
                }
                maxn=max(mnn,maxn);
            }
            
            ans=min(ans,maxn);
        }
        cout<<ans<<"\n";
        // cout<<"----------------------\n";
    }
    return 0;
}
/*
0 1
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10

7 1
5 2
1 2
2 3
3 4
4 5

*/