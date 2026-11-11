//pts in optimistic:25
#include<bits/stdc++.h>
#define int long long
#define For(i,a,b) for(int i=a;i<=b;i++)
#define Rof(i,a,b) for(int i=a;i>=b;i--)
#define fi first
#define sc second
#define pb push_back
#define pii pair<int,int>
#define vec vector
using namespace std;
const int N=35;
void solve1()
{
    int n,k;cin>>n>>k;
    int u,v;For(i,1,n-1)cin>>u>>v;
    if(k==n)
        return cout<<0<<'\n',void();
    int m=n/2;
    if(k<m)
    {
        int p=(m-k)/(4);
        if((m-k)%(4))
            p++;
        return cout<<p+1<<'\n',void();
    }
    else
    {
        return cout<<1<<'\n',void();
    }
}
int n,k,dis[N][N],a[N];
vec<int>e[N];
void bfs(int s)
{
    queue<int>q;
    q.push(s);
    For(i,1,n)
        dis[s][i]=100;
    dis[s][s]=0;
    while(!q.empty())
    {
        int u=q.front();q.pop();
        for(int v:e[u])
        {
            if(dis[s][v]==100)
                dis[s][v]=dis[s][u]+1,q.push(v);
        }
    }
}
int fa[N];
int find(int x)
{
    if(fa[x]==x)
        return x;
    return fa[x]=find(fa[x]);
}
void merge(int x,int y)
{
    int fx=find(x),fy=find(y);
    if(fx!=fy)
        fa[fx]=fy;
}
int ck()
{
    For(i,1,n)
        fa[i]=i;
    For(i,1,n)
    {
        if(a[i])
        {
            for(int j:e[i])
            {
                if(a[j])
                    merge(i,j);
            }
        }
    }
    int col=0;
    For(i,1,n)
        if(a[i]&&find(i)==i)
            col++;
    if(col<=2)
        return 1;
    return 0;
}
int ans=10000;
void dfs(int dep,int cnt)
{
    if(dep==n+1||cnt==k)
    {
        if(ck())
        {
            int mx=0;
            For(i,1,n)
            {
                int mn=100;
                For(j,1,n)
                {
                    if(a[j]==1)
                        mn=min(mn,dis[i][j]);
                }
                mx=max(mx,mn);
            }
            ans=min(ans,mx);
        }
        return;
    }
    a[dep]=1;
    dfs(dep+1,cnt+1);
    a[dep]=0;
    dfs(dep+1,cnt);
}
void solve2()
{
    // cout<<1<<'\n';
    cin>>n>>k;
    For(i,1,n)
        e[i].clear();
    For(i,1,n)
        For(j,1,n)
            dis[i][j]=100;
    For(i,1,n)
        a[i]=0;
    // cout<<2<<'\n';
    // For(i,1,n)
    //     cout<<i<<' '<<e[i].size()<<'\n';
    For(i,1,n-1)
    {
        int u,v;cin>>u>>v;
        e[u].pb(v),e[v].pb(u);
    }
    // cout<<3<<'\n';
    For(i,1,n)
        bfs(i);
    // cout<<4<<'\n';
    ans=100000;
    dfs(1,0);
    cout<<ans<<'\n';
}
signed main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int c,t;cin>>c>>t;
    while(t--)
    {
        if(c>=13&&c<=14)
            solve1();
        else if(c<=6)
            solve2();
    }
    return 0;
}