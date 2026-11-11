#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<pair<ll,ll> >v[5000505];
ll c,n,m,d,q,cnt;
ll tim[500005];
ll s,t;
ll dis[1000005];
void dij()
{
    memset(dis,0x3f,sizeof(dis));
    priority_queue<pair<ll,ll> >pq;
    pq.push({0,s});
    dis[s]=0;
    while(pq.size())
    {
        auto [len,u]=pq.top();
        pq.pop();
        for(auto [i,siz]:v[u])
        {
            if(dis[i]>dis[u]+siz)
            {
                dis[i]=dis[u]+siz;
                pq.push({dis[i],i});
            }
        }
    }
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    cnt=m;
    for(ll i=1;i<=m;i++)
    {
        cin>>tim[i];
    }
    for(ll i=1;i<=n;i++)
    {
        ll k;
        cin>>k;
        cnt++;
        for(ll j=1;j<=k;j++)
        {
            ll u,t;
            cin>>u>>t;
            v[u].push_back({cnt,t});
            v[cnt].push_back({u,t});
        }
    }
    while(q--)
    {
        cin>>s>>t;
        dij();
        cout<<dis[t]+tim[s]+tim[t]<<'\n';
    }
    return 0;
}
