#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M=5e5+7;
const int N=507;
int c,n,m,d,q;
struct Edge{
    int v,w;
};
vector<Edge> Rot[M];
int w[M];
int Dis[N][N];
inline void GetEdge(){
    memset(Dis,0x3f,sizeof(Dis));
    for(int i=1;i<=m;i++){
        int S=Rot[i].size();
        // cout<<i<<" "<<S<<endl;
        for(int p=0;p<S;p++){
            for(int q=p+1;q<S;q++){
                int u=Rot[i][p].v,v=Rot[i][q].v;
                Dis[u][v]=min(Dis[u][v],Rot[i][p].w+Rot[i][q].w);
                Dis[v][u]=min(Dis[v][u],Rot[i][p].w+Rot[i][q].w);
            }
        }
    }
}
int f[N][N];
inline void Floyd(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i^j)f[i][j]=Dis[i][j];
            else f[i][j]=0;
        }
    }
    for(int i=1;i<=n;i++){
        for(int u=1;u<=n;u++){
            for(int v=1;v<=n;v++){
                f[u][v]=min(f[u][v],f[u][i]+f[i][v]);
            }
        }
    }
}
inline int Qry(int x,int y){
    int Ans=1e18;
    for(auto e1:Rot[x]){
        for(auto e2:Rot[y]){
            Ans=min(Ans,f[e1.v][e2.v]+e1.w+e2.w);
        }
    }
    return Ans+w[x]+w[y];
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        int k;cin>>k;
        for(int j=1;j<=k;j++){
            int a,t;
            cin>>a>>t;
            Rot[a].push_back((Edge){i,t});
        }
    }
    // for(int i=1;i<=m;i++){
    //     for(auto e:Rot[i]){
    //         cout<<i<<" "<<e.v<<" "<<e.w<<endl;
    //     }
    // }
    GetEdge();
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         cout<<Dis[i][j]<<" ";
    //     }cout<<endl;
    // }
    Floyd();
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         cout<<f[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    while(q--){
        int x,y;
        cin>>x>>y;
        cout<<Qry(x,y)<<endl;
    }
    return 0;
}