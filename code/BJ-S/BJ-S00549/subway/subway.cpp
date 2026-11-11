#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5,M=505,inf=1e18;
int c,n,m,d,q,k[N],f[M][M],a[N];
struct T{
    int v,w;
};
vector<T>nxt[N];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>a[i];
    memset(f,0x3f,sizeof(f));
    for(int i=1;i<=n;i++){
        cin>>k[i],f[i][i]=0;
        for(int j=1,v,w;j<=k[i];j++){
            cin>>v>>w;
            nxt[v].push_back({i,w});
        }
    }
    for(int i=1;i<=m;i++){
        for(T x:nxt[i]){
            int u=x.v;
            for(T y:nxt[i]){
                int v=y.v,w=y.w+x.w;
                f[u][v]=f[v][u]=min(f[u][v],w);
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            for(int k=1;k<=n;k++){
                f[i][j]=f[j][i]=min(f[i][j],f[i][k]+f[k][j]);
            }
        }
    }
    while(q--){
        int u,v,ans=inf;cin>>u>>v;
        for(T x:nxt[u]){
            for(T y:nxt[v]){
                ans=min(ans,f[x.v][y.v]+x.w+y.w+a[u]+a[v]);
            }
        }
        cout<<ans<<'\n';
    }
}//因为不知道地铁是双向卡了1.5h...