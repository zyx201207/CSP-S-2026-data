#include<bits/stdc++.h>
#define int long long
#define inf 1e18
#define rep(i,a,b) for(int i=(a);i<=(int)(b);i++)
#define per(i,a,b) for(int i=(a);i>=(int)(b);i--)
#define all(v) v.begin(),v.end()
#define lb(x) ((x) & -(x))
#define clz(x) __builtin_clz(x)
#define lg(x) (clz(1)-clz(x))
#define fi first
#define se second
#define mkp make_pair
#define pb emplace_back
#define siz(x) ((int)x.size())
using namespace std;
const int N=5e5+10,M=510;
int n,m,d,Q,w[N],dis[M][M];
vector<int> to[N],cs[N];
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int C; cin>>C;
    cin>>n>>m>>d>>Q;
    rep(i,1,m) cin>>w[i];
    rep(i,1,n)
    {
        int k,x,y; cin>>k;
        rep(j,1,k) cin>>x>>y,to[x].pb(i),cs[x].pb(y);
    }
    rep(i,1,n) rep(j,1,n) dis[i][j]=(i==j?0:inf);
    rep(i,1,m)
        rep(t1,0,siz(to[i])-1) rep(t2,0,siz(to[i])-1)
        {
            int x=to[i][t1],y=to[i][t2];
            dis[x][y]=min(dis[x][y],cs[i][t1]+cs[i][t2]);
        }
    rep(k,1,n) rep(i,1,n) rep(j,1,n) dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    while(Q--)
    {
        int x,y,res=inf; cin>>x>>y;
        rep(t1,0,siz(to[x])-1) rep(t2,0,siz(to[y])-1) res=min(res,cs[x][t1]+cs[y][t2]+dis[to[x][t1]][to[y][t2]]);
        cout<<res+w[x]+w[y]<<"\n";
    }
    return 0;
}

