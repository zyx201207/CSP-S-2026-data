#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<int> g[1010];
int n,k;
int st[12][2010];
int fir[2010],dep[2010],madep[2010][2],out[2010],tot;
void dfs(int u,int fa)
{
    dep[u]=dep[fa]+1;
    madep[u][0]=dep[u];
    tot++;
    if(!fir[u])fir[u]=tot;
    st[0][tot]=u;
    for(auto v:g[u])
    {
        if(v==fa)continue;
        dfs(v,u);
        st[0][++tot]=u;
        vector<int> tmp;
        tmp.push_back(madep[u][0]);
        tmp.push_back(madep[v][0]);
        tmp.push_back(madep[u][1]);
        tmp.push_back(madep[v][1]);
        sort(tmp.begin(),tmp.end());
        madep[u][0]=tmp[3],madep[u][1]=tmp[2];
    }
}
void init()
{
    for(int i=1;i<12;i++)
    {
        for(int j=1;j<=tot-(1<<i)+1;j++)
        {
            st[i][j]=dep[st[i-1][j]]<dep[st[i-1][j+(1<<(i-1))]]?st[i-1][j]:st[i-1][j+(1<<(i-1))];
        }
    }
}
int lca(int u,int v)
{
    if(fir[u]>fir[v])swap(u,v);
    int m=log2(fir[v]-fir[u]);
    return dep[st[m][fir[u]]]<dep[st[m][fir[v]-(1<<m)+1]]?st[m][fir[u]]:st[m][fir[v]-(1<<m)+1];
}
int get_dis(int u,int v)
{
    return dep[u]-dep[v]-2*dep[lca(u,v)];
}
bool notus[2010];
int get_depth(int u,int fa)
{
    for(auto v:g[u])
    {
        if(v==fa or notus[v])continue;
        if(madep[v][0]==madep[u][0])out[v]=madep[u][1];
        else out[v]=madep[u][0];
        dfs(v,u);
    }
}
bool find(int u,int m)
{
    memset(notus,0,sizeof notus);
    int v=0;
    for(int i=1;i<=n;i++)
    {
        if(get_dis(i,u)<=m)notus[i]=1;
        else v=i;
    }
    if(!v)return 1;
    get_depth(v,0);
    int mi=0x3f3f3f3f;
    for(int i=1;i<=n;i++)
    {
        if(!notus[i])
        {
            mi=min(mi,max(madep[i][0],out[i]));
        }
    }
    return mi<=m;
}
bool check(int m)
{
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        ans|=find(i,m);
    }
    return ans;
}
bool vis[2010],fangwen[2010];
void check_two_part(int u,int fa)
{
    fangwen[u]=1;
    for(auto v:g[u])
    {
        if(fa==v)continue;
        check_two_part(v,u);
    }
}
int get_ans()
{
    int tot=0;
    for(int i=1;i<=n;i++)
    {
        if(vis[i] and !fangwen[i])
        {
            tot++;
            check_two_part(i,0);
        }
    }
    if(tot>2)return 0;
    int ma=0;
    for(int i=1;i<=n;i++)
    {
        int mi=0x3f3f3f3f;
        for(int j=1;j<=n;j++)
        {
            if(vis[j])
            mi=min(mi,get_dis(i,j));
        }
        ma=max(ma,mi);
    }
    return ma;
}
int brute(int i,int sum)
{
    if(sum>k)return 0x3f3f3f3f;
    if(i==n+1 and sum==k)
    {
        return get_ans();
    }
    int ans=0;
    vis[i]=1;
    ans=min(ans,brute(i+1,sum+1));
    vis[i]=0;
    ans=min(ans,brute(i+1,sum));
    return ans;
}
signed main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    cin>>c>>t;
    if(c<=3)
    {
        while(t--)
        {
            cin>>n>>k;
            for(int i=1;i<n;i++)
            {
                int u,v;
                cin>>u>>v;
                g[u].push_back(v);
                g[v].push_back(u);
            }
            dfs(1,0);
            init();
            cout<<brute(1,0)<<'\n';
        }
    }
    else if(c==7)
    {
        // while(t--)
        // {
        //     cin>>n>>k;
        //     for(int i=1;i<n;i++)
        //     {
        //         int u,v;
        //         cin>>u>>v;
        //         g[u].push_back(v);
        //         g[v].push_back(u);
        //     }
        //     int l=0,r=n;
        //     dfs(1,0);
        //     init();
        //     while(l+1!=r)
        //     {
        //         int m=(l+r)>>1;
        //         if(check(m))l=m;
        //         else r=m;
        //     }
        //     cout<<r<<'\n';
        // }
    }
    else if(c==13 or c==14)
    {
        while(t--)
        {
            cin>>n>>k;
            for(int i=1;i<n;i++)
            {
                int u,v;
                cin>>u>>v;
            }
            if(k==n)cout<<"0\n";
            else if(k>=(n>>1))cout<<"1\n";
            else
            {
                int m=n>>1;
                cout<<((m-k)+3)/4+1<<'\n';
            }
        }
    }
}
