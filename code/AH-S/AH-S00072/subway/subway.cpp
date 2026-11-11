#include<bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll=long long;
ll c,n,m,d,q,tmp[2000005],dis[2000005],T=-1,Q[2000005],hd,tl;
bool used[2000005];
vector<pair<ll,ll>> g[2000005];
priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
void BFS(int s){
    for (ll i=m+1;i<=n+m*2;i++)
    {
        dis[i]=INF;
        used[i]=false;
    }
    dis[s]=0;
    hd=1,tl=0;
    Q[++tl]=s;
    used[s]=true;
    while (hd<=tl)
    {
        ll u=Q[hd];
        hd++;
        for (pair<ll,ll> i:g[u])
        {
            ll v=i.second;
            if (v>=1&&v<=m)
            {
                continue;
            }
            if (dis[v]>dis[u]+1)
            {
                dis[v]=dis[u]+1;
                if (!used[v])
                {
                    used[v]=true;
                    Q[++tl]=v;
                }
            }
        }
    }
}
void Dijkstra(int s){
    for (ll i=1;i<=n+m*2;i++)
    {
        dis[i]=INF;
    }
    dis[s]=0;
    pq.push({0,s});
    while (!pq.empty())
    {
        ll D=pq.top().first,u=pq.top().second;
        pq.pop();
        if (dis[u]!=D)
        {
            continue;
        }
        for (pair<ll,ll> i:g[u])
        {
            ll wei=i.first,v=i.second;
            if (dis[v]>dis[u]+wei)
            {
                dis[v]=dis[u]+wei;
                pq.push({dis[v],v});
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>c>>n>>m>>d>>q;
    for (int i=1;i<=m;i++)
    {
        ll w;
        cin>>w;
        g[i].push_back({w,i+m});
        g[i+m].push_back({w,i});
    }
    for (int i=1;i<=n;i++)
    {
        ll k;
        cin>>k;
        for (ll j=1;j<=k;j++)
        {
            ll a,t;
            cin>>tmp[j]>>t;
            if (T==-1)
            {
                T=t;
            }
            if (T!=t)
            {
                T=-2;
            }
            a=tmp[j];
            g[a+m].push_back({t,i+m*2});
            g[i+m*2].push_back({t,a+m});
        }
    }
    for (int i=1;i<=q;i++)
    {
        int x,y;
        cin>>x>>y;
        if (T!=-2)
        {
            BFS(x+m);
            cout<<dis[y+m]*T+g[x][0].first+g[y][0].first<<"\n";
        }
        else
        {
            Dijkstra(x);
            cout<<dis[y]<<"\n";
        }
    }
    return 0;
}
