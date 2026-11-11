#include<bits/stdc++.h>
using namespace std;
#define fileio
#define IOS
void ___()
{
#ifdef fileio
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
#endif
#ifdef IOS
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    #define endl '\n'
#endif
}
#define ll long long
typedef pair<int,int> pii;
const int _mxn=1e6+505,_mxm=5e5+5;
struct graph
{
    struct node
    {
        int v;
        ll w;
        node(){}
        node(int _v,int _w):v(_v),w(_w){}
        bool operator<(node _x) const {return w<_x.w;}
        bool operator>(node _x) const {return w>_x.w;}
    };
    vector<node> g[_mxn];
    void add(int u,int v,ll w)
    {
        g[u].push_back(node(v,w));
        g[v].push_back(node(u,w));
    }
}g;
//i 站，m+i 线路，m+n+idx 站台
//地铁口<->站厅<->站台<->线路
//求地铁口之间的最短路
int n,m,d,q;
ll w[_mxm];
vector<pair<ll,int> > t[_mxm];
struct query
{
    int x,y,id;
    bool operator<(query _x) const {return x<_x.x;}
}qs[_mxm];
ll dis[505][505],dis1[_mxn];
void dijkstra(int st)
{
    memset(dis1,0x3f,sizeof(dis1));
    typedef graph::node node;
    priority_queue<node,vector<node>,greater<node> > q;
    q.push(node(m+st,0));
    dis1[m+st]=0;
    while(!q.empty())
    {
        auto nw=q.top();q.pop();
        int u=nw.v;
        if(nw.w>dis1[u])
            continue;
        for(auto it:g.g[u])
        {
            int v=it.v;
            if(dis1[v]>dis1[u]+it.w)
            {
                dis1[v]=dis1[u]+it.w;
                q.push(node(v,dis1[v]));
            }
        }
    }
    for(int i=1;i<=n;i++)
        dis[st][i]=dis1[m+i];
}
int main()
{
    ___();
    // clock_t _st=clock();

    int __;
    cin>>__>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
        cin>>w[i];
    int idx=0;
    for(int i=1;i<=n;i++)
    {
        int ki;
        cin>>ki;
        for(int j=1;j<=ki;j++)
        {
            int a;
            ll tt;
            cin>>a>>tt;
            t[a].push_back(make_pair(tt,i));
            idx++;
            g.add(a,m+n+idx,tt);
            g.add(m+n+idx,m+i,0);
        }
    }
    for(int i=1;i<=n;i++)
        dijkstra(i);

    // clock_t _ed1=clock();
    // cerr<<_ed1-_st<<endl;
    // for(int i=1;i<=m+n+idx;i++)
    // {
    //     cout<<i<<": ";
    //     for(auto it:g.g[i])
    //         cout<<it.v<<" "<<it.w<<"  ";
    //     cout<<endl;
    // }
    for(int qi=1;qi<=q;qi++)
    {
        // cin>>qs[i].x>>qs[i].y,qs[i].id=i;
        // if(qs[i].x>qs[i].y)
        //     swap(qs[i].x,qs[i].y);
        int x,y;
        cin>>x>>y;
        ll ans=1e18;
        for(auto itx:t[x])
            for(auto ity:t[y])
                ans=min(ans,itx.first+ity.first+dis[itx.second][ity.second]);
        cout<<ans+w[x]+w[y]<<endl;
    }
    // for(int i=1;i<=q;i++)
    //     cout<<ans[i]<<endl;

    // clock_t _ed=clock();
    // cerr<<_ed-_st<<endl;
    return 0;
}