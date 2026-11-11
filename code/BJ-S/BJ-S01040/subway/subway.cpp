#include<bits/stdc++.h>
#define N 200010
#define int long long
#define pb push_back
using namespace std;
int c,n,m,__d,__q,wt[N],nut,d[N],vs[N],flg=1,_T;
struct p
{
    int v,w;
    bool friend operator < (p aa,p bb) { return aa.w>bb.w; };
};
vector<p> g[N];
priority_queue<p> q;
int dkij(int u,int v)
{
    for(int i=1;i<=nut;i++) d[i]=1e18,vs[i]=0;
    q.push({u,0}); d[u]=0;
    while(!q.empty())
    {
        int t=q.top().v; q.pop();
        if(vs[t]) continue;
        vs[t]=1;
        for(int i=0;i<g[t].size();i++)
        {
            int _u=g[t][i].v,w=g[t][i].w;
            if(d[_u]>d[t]+w) d[_u]=d[t]+w,q.push({_u,d[t]});
        }
    }
    return d[v];
}
int qt[N];
int _mn(int u,int v)
{
    int l=1,r=0;
    for(int i=1;i<=nut;i++) d[i]=1e18,vs[i]=0;
    d[u]=0; qt[++r]=u;
    while(l<=r)
    {
        int t=qt[l]; l++;
        if(vs[t]) continue;
        vs[t]=1;
        for(int i=0;i<g[t].size();i++)
        {
            int _v=g[t][i].v;
            if(d[_v]>d[t]+1) d[_v]=d[t]+1,qt[++r]=_v;
        }
    }
    return d[v];
}
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>c>>n>>m>>__d>>__q; nut=m;
    for(int i=1;i<=m;i++) cin>>wt[i];
    for(int i=1,k;i<=n;i++)
    {
        cin>>k; ++nut;
        for(int i=1,v,w;i<=k;i++)
        {
            cin>>v>>w;
            if(!_T) _T=w;
            else if(_T!=w) flg=0;
            g[v].pb({nut,w}),g[nut].pb({v,w});
        }
    }
    if(flg)
    {
        while(__q--)
        {
            int l,r; cin>>l>>r;
            cout<<wt[l]+wt[r]+_mn(l,r)*_T<<"\n";
        }
        return 0;
    }
    while(__q--)
    {
        int u,v; cin>>u>>v;
        cout<<wt[u]+wt[v]+dkij(u,v)<<"\n";
    }
    return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 2 2 2 4 2
3 2 2 3 2 5 2
1 2
1 3
*/
