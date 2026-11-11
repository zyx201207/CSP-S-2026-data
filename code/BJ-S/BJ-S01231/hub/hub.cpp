#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5;
int dis[N];
int ans[N];
int dep[N];
vector<int> G[N];
int Id;
vector<int> p;
void dfs(int x,int fa)
{
    for(int v:G[x])
    {
        if(v==fa) continue;
        dis[v]=dis[x]+1;
        dfs(v,x);
    }
}
void calc(int x,int fa)
{
    for(int v:G[x])
    {
        if(v==fa) continue;
        calc(v,x);
    }
    if(x==Id)
    {
        p.push_back(x);
        Id=fa;
    }
}
void dfs1(int x,int fa)
{
    for(int v:G[x])
    {
        if(v==fa) continue;
        dis[v]=dis[x]+1;
        dfs1(v,x);
        dep[x]=max(dep[x],dep[v]+1);
        //cout<<dep[x]<<endl;
    }
}
int Dfs(int x,int fa,int k)
{
    if(dep[x]<k) return 0;
    int cnt=1;
    for(int v:G[x])
    {
        if(v==fa) continue;
        cnt+=Dfs(v,x,k);
    }
    return cnt;
}
int f(int x,int n,int k)
{
    int l=1,r=n;
    int ans=n;
    while(l<=r)
    {
        int mid=l+r>>1;
        int x=Dfs(x,0,n-mid);
        //cout<<x<<" "<<mid<<endl;
        if(x<=k)
        {
            l=mid+1;
            ans=n-mid;
        }
        else r=mid-1;
    }
    return ans;
}
signed main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin.tie(0)->sync_with_stdio(0);
    int c,t;
    cin>>c>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        for(int i=1;i<=n;i++) G[i].clear();
        for(int i=1;i<n;i++)
        {
            int u,v;
            cin>>u>>v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
         for(int i=1;i<=n;i++) dis[i]=dep[i]=ans[i]=0;
        dis[1]=0;
        dfs(1,-1);
        int maxx=0;
        int id=1;
        for(int i=1;i<=n;i++)
        {
            if(maxx<dis[i])
            {
                maxx=dis[i];
                id=i;
            }
        }
        dis[id]=0;
        dfs(id,-1);
        maxx=0;
        Id=id;
        for(int i=1;i<=n;i++)
        {
            if(maxx<dis[i])
            {
                maxx=dis[i];
                Id=i;
            }
        }
        //cout<<id<<" "<<Id<<endl;
        p.clear();
        calc(id,-1);

        //for(int x:p) cout<<x<<" ";
        int x=p[p.size()/2];
        for(int i=0;i<=n;i++) dep[i]=dis[i]=0;
        dfs1(x,-1);
        //cout<<x<<endl;
        cout<<f(x,(int)(p.size()+1)/2,k)<<endl;
//cout<<dep[3]<<endl;
    }
    return 0;
}
