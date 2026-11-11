#include <bits/stdc++.h>
#define For(e,e1,e2) for(int e=(e1);e<=(e2);e++)
#define For_(e,e1,e2) for(int e=(e1);e<(e2);e++)
#define Rof(e,e1,e2) for(int e=(e2);e>=(e1);e--)
#define Rof_(e,e1,e2) for(int e=(e2);e>(e1);e--)
#define LL long long
#define ULL unsigned long long
#define DB double
#define cint const int
#define cLL const long long
#define ft first
#define sc second
#define vct vector
#define pb push_back
#define all(ev) ev.begin(),ev.end()
#define sz(ev) ((int)ev.size())
#define exc(ev) if(ev) continue
#define stop(ev) if(ev) break
#define ret(ev) if(ev) return 
#define x0 __xx00__
#define x1 __xx11__
#define y0 __yy00__
#define y1 __yy11__
using namespace std;

void get_max(LL &w1,cLL w2)
{ if(w2>w1) w1=w2; }
void get_min(LL &w1,cLL w2)
{ if(w2<w1) w1=w2; }

void main_init()
{

}
cint N=510,M=500020;
int n,m,Q;
LL a0[M];
vct <pair<int,LL> > v[M];
cLL inf=1e18;
LL dis[N][N];
void main_solve()
{
    int tp_,d_;
    scanf("%d%d%d%d%d",&tp_,&n,&m,&d_,&Q);
    For(i,1,m) scanf("%lld",&a0[i]);
    For(i,1,n)
    {
        int len; scanf("%d",&len);
        while(len--)
        {
            int x; LL w; scanf("%d%lld",&x,&w);
            v[x].pb({i,w});
        }
    }
    For(i,1,n)
    {
        memset(dis[i],0x3f,(n+1)<<3);
        dis[i][i]=0ll;
    }
    For(i,1,m)
    {
        int len=sz(v[i]);
        For_(k1,0,len) For_(k2,0,len)
            get_min(dis[v[i][k1].ft][v[i][k2].ft],v[i][k1].sc+v[i][k2].sc);
    }
    For(k,1,n) For(i,1,n) For(j,1,n) get_min(dis[i][j],dis[i][k]+dis[k][j]);
    while(Q--)
    {
        int x,y; scanf("%d%d",&x,&y);
        LL ans=inf;
        int len1=sz(v[x]),len2=sz(v[y]);
        For_(k1,0,len1) For_(k2,0,len2)
            get_min(ans,dis[v[x][k1].ft][v[y][k2].ft]+v[x][k1].sc+v[y][k2].sc);
        ans+=(a0[x]+a0[y]);
        printf("%lld\n",ans);
    }
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    main_init();
    // int _; scanf("%d",&_); while(_--)
        main_solve();
    return 0;
}