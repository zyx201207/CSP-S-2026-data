#include<bits/stdc++.h>
#define int long long
#define ll long long
#define ull unsigned long long
#define f(i,j,n) for(int i=(j);i<=(n);i++)
#define F(i,n,j) for(int i=(n);i>=(j);i--)
#define updmin(a,b) a=min(a,b)
#define updmax(a,b) a=max(a,b)
#define updsum(a,b) a=(a+(b))%mod
#define pri_grt(x) x,vector<x>,greater<x>
#define arr(x) array<int,x>
#define arrl(x) array<ll,x>
#define pb push_back
using namespace std;
typedef pair<int,int> pii;
namespace fsd{
    #define gc() (p1==p2&&(p2=(p1=buf)+fread(buf,1,MX,stdin)),p1==p2?EOF:*p1++)
    const int MX=1<<20;
    char buf[MX],*p1,*p2;
    inline int read(){
        int ak=0,csp=1;
        char c=gc();
        while(!isdigit(c)){if(c=='-')csp=-1;c=gc();}
        while(isdigit(c))ak=ak*10+(c-'0'),c=gc();
        return ak*csp;
    }
}
using fsd::read;
const int N=5e5+10;
const int inf=LLONG_MAX/4;
int cc,n,m,D,q;
int val[N];
vector<pii> to[510];
arr(2) hv[N][21];
int ct[N];
int d[510][510];
void gs(){
    cc=read(),n=read(),m=read(),D=read(),q=read();
    f(i,1,m)val[i]=read();
    f(i,1,n){
        int s=read();
        f(j,1,s){
            int v=read(),w=read();
            to[i].pb({v,w}),hv[v][++ct[v]]={i,w};
        }
    }
    f(i,1,n)f(j,1,n)d[i][j]=i==j?0:inf;
    f(i,1,n){
        for(auto [v,w]:to[i])f(j,1,ct[v])updmin(d[i][hv[v][j][0]],w+hv[v][j][1]);
    }
    f(k,1,n)f(i,1,n)f(j,1,n)updmin(d[i][j],d[i][k]+d[k][j]);
    f(i,1,q){
        int u=read(),v=read();
        int ans=inf;
        f(x,1,ct[u])f(y,1,ct[v])updmin(ans,val[u]+hv[u][x][1]+d[hv[u][x][0]][hv[v][y][0]]+hv[v][y][1]+val[v]);
        printf("%lld\n",ans);
    }
}
// #define XQZ
signed main(){
#ifndef XQZ
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
#endif
#ifdef NXD
    int t=0;cin>>t;while(t--)
#endif
    gs();
    cerr<<"time:"<<clock()<<"ms.\n";
    return 0;
}