#include<bits/stdc++.h>
using namespace std;
const int N=505,M=5e5+10,inf=1e9+7;
int c,n,m,d,q;
int w[M];
int k[N];
int a[N][M],t[N][M];
struct edge{
    int to,wei;
};
vector<edge> g[M];
vector<int> line[M];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j];
            line[a[i][j]].push_back(i);
        }
        for(int j=1;j<=k[i];j++){
            cin>>t[i][j];
            g[a[i][j]].push_back((edge){i,t[i][j]});
        }
    }
    int x,y;
    if(n==1){
        int tt[M];
        for(int i=1;i<=k[1];i++){
            tt[a[1][i]]=t[1][i];
        }
        while(q--){
            cin>>x>>y;
            cout<<w[x]+w[y]+tt[x]+tt[y];
        }
        return 0;
    }
    if(n==2){
        int minn=inf;
        int tt[3][M];
        for(int i=1;i<=k[1];i++){
            tt[1][a[1][i]]=t[1][i];
            tt[2][a[1][i]]=inf;
        }
        for(int i=1;i<=k[2];i++){
            tt[2][a[2][i]]=t[2][i];
        }
        for(int i=1;i<=k[1];i++){
            if(tt[2][a[1][i]]!=inf){
                minn=min(minn,tt[1][a[1][i]]+tt[2][a[1][i]]);
            }
        }
        while(q--){
            cin>>x>>y;
            int ans=inf;
            if(tt[1][x]!=inf&&tt[1][y]!=inf){
                ans=min(ans,w[x]+w[y]+tt[1][x]+tt[1][y]);
            }
            if(tt[2][x]!=inf&&tt[2][y]!=inf){
                ans=min(ans,w[x]+w[y]+tt[2][x]+tt[2][y]);
            }
            ans=min(ans,w[x]+w[y]+minn+min(tt[1][x]+tt[2][y],tt[1][y]+tt[2][x]));
            cout<<ans<<'\n';
        }
        return 0;
    }
    while(q--){
        cin>>x>>y;
        cout<<w[x]+w[y]<<"\n";
    }
    return 0;
}
