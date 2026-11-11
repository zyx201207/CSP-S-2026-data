#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>
#define int long long
using namespace std;

const int M=500005,N=505;

int w[M];
struct train{
    int t,id;
};vector<train> v[M];
int dis[N][N];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("subway.in","r",stdin);
    //freopen("subway/subway7.in","r",stdin);
    freopen("subway.out","w",stdout);

    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;++i){
        cin>>w[i];
    }for(int i=1;i<=n;++i){
        int k;
        cin>>k;
        while(k--){
            int a,t;
            cin>>a>>t;
            v[a].push_back({t,i});
        }
    }
    memset(dis,0x3f,sizeof(dis));
    for(int i=1;i<=n;++i) dis[i][i]=0;
    for(int i=1;i<=m;++i){
        for(auto x:v[i]){
            for(auto y:v[i]){
                int u=x.id,v=y.id,t=x.t+y.t;
                dis[u][v]=dis[v][u]=min(dis[u][v],t);
            }
        }
    }
    for(int k=1;k<=n;++k){
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        int ans=1e18;
        for(auto p:v[x]){
            for(auto q:v[y]){
                ans=min(ans,w[x]+w[y]+p.t+q.t+dis[p.id][q.id]);
            }
        }cout<<ans<<'\n';
    }
    return 0;
}
