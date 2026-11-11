#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,n,m,d,q;
int w[500005],k[505];
vector<int>a[505],t[505];
//vector<pair<int,int>>sta[500005];
vector<pair<int,int>>g[1005];
ll dis[1005][1005];
bitset<1005>f,fquery;
void dij(int id,int s)
{
    memset(dis[id],0x3f,(n+m+3)*sizeof(dis[id][0]));
    f.reset();
    priority_queue<pair<ll,int>>q;
    dis[id][s]=0;
    q.push({0,s});
    while(!q.empty())
    {
        int u=q.top().second;
        if(f[u]==1)
        {
            continue;
        }
        f[u]=1;
        q.pop();
        for(auto x:g[u])
        {
            int v=x.first;
            ll w=x.second;
            if(dis[id][u]+w<dis[id][v])
            {
                dis[id][v]=dis[id][u]+w;
                if(f[v]==0)
                {
                    q.push({-dis[id][v],v});
                }
            }
        }
    }
    return;
}
void do_small()
{
    for(int i=1;i<=m;++i)
    {
        cin>>w[i];
    }
    for(int i=1;i<=n;++i)
    {
        cin>>k[i];
        a[i].resize(k[i]+5);
        t[i].resize(k[i]+5);
        for(int j=1;j<=k[i];++j)
        {
            cin>>a[i][j]>>t[i][j];
            g[a[i][j]].push_back({m+i,t[i][j]});
            g[m+i].push_back({a[i][j],t[i][j]});
        }
    }
    for(int i=1;i<=q;++i)
    {
        int x,y;
        cin>>x>>y;
        dij(0,x);
        cout<<dis[0][y]+w[x]+w[y]<<"\n";
    }
    return;
}
void do_A()
{
    for(int i=1;i<=m;++i)
    {
        cin>>w[i];
    }
    for(int i=1;i<=n;++i)
    {
        cin>>k[i];
        a[i].resize(k[i]+5);
        t[i].resize(k[i]+5);
        for(int j=1;j<=k[i];++j)
        {
            cin>>a[i][j]>>t[i][j];
        }
        if(k[i]==2)
        {
            g[a[i][1]].push_back({a[i][2],t[i][2]+t[i][1]});
            g[a[i][2]].push_back({a[i][1],t[i][2]+t[i][1]});
        }
    }
    for(int i=1;i<=q;++i)
    {
        int x,y;
        cin>>x>>y;
        if(fquery[x]==0)
        {
            dij(x,x);
            fquery[x]=1;
        }
        cout<<dis[x][y]+w[x]+w[y]<<"\n";
    }
    return;
}
ll in[5][500005];
void do_nle2()
{
    memset(in[1],0x3f,sizeof(in[1]));
    memset(in[2],0x3f,sizeof(in[2]));
    for(int i=1;i<=m;++i)
    {
        cin>>w[i];
    }
    for(int i=1;i<=n;++i)
    {
        cin>>k[i];
        a[i].resize(k[i]+5);
        t[i].resize(k[i]+5);
        for(int j=1;j<=k[i];++j)
        {
            cin>>a[i][j]>>t[i][j];
            in[i][a[i][j]]=t[i][j];
        }
    }
    ll tmin=LONG_LONG_MAX;
    for(int i=1;i<=m;++i)
    {
        tmin=min(tmin,in[1][i]+in[2][i]);
    }
    for(int i=1;i<=q;++i)
    {
        int x,y;
        cin>>x>>y;
        cout<<min({in[1][x]+in[1][y],in[2][x]+in[2][y],in[1][x]+tmin+in[2][y],in[2][x]+tmin+in[1][y]})+w[x]+w[y]<<"\n";
    }
    return;
}
vector<int>sta[500005];
bitset<505>link[505];
void do_B()
{
    ll tc;
    for(int i=1;i<=m;++i)
    {
        cin>>w[i];
    }
    for(int i=1;i<=n;++i)
    {
        cin>>k[i];
        a[i].resize(k[i]+5);
        t[i].resize(k[i]+5);
        for(int j=1;j<=k[i];++j)
        {
            cin>>a[i][j]>>t[i][j];
            sta[a[i][j]].push_back(i);
            tc=t[i][j];
        }
    }
    for(int i=1;i<=m;++i)
    {
        for(int j=0;j<sta[i].size();++j)
        {
            for(int k=j+1;k<sta[i].size();++k)
            {
                if(link[sta[i][j]][sta[i][k]]==0)
                {
                    g[sta[i][j]].push_back({sta[i][k],tc*2});
                    g[sta[i][k]].push_back({sta[i][j],tc*2});
                    link[sta[i][j]][sta[i][k]]=link[sta[i][k]][sta[i][j]]=1;
                }
            }
        }
    }
    for(int i=1;i<=n;++i)
    {
        dij(i,i);
    }
    for(int i=1;i<=q;++i)
    {
        int x,y;
        cin>>x>>y;
        ll ans=LONG_LONG_MAX;
        for(auto a:sta[x])
        {
            for(auto b:sta[y])
            {
                ans=min(ans,dis[a][b]+tc*2);
            }
        }
        cout<<ans+w[x]+w[y]<<"\n";
    }
    return;
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    cin>>c>>n>>m>>d>>q;
    if(c>=1&&c<=6)
    {
        do_small();
    }
    else if(c>=7&&c<=11)
    {
        do_A();
    }
    else if(c>=20&&c<=21)
    {
        do_nle2();
    }
    else if(c>=12&&c<=19)
    {
        do_B();
    }
    return 0;
}
//finish do_small at 15:55
//finish do_A at 16:20
//finish do_nle2 at 16:33
//finish do_B at 18:16