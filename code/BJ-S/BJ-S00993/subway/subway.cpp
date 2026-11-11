#include<bits/stdc++.h>
using namespace std;
using ll=long long;

const int maxm=5e5+1000;
ll c,n,m,d,q,l;
ll a[maxm],dis[maxm],vis[maxm];
vector<pair<ll,ll>> e[maxm];
priority_queue<pair<ll,ll>,vector<
pair<ll,ll>>,greater<pair<ll,ll>>> que;

void dijk(ll s,ll t)
{
    for(int i=1; i<=m+l; i++)
        vis[i]=0,dis[i]=1e18;
    que.push({0,s});dis[s]=0;

    while(que.size())
    {
        ll x=que.top().second;
        que.pop();
//        cout<<x<<" ";

        if(x==t)
            break;

        if(vis[x]==1)
            continue;
        vis[x]=1;

        for(auto i:e[x])
        {
            ll nx=i.first;
            ll nw=i.second;

            if(dis[x]+nw<dis[nx])
            {
                dis[nx]=dis[x]+nw;
                que.push({dis[nx],nx});
            }
        }
    }
}

int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin>>c>>n>>m>>d>>q;
    for(int i=1; i<=m; i++)
        cin>>a[i];

    for(int i=1; i<=n; i++)
    {
        ll k;cin>>k;l++;
        for(int i=1; i<=k; i++)
        {
            ll y,w;cin>>y>>w;
            e[m+l].push_back({y,w});
            e[y].push_back({m+l,w});
        }
    }

    while(q--)
    {
        int x,y;
        cin>>x>>y;
        dijk(x,y);
        cout<<dis[y]+a[x]+a[y]<<endl;
    }

    return 0;
}
