#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef char ch;
typedef string str;
const ll maxn=1e6+10,inf=1e18;
ll c,t,n,k,ans,dis[maxn],p[maxn],col[maxn];
struct edge
{
    ll to,nxt;
}e[maxn];
ll head[maxn],cnt;
void add(ll u,ll v)
{
    e[++cnt]={v,head[u]},head[u]=cnt;
}
deque<pair<ll,ll>> q1,q2;
queue<ll> q3;
bool vis[maxn];
ll bfs()
{
    q2=q1;
    for(int i=1;i<=n;i++) vis[i]=0,col[i]=0;
    while(q2.size()) p[q2.size()]=q2.front().first,vis[q2.front().first]=1,q2.pop_front();
    ll tot=0;
    for(int i=1;i<=k;i++)
    {
        if(!col[p[i]]&&vis[p[i]])
        {
            tot++;
            if(tot>2) return inf;
            q3.push(p[i]);
            while(q3.size())
            {
                ll fr=q3.front();
                q3.pop();
                if(!vis[fr]) continue;
                if(col[fr]) continue;
                col[fr]=tot;
                for(int i=head[fr];i;i=e[i].nxt) q3.push(e[i].to);
            }
        }
    }
    q2=q1;
    for(int i=1;i<=n;i++) vis[i]=0;
    while(q2.size())
    {
        pair<ll,ll> fr=q2.front();
        ll u=fr.first,d=fr.second;
        q2.pop_front();
        if(vis[u]) continue;
        vis[u]=1,dis[u]=d;
        for(int i=head[u];i;i=e[i].nxt) q2.push_back({e[i].to,d+1});
    }
    ll mx=0;
    for(int i=1;i<=n;i++) mx=max(mx,dis[i]);
    return mx;
}
void dfs(ll dep,ll cnt)
{
    if(dep>n)
    {
        if(cnt==k) ans=min(ans,bfs());
        return;
    }
    q1.push_back({dep,0}),dfs(dep+1,cnt+1),q1.pop_back(),dfs(dep+1,cnt);
}
void solve()
{
    cin>>n>>k,cnt=0,ans=inf;
    for(int i=1;i<=n;i++) head[i]=0;
    for(int i=1;i<n;i++)
    {
        ll u,v;
        cin>>u>>v,add(u,v),add(v,u);
    }
    dfs(1,0),cout<<ans<<"\n";
}
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>t;
    while(t--) solve();
}
