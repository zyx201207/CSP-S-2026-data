#include<bits/stdc++.h>
#define ll long long
#define pb emplace_back
#define all(x) x.begin(),x.end()
#define sz(x) ((int)x.size())
using namespace std;
int c,t,n,k;
const int N=1e6+10;
vector<int> g[N];
int vis[N];
void st(int x)
{
    fill(vis+1,vis+n+1,x);
}
void dfs1(int now,int fa,int w)
{
    vis[now]=w;
    for(auto to:g[now])
    {
        if(to==fa) continue;
        dfs1(to,now,w);
    }
}
int ans,mx[N],dx[N],ct,mid,anss;
void dfs2(int now,int fa)
{
    mx[now]=dx[now]=0;
    for(auto to:g[now])
    {
        if(vis[to]||to==fa) continue;
        dfs2(to,now);
        if(mx[to]+1>=mx[now]) dx[now]=mx[now],mx[now]=mx[to]+1;
        else dx[now]=max(dx[now],mx[to]+1);
    }
    if(mx[now]>=mid||!fa) ct++;
}
void dfs3(int now,int fa)
{
    for(auto to:g[now])
    {
        if(vis[to]||to==fa) continue;
        int sv=ct,ms=mx[to],ds=dx[to];
        if(mx[to]<mid) ct++;
        int w=(mx[now]==mx[to]+1)?dx[now]:mx[now];
        if(w<mid) ct--;
        if(w+1>=mx[to]) dx[to]=mx[to],mx[to]=w+1;
        else dx[to]=max(dx[to],w+1);
        anss=min(anss,ct);
        dfs3(to,now);
        ct=sv;
        mx[to]=ms,dx[to]=ds;
    }
}
int calc(int rt)
{
    ct=0;
    dfs2(rt,0);
    anss=ct;
    dfs3(rt,0);
    return anss;
}
void dfs(int now,int fa)
{
    if(ans<=k) return;
    int nw=0;
    st(1);
    dfs1(now,fa,0);
    nw+=calc(now);
    // clog<<now<<' '<<nw<<endl;
    if(fa&&nw<=k)
    {
        st(0);
        dfs1(now,fa,1);
        nw+=calc(fa);
    }
    ans=min(ans,nw);
    for(auto to:g[now])
    {
        if(to==fa) continue;
        dfs(to,now);
    }
}
bool ck()
{
    ans=n+1;
    dfs(1,0);
    return ans<=k;
}
int solve()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++) g[i].clear();
    int u,v;
    for(int i=1;i<n;i++) cin>>u>>v,g[u].pb(v),g[v].pb(u);
    if(n==k) return 0;
    int l=1,r=n-1,ans;
    while(l<=r)
    {
        mid=l+r>>1;
        if(ck()) ans=mid,r=mid-1;
        else l=mid+1;
    }
    return ans;
}
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>c>>t;
    while(t--) cout<<solve()<<"\n";
    return 0;
}