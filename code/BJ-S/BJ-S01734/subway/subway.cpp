#include<bits/stdc++.h>
#define ll long long

using namespace std;

const ll maxn1=1510,maxn=5e5+5;

struct Edge
{
    ll v,nxt,w;
}e[2*maxn];
ll head[maxn],tot;
void add(ll u,ll v,ll w)
{
    e[++tot].v=v;
    e[tot].w=w;
    e[tot].nxt=head[u];
    head[u]=tot;
}

struct Node
{
    ll id,ans;
    bool operator<(const Node &n)const
    {
        return n.ans<ans;
    }
};

priority_queue<Node> pq;
ll C,n,m,d,q,w[maxn],dis[maxn1][maxn1];
bool vis[maxn];

void Dij(ll st)
{
    for(ll i=1;i<=n+m;i++) dis[st][i]=1e18;
    for(ll i=1;i<=n+m;i++) vis[i]=false;

    dis[st][st]=0;
    pq.push((Node){st,0});
    while(!pq.empty())
    {
        Node cur=pq.top();
        pq.pop();
        ll u=cur.id;
        if(vis[u]) continue;
        vis[u]=true;
        for(ll i=head[u];i;i=e[i].nxt)
        {
            ll v=e[i].v,w=e[i].w;
            if(vis[v]) continue;
            if(dis[st][v]>dis[st][u]+w)
            {
                dis[st][v]=dis[st][u]+w;
                pq.push((Node){v,dis[st][v]});
            }
        }
    }
}

void sub1()
{
    for(ll i=1;i<=m;i++) cin>>w[i];
    for(ll i=1;i<=n;i++)
    {
        ll k;cin>>k;
        for(ll j=1;j<=k;j++)
        {
            ll a,t;cin>>a>>t;
            add(m+i,a,t);add(a,m+i,t);
        }
    }

    for(ll i=1;i<=m;i++)
    {
        Dij(i);
    }

    for(ll i=1;i<=q;i++)
    {
        ll x,y;cin>>x>>y;
        ll ans=dis[x][y]+w[x]+w[y];
        cout<<ans<<'\n';
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    cin>>C>>n>>m>>d>>q;
    if(C<=11)
    {
        sub1();
        return 0;
    }
    else
    {
        for(ll i=1;i<=m;i++) cin>>w[i];
        for(ll i=1;i<=n;i++)
        {
            ll k;cin>>k;
            for(ll j=1;j<=k;j++)
            {
                ll a,t;cin>>a>>t;
                add(m+i,a,t);add(a,m+i,t);
            }
        }
    }

    return 0;
}
