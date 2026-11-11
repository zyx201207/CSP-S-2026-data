#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF=1e18;
struct P
{
    int sta;
    int line;
    P(int s=0,int l=0):sta(s),line(l){}
    bool operator<(const P&b) const
    {
        if(sta!=b.sta) return sta<b.sta;
        return line<b.line;
    }
};
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    vector<ll> w(m+1);
    for(int i=1;i<=m;i++) cin>>w[i];
    vector<vector<pair<int,ll>>> sl(m+1);
    map<P,int> id;
    vector<P> rev;
    int tot=0;
    for(int line=1;line<=n;line++)
    {
        int k;
        cin>>k;
        for(int j=1;j<=k;j++)
        {
            int a;
            ll t;
            cin>>a>>t;
            sl[a].emplace_back(line,t);
            P p(a,line);
            if(!id.count(p))
            {
                id[p]=tot++;
                rev.push_back(p);
            }
        }
    }
    vector<vector<pair<int,ll>>> g(tot);
    for(int s=1;s<=m;s++)
    {
        auto &vec=sl[s];
        for(int i=0;i<vec.size();i++)
        {
            int l1=vec[i].first;
            ll t1=vec[i].second;
            int u=id[P(s,l1)];
            for(int j=i+1;j<vec.size();j++)
            {
                int l2=vec[j].first;
                ll t2=vec[j].second;
                int v=id[P(s,l2)];
                ll cost=t1+t2;
                g[u].emplace_back(v,cost);
                g[v].emplace_back(u,cost);
            }
        }
    }
    vector<vector<ll>> dist(tot,vector<ll> (tot,INF));
    for(int st=0;st<tot;st++)
    {
        priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<> >pq;
        dist[st][st]=0;
        pq.emplace(0,st);
        while(!pq.empty())
        {
            auto [dis,u]=pq.top();
            pq.pop();
            if(dis>dist[st][u]) continue;
            for(auto[v,ww]:g[u])
            {
                if(dist[st][v]>dis+ww)
                {
                    dist[st][v]=dis+ww;
                    pq.emplace(dist[st][v],v);
                }
            }
        }
    }
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        ll ans;
        for(auto &px:sl[x])
        {
            int lx=px.first;
            ll tx=px.second;
            int u=id[P(x,lx)];
            ll incost=w[x]+tx;
            for(auto &py:sl[y])
            {
                int ly=py.first;
                ll ty=py.second;
                int v=id[P(y,ly)];
                ll outcost=w[y]+ty;
                if(dist[u][v]!=INF)
                {
                    ans=min(ans,incost+dist[u][v]+outcost);
                }
            }
            
        }
        cout<<ans<<endl;
    }
    return 0;

}