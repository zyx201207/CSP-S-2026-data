#include<iostream>
#include<vector>
#include<cstring>
#define int long long
using namespace std;
typedef pair < int,int > pii;
const int inf=1e17;
int c,n,m,d,q,w[500005],f[505][505];
vector < pii > r[500005];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            f[i][j]=inf;
        }
    }
    for(int i=1;i<=n;i++) f[i][i]=0;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int a,t;
            cin>>a>>t;
            r[a].push_back({i,t});
        }
    }
    for(int i=1;i<=m;i++){
        int len=r[i].size();
        for(int p1=0;p1<len;p1++){
            for(int p2=p1+1;p2<len;p2++){
                int u=r[i][p1].first,v=r[i][p2].first;
                int w=r[i][p1].second+r[i][p2].second;
                f[u][v]=min(f[u][v],w);
                f[v][u]=min(f[v][u],w);
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
            }
        }
    }
    while(q--){
        int u,v;
        cin>>u>>v;
        int ans=inf;
        for(auto x:r[u]){
            for(auto y:r[v]){
                int a=x.first,b=y.first;
                int w=x.second+y.second;
                ans=min(ans,w+f[a][b]);
            }
        }
        cout<<ans+w[u]+w[v]<<endl;
    }
}