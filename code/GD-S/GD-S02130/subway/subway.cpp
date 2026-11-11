#include<bits/stdc++.h>
using namespace std;
#define online
constexpr int maxn=501;
constexpr int maxm=501010;
long long a[maxm];
long long w[maxm];
struct edge{
    long long t,v;
};
vector<edge> e[maxm];
long long floyd[maxn][maxn];
int main(){
    #ifdef online
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    #endif
    ios::sync_with_stdio(false);cin.tie(0);
    memset(floyd,0x3f,sizeof(floyd));
    int c,n,m,d,q;cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=n;i++)floyd[i][i]=0;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        int k;cin>>k;
        for(int x=1;x<=k;x++){
            int a,t;cin>>a>>t;
            e[a].push_back(edge{i,t});
        }
    }
    for(int i=1;i<=m;i++){
        for(auto x:e[i])for(auto y:e[i]){
            floyd[x.t][y.t]=min(floyd[x.t][y.t],x.v+y.v);
        }
    }
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)for(int k=1;k<=n;k++){
        floyd[j][k]=min(floyd[j][k],floyd[j][i]+floyd[i][k]);
    }
    for(int i=1;i<=q;i++){
        int p,q;cin>>p>>q;
        long long ans=1e18;
        for(auto x:e[p])for(auto y:e[q]){
            ans=min(ans,x.v+floyd[x.t][y.t]+y.v);
        }
        ans+=w[p]+w[q];
        cout<<ans<<'\n';
    }
    return 0;
}