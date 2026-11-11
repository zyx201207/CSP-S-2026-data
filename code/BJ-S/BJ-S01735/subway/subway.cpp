#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=502,M=500005,K=500005;
int c,n,m,d,q,w[M];
int k,x,y,ans;
struct Edge{
    int v,t;
};
vector<Edge> line[M];
int dist[N][N];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k;
        for(int j=1;j<=k;j++){
            int a,t;
            cin>>a>>t;
            line[a].push_back({i,t});
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j) dist[i][j]=0;
            else dist[i][j]=-1;
        }
    }
    for(int p=1;p<=m;p++){
        int s=line[p].size();
        for(Edge e1:line[p]){
            for(Edge e2:line[p]){
                int t=e1.t+e2.t;
                int u=e1.v,v=e2.v;
                if(dist[u][v]==-1||dist[u][v]>t){
                    dist[u][v]=t;
                }
            }
        }
    }
    for(int p=1;p<=n;p++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(dist[i][p]==-1||dist[j][p]==-1) continue;
                if(dist[i][j]==-1||dist[i][p]+dist[j][p]<dist[i][j]){
                    dist[i][j]=dist[i][p]+dist[j][p];
                }
            }
        }
    }
    for(int r=1;r<=q;r++){
        cin>>x>>y;
        ans=-1;
        for(Edge e1:line[x]){
            for(Edge e2:line[y]){
                int u=e1.v,v=e2.v;
                int t=dist[u][v]+e1.t+e2.t;
                if(ans==-1||t<ans) ans=t;
            }
        }
        ans+=w[x]+w[y];
        cout<<ans<<endl;
    }
    return 0;
}
