#include <bits/stdc++.h>

using namespace std;

#define int long long

#define fileio(x,y) freopen(x,"r",stdin),freopen(y,"w",stdout);
#define tup tuple<int,int,int>
#define fir(x) (get<0>(x))
#define sec(x) (get<1>(x))
#define thr(x) (get<2>(x))
#define pii pair<int,int>
#define bit(x) bitset<x>
#define pb emplace_back
#define i12 __int128_t
#define mt make_tuple
#define mp make_pair

const int mod=998244353;
const int maxn=1e6+10;

vector<int> road[maxn];
set<int>    scc;
int         fa[maxn],spe[maxn],d[maxn];
int         n,k;

int find(int x) { return (fa[x]==x? x:(fa[x]=find(fa[x]))); }
bool merge(int x,int y) { x=find(x),y=find(y); if(x==y) return false; fa[x]=y; return true; }

int check(int st)
{
    queue<int> q; scc.clear(); int res=0;
    for(int i=1; i<=n; i++) fa[i]=i,spe[i]=(st>>(i-1))&1;
    for(int i=1; i<=n; i++) if(spe[i]) for(int it:road[i]) if(spe[it]) merge(i,it);
    for(int i=1; i<=n; i++) if(spe[i]) scc.insert(find(i)),q.push(i);
    if(scc.size()>2) return 1e18;
    for(int i=1; i<=n; i++) d[i]=1e18*(!spe[i]);
    while(q.size())
    {
        int now=q.front(); q.pop();
        res=max(res,d[now]);
        for(int it:road[now]) if(d[it]>d[now]+1) d[it]=d[now]+1,q.push(it);
    }
    return res;
}

void work()
{
    /* Code */
    cin>>n>>k; int res=1e18;
    for(int i=1; i<=n; i++) road[i].clear();
    for(int i=1,x,y; i<n; i++) cin>>x>>y,road[x].pb(y),road[y].pb(x);
    for(int i=0; i<(1<<n); i++)
    {
        if(__builtin_popcount(i)!=k) continue;
        res=min(res,check(i));
    }
    cout<<res<<'\n';
    return;
}

signed main()
{
    fileio("hub.in","hub.out");
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t,stTime=clock();
    cin>>t>>t;
    while(t--) work();
    // cerr<<"Time : "<<(double)(clock()-stTime)/CLOCKS_PER_SEC<<'\n';
    return 0;
} // Cellinia Texas.