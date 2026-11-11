#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=500005;
ll c,n,m,d,q;
ll w[M];
struct node{
    int k;
    ll t;
};
vector<node> e[M];
ll dis[505][505];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    memset(dis,0x3f,sizeof(dis));
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        while(k--){
            int a,t;
            cin>>a>>t;
            e[a].push_back({i,t});
        }
        dis[i][i]=0;
    }
    for(int i=1;i<=m;i++){
        for(auto x:e[i]){
            for(auto y:e[i]){
                if(x.k==y.k&&x.t==y.t) continue;
                int u=x.k;
                int v=y.k;
                dis[u][v]=min(dis[u][v],x.t+y.t);
                dis[v][u]=min(dis[v][u],x.t+y.t);
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        ll ans=0x3f3f3f3f3f3f3f3f;
        for(auto i:e[x]){
            for(auto j:e[y]){
                ans=min(ans,dis[i.k][j.k]+i.t+j.t);
            }
        }
        ans+=w[x]+w[y];
        cout<<ans<<endl;
    }
    return 0;
}
