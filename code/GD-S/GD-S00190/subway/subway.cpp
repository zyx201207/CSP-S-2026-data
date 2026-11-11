#include<bits/stdc++.h>
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int,int>
#define fi first
#define se second
#define eb emplace_back
using namespace std;

inline int read(){
    char c=getchar();int f=1,x=0;
    for(;c<'0'||c>'9';c=getchar())if(c=='-') f=-1;
    for(;'0'<=c&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
    return x*f;
}

const int N=510,M=5e5+10,mod=998244353;
int c,n,m,d,q,w[M];ll f[N][N];
vector<pii> V[M];int len[N];
inline void ck(ll &x,ll y){(x>y)&&(x=y);}
void Apeiria(){
    memset(f,0x3f,sizeof(f));
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    rep(i,1,m) w[i]=read();
    rep(i,1,n){
        int k=read();len[i]=k;
        rep(j,1,k){
            int x=read(),t=read();
            V[x].eb(i,t);
        }
    }
    rep(i,1,n) f[i][i]=0;
    rep(i,1,m){
        int n=V[i].size();
        rep(x,0,n-1)rep(y,x+1,n-1){
            ll a=V[i][x].fi,b=V[i][y].fi,t=V[i][x].se+V[i][y].se;
            ck(f[a][b],t);ck(f[b][a],t);
        }
    }
    rep(k,1,n)rep(i,1,n)rep(j,1,n) ck(f[i][j],f[i][k]+f[k][j]);
    rep(_,1,q){
        int x=read(),y=read();ll res=1e18;
        for(auto [a,p]:V[x])for(auto [b,q]:V[y]) ck(res,f[a][b]+p+q);
        printf("%lld\n",res+w[x]+w[y]);
    }
}

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int T=1;
    rep(i,1,T) Apeiria();
    return 0;
}
