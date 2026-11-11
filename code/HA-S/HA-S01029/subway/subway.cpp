#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,int> LP;
#define fir first
#define sec second
#define infl 0x3f3f3f3f3f3f3f3f
void solve1()
{

    int _,n,m,D,Q;
    cin>>_>>n>>m>>D>>Q;
    vector<int>val(m+10);
    for(int i=1;i<=m;++i)
        cin>>val[i];
    int tot=m;
    vector<vector<P> >G(m+10);
    {
        vector<vector<int> >a(n+4);

        for(int i=1;i<=n;++i)
        {
            int k;
            cin>>k;
            a[i].resize(k);
//            t[i].resize(k);
            for(int j=0;j<k;++j)
            {
                int x,t;
                cin>>x>>t;
                a[i][j]=++tot;
                G[x].emplace_back(tot,t);
//                las=x;
            }
        }
        G.resize(tot+10);
        for(int i=1;i<=m;++i)
            for(const auto e:G[i])
                G[e.fir].emplace_back(i,e.sec);
        for(int i=1;i<=n;++i)
            for(int j=1;j<a[i].size();++j)
                G[a[i][j-1]].emplace_back(a[i][j],0),G[a[i][j]].emplace_back(a[i][j-1],0);
    }
    while(Q--)
    {
        int st,ed;
        cin>>st>>ed;
        vector<ll>dis(tot+10,infl);
        dis[st]=0;
        priority_queue<LP,vector<LP>,greater<LP> >pq;
        pq.emplace(0,st);
        while(!pq.empty())
        {
            auto tmp=pq.top();
            pq.pop();
            ll d=tmp.fir;
            int u=tmp.sec;
//            cerr<<u<<endl;
            if(dis[u]!=d)
                continue;
            for(const auto&e:G[u])
                if(dis[e.fir]>d+e.sec)
                    pq.emplace(dis[e.fir]=d+e.sec,e.fir);
        }
        cout<<val[st]+val[ed]+dis[ed]<<endl;
    }
//    return 0;
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _,n,m,D,Q;
    cin>>_>>n>>m>>D>>Q;
    vector<int>val(m+10);
    for(int i=1;i<=m;++i)
        cin>>val[i];
    vector<vector<P> >blg(m+10);
    for(int i=1;i<=n;++i)
    {
        int k;
        cin>>k;
        while(k--)
        {
            int x,t;
            cin>>x>>t;
            blg[x].emplace_back(i,t);
        }
    }
    vector<vector<ll> >dis(n+10,vector<ll>(n+10,infl));
    for(int i=1;i<=n;++i)
        dis[i][i]=0;
    for(int u=1;u<=m;++u)
        for(const auto&e:blg[u])
            for(const auto&e2:blg[u])
                dis[e.fir][e2.fir]=min(dis[e.fir][e2.fir],0LL+e.sec+e2.sec);
    for(int k=1;k<=n;++k)
        for(int i=1;i<=n;++i)
            for(int j=1;j<=n;++j)
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    while(Q--)
    {
        ll ans=infl;
        int u,v;
        cin>>u>>v;
        for(const auto&e:blg[u])
            for(const auto&e2:blg[v])
                ans=min(ans,dis[e.fir][e2.fir]+e.sec+e2.sec);
        cout<<ans+val[u]+val[v]<<endl;
    }
    return 0;
}
