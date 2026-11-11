#include<bits/stdc++.h>
using namespace std;
#define gc() getchar_unlocked()
#define pc(x) putchar_unlocked(x)
inline int read(){
    int x=0,c=gc();
    while(!isdigit(c))c=gc();
    do{
        x=(x<<1)+(x<<3)+(c^48);
        c=gc();
    }while(isdigit(c));
    return x;
}
typedef long long ll;
const int N=505,M=5e5+5,Q=1e5+5;
int c,n,m,d,q;
int w[M];
int k[N];
struct side{
    int v;
    ll val;
};
vector<side> e[N+M];
const ll inf=LLONG_MAX/10;
ll dst[N][N];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin.tie(0)->sync_with_stdio(0);
    c=read();
    n=read();
    m=read();
    d=read();
    q=read();
    for(int i=1;i<=m;i++){
        w[i]=read();
    }
    for(int i=1;i<=n;i++){
        k[i]=read();
        for(int j=1,a,t;j<=k[i];j++){
            a=read();
            t=read();
            e[a].push_back((side){i,t});
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dst[i][j]=inf;
        }
        dst[i][i]=0;
    }
    for(int a=1;a<=m;a++){
        for(auto i:e[a]){
            for(auto j:e[a]){
                if(i.v==j.v)continue ;
                dst[i.v][j.v]=min(dst[i.v][j.v],i.val+j.val);
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            if(dst[i][k]==inf)continue ;
            for(int j=1;j<=n;j++){
                if(dst[k][j]==inf)continue ;
                dst[i][j]=min(dst[i][j],dst[i][k]+dst[k][j]);
            }
        }
    }
    while(q--){
        int x,y;
        x=read();
        y=read();
        ll ans=inf,sum;
        for(auto i:e[x]){
            for(auto j:e[y]){
                sum=i.val+j.val+dst[i.v][j.v];
                ans=min(ans,sum);
            }
        }
        ans+=w[x]+w[y];
        cout<<ans<<'\n';
    }
    return 0;
}