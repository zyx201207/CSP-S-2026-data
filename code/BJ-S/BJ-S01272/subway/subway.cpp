#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,ll> pil;
typedef pair<ll,int> pli;
typedef pair<ll,ll> pll;
template<typename T>
void chkmin(T &x,const T &y){x=min(x,y);}
template<typename T>
void chkmax(T &x,const T &y){x=max(x,y);}
const int inf=0x3f3f3f3f;
const ll infll=0x3f3f3f3f3f3f3f3f;
const int MOD=998244353;
void add(int &x,int y){
    x+=y;
    if(x>=MOD) x-=MOD;
}
int add2(int x,int y){
    add(x,y);
    return x;
}
int qpow(int a,ll b){
    int mul=1;
    for(;b;b>>=1,a=(ll)a*a%MOD) if(b&1) mul=(ll)mul*a%MOD;
    return mul;
}
const int N=500,M=500005;
int n,m,d,q;
ll w[M],dis[N][N];
vector<pli> line[M];
void __INIT__(){}
void __SOLVE__(){
    scanf("%d%d%d%d",&n,&m,&d,&q);
    for(int i=1;i<=m;i++) scanf("%lld",&w[i]);
    for(int i=1;i<=n;i++){
        int k;
        scanf("%d",&k);
        for(int j=1;j<=k;j++){
            int a;ll t;
            scanf("%d%lld",&a,&t);
            line[a].push_back({i,t});
        }
    }
    memset(dis,0x3f,sizeof(dis));
    for(int i=1;i<=n;i++) dis[i][i]=0;
    for(int i=1;i<=m;i++){
        for(int x=0;x<line[i].size();x++){
            for(int y=x+1;y<line[i].size();y++){
                auto [u,tu]=line[i][x];
                auto [v,tv]=line[i][y];
                dis[u][v]=dis[v][u]=tu+tv;
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) chkmin(dis[i][j],dis[i][k]+dis[k][j]);
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++) printf("%lld ",dis[i][j]);
    //     printf("\n");
    // }
    while(q--){
        int x,y;
        scanf("%d%d",&x,&y);
        ll ans=infll;
        for(int i=0;i<line[x].size();i++){
            for(int j=0;j<line[y].size();j++){
                auto [u,tu]=line[x][i];
                auto [v,tv]=line[y][j];
                chkmin(ans,w[x]+w[y]+dis[u][v]+tu+tv);
            }
        }
        printf("%lld\n",ans);
    }
}
int main(){
    #ifndef JZQ
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    #endif
    int T=1;
    scanf("%*d");
    __INIT__();
    while(T--) __SOLVE__();
    return 0;
}