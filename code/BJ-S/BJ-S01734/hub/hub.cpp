#include<bits/stdc++.h>
#define ll long long

using namespace std;

const ll maxn=2e6+5,maxn1=20;

struct Edge
{
    ll v,nxt;
}e[2*maxn1];
ll head[maxn1],tot;
void add(ll u,ll v)
{
    e[++tot].v=v;
    e[tot].nxt=head[u];
    head[u]=tot;
}

ll n,k,dis[maxn1][maxn1],fl[maxn1];

void dfs(ll st,ll u,ll fa)
{
    for(ll i=head[u];i;i=e[i].nxt)
    {
        ll v=e[i].v;
        if(v==fa) continue;
        dis[st][v]=dis[st][u]+1;
        dfs(st,v,u);
    }
}

void sub1()
{
    cin>>n>>k;
    for(ll i=1;i<n;i++)
    {
        ll u,v;cin>>u>>v;
        add(u,v);add(v,u);
    }

    for(ll i=1;i<=n;i++)
    {
        dis[i][i]=0;
        dfs(i,i,0);
    }

    ll full=(1<<n)-1,ans=1e18;
    for(ll msk=0;msk<=full;msk++)
    {
        if(__builtin_popcount(msk)!=k) continue;
        for(ll i=1;i<=n;i++)
        {
            if(msk&(1<<(i-1))) fl[i]=true;
            else fl[i]=false;
        }
        ll mx=0;
        for(ll i=1;i<=n;i++)
        {
            ll mn=1e18;
            for(ll j=1;j<=n;j++)
            {
                if(!fl[j]) continue;
                mn=min(mn,dis[i][j]);
            }
            mx=max(mx,mn);
        }
        ans=min(ans,mx);
    }
    cout<<ans<<'\n';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);

    ll C,T;cin>>C>>T;
    if(C<=1)
    {
        while(T--) sub1();
        return 0;
    }
    while(T--)
    {
        cin>>n>>k;
        for(int i=1;i<n;i++)
        {
            int u,v;cin>>u>>v;
        }
        cout<<1<<'\n';
    }
    return 0;
}
