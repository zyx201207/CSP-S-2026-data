#include<bits/stdc++.h>
#define N 210
#define M 410
#define int long long
using namespace std;

int c,n,m,d,q;
int a[M],f[N][M][M];
int dist[M][M];

signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        int k; cin>>k;
        pair<int,int> temp[N]={};
        for(int j=1;j<=k;j++){
            cin>>temp[j].first>>temp[j].second;
        }
        sort(temp+1,temp+k+1);
        for(int j=1;j<=k;j++){
            for(int jj=1;jj<=k;jj++){
                int fi1=temp[j].first,se1=temp[j].second,fi2=temp[jj].first,se2=temp[jj].second;
                if(j!=jj) f[i][fi1][fi2]=se1+se2;
            }
        }
    }
    memset(dist,0x3f,sizeof dist);
    for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++){
            for(int k=1;k<=n;k++){
                if(f[k][i][j]==0) continue;
                dist[i][j]=min(dist[i][j],f[k][i][j]);
            }
        }
    }
    for(int k=1;k<=m;k++){
        for(int i=1;i<=m;i++){
            for(int j=1;j<=m;j++){
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }
    for(int i=1;i<=q;i++){
        int u,v;
        cin>>u>>v;
        cout<<dist[u][v]+a[u]+a[v]<<'\n';
    }
    return 0;
}
