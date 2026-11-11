#include<bits/stdc++.h>
#define debug(x) cerr<<#x<<"="<<x<<endl
#define gc getchar_unlocked
#define pc putchar_unlocked
#define pii pair<int,int>
#define fi first
#define se second
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define i128 __int128
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
namespace IO{
    template<typename T>
    inline void read(T &x){
        x=0;bool fl=1;
        char c=gc();
        while(c<'0'||c>'9'){if(c=='-')fl=0;c=gc();}
        while(c>='0'&&c<='9') x=(x<<1)+(x<<3)+(c^48),c=gc();
        x=fl?x:-x;
    }
    template<typename T>
    inline void write(T x){
        if(x<0) pc('-'),x=-x;
        if(x>9) write(x/10);
        pc(x%10+'0');
    }
}using namespace IO;
const int N=505,M=5e5+5;
const ll inf=4e18;
int tid,n,m,d,q;
int w[M];
ll dis[N][N];
vector<pii>v[M];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    read(tid),read(n),read(m),read(d),read(q);
    rep(i,1,m) read(w[i]);
    rep(i,1,n){
        int k;read(k);
        rep(j,1,k){
            int x,t;
            read(x),read(t);
            v[x].push_back({i,t});
        }
    }
    rep(i,1,n) rep(j,1,n) dis[i][j]=inf;
    rep(i,1,n) dis[i][i]=0;
    rep(i,1,m){
        for(pii p1:v[i]){
            int u=p1.fi;ll w1=p1.se;
            for(pii p2:v[i]){
                int v=p2.fi;ll w2=p2.se;
                dis[u][v]=dis[v][u]=min(dis[u][v],w1+w2);
            }
        }
    }
    rep(k,1,n){
        rep(i,1,n){
            rep(j,1,n){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    while(q--){
        int x,y;
        read(x),read(y);
        ll ans=inf;
        for(pii p1:v[x]){
            int u=p1.fi;ll w1=p1.se;
            for(pii p2:v[y]){
                int v=p2.fi;ll w2=p2.se;
                ans=min(ans,dis[u][v]+w1+w2);
            }
        }
        write(ans+w[x]+w[y]),pc('\n');
    }
    return 0;
}