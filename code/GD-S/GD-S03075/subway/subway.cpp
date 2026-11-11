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
const int maxn=5e5+10;
const int maxm=500+10;

vector<pii> road[maxn];
int         f[maxm][maxm];
int         w[maxn];
int         n,m,d,q;

// inline char nc() { static char buf[1<<22],*p1=buf,*p2=buf; return (p1==p2&&(p2=p1+fread(buf,1,1<<22,stdin),p1==p2)? EOF:*p1++); }
// inline int read() { char c; int x=0,f=1; while(!isdigit(c=nc())) if(c=='-') f=-1; while(isdigit(c)) x=x*10+c-'0',c=nc(); return x*f; }

void work()
{
    /* Code */
    cin>>n>>m>>d>>q;
    for(int i=1; i<=m; i++) cin>>w[i];
    for(int i=1; i<=n; i++)
    {
        int k,x,y; cin>>k;
        for(int j=1; j<=k; j++) cin>>x>>y,road[x].pb(i,y);
    }
    for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) f[i][j]=1e18*(i!=j);
    for(int i=1; i<=m; i++) for(int j=0; j<road[i].size(); j++) for(int k=j+1; k<road[i].size(); k++)
        f[fir(road[i][j])][fir(road[i][k])]=min(f[fir(road[i][j])][fir(road[i][k])],sec(road[i][j])+sec(road[i][k])),
        f[fir(road[i][k])][fir(road[i][j])]=min(f[fir(road[i][k])][fir(road[i][j])],sec(road[i][j])+sec(road[i][k]));
    for(int k=1; k<=n; k++) for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
    for(int i=1,x,y; i<=q; i++)
    {
        cin>>x>>y; int res=1e18;
        for(auto [id1,val1]:road[x]) for(auto [id2,val2]:road[y]) res=min(res,val1+val2+f[id1][id2]);
        cout<<res+w[x]+w[y]<<'\n';
    }
    // O(0.5md^2+n^3+qd^2).
    return;
}

signed main()
{
    fileio("subway.in","subway.out");
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t,stTime=clock();
    cin>>t; t=1;
    while(t--) work();
    // cerr<<"Time : "<<(double)(clock()-stTime)/CLOCKS_PER_SEC<<'\n';
    return 0;
} // Cellinia Texas.