#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+1000;
ll a[N];
ll b[N];
ll c[N];
ll s[N];
ll vis[N];
vector<pair<ll,ll> > g[N];
ll f,n,m,d,q;
struct point
{
    ll u;
    ll sum;
    bool operator <(const point&p) const
    {
        return sum>p.sum;
    }
};
void dijk(ll fr)
{
    memset(s,0x3f,sizeof s);
    memset(vis,0,sizeof vis);
    priority_queue<point> q;
    s[fr]=0;
    q.push({fr,0});
    while(q.size())
    {
        auto [u,x]=q.top();
        q.pop();
        if(vis[u]==1)
            continue;
        vis[u]=1;
        for(auto [v,w]:g[u])
            if(s[u]+w<s[v])
                s[v]=s[u]+w,q.push({v,s[v]});
    }
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>f>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
        cin>>a[i];
    for(ll i=1;i<=n;i++)
    {
        ll t;
        cin>>t;
        for(ll j=1;j<=t;j++)
        {
            ll u,v;
            cin>>u>>v;
            b[j]=u;
            c[j]=v;
            for(ll k=1;k<j;k++)
            {
                g[u].push_back({b[k],v+c[k]});
                g[b[k]].push_back({u,v+c[k]});
            }
        }
    }
    for(int i=1;i<=q;i++)
    {
        ll fr,to,minn=1e18;
        cin>>fr>>to;
        dijk(fr);
        cout<<s[to]+a[fr]+a[to]<<'\n';
    }
    return 0;
}
