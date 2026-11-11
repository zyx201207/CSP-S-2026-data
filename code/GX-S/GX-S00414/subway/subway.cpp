#include<bits/stdc++.h>
using namespace std;
struct ed{
    int v;
    long long w;
};
vector<ed>g[505];
int c,n,m,k,d,q;
long long f[505][505],wv[500005],t[505][500005];
vector<int>id[500005];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>wv[i];
    for(int i=1;i<=n;i++){
        cin>>k;
        for(int j=1;j<=k;j++){
            int x;
            cin>>x;
            cin>>t[i][x];
            id[x].push_back(i);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            f[i][j]=1e18;
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=0;j<id[i].size();j++){
            for(int k=0;k<id[i].size();k++){
                int u=id[i][j],v=id[i][k];
                if(u==v)f[u][v]=0;
                else f[u][v]=min(f[u][v],t[u][i]+t[v][i]);
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i==j)continue;
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
            }
        }
    }
    while(q--){
        int x,y;
        long long ans=1e18;
        cin>>x>>y;
        for(int i=0;i<id[x].size();i++){
            for(int j=0;j<id[y].size();j++){
                int u=id[x][i],v=id[y][j];
                if(u==v){
                    ans=min(wv[x]+wv[y]+t[u][x]+t[v][y],ans);
                }else ans=min(ans,f[u][v]+wv[x]+wv[y]+t[u][x]+t[v][y]);
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
