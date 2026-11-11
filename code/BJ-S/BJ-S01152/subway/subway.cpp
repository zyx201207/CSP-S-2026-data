#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q,a[505][5005],x[5005],g[5005][5005],ans[5005][5005];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>x[i];
    }
    for(int i=1;i<=n;i++){
        int y;
        cin>>y;
        for(int j=1;j<=y;j++){
            int g1,g2;
            cin>>g1>>g2;
            a[i][g1]=g2;
        }
    }
    memset(g,0x3f,sizeof(g));
    for(int i=1;i<=m;i++){
        g[i][i]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            for(int k=1;k<=m;k++){
                if(a[i][j]!=0&&a[i][k]!=0) g[j][k]=min(g[j][k],a[i][j]+a[i][k]);
            }
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++){
            if(g[i][j]>=1061109560) g[i][j]=0;
            else ans[i][j]=g[i][j];
        }
    }
    for(int k=1;k<=m;k++){
        for(int i=1;i<=m;i++){
            for(int j=1;j<=m;j++){
                if(ans[i][k]!=0&&ans[k][j]!=0&&ans[i][j]!=0) ans[i][j]=min(ans[i][j],ans[i][k]+ans[k][j]);
                else if(ans[i][k]!=0&&ans[k][j]!=0&&ans[i][j]==0) ans[i][j]=ans[i][k]+ans[k][j];
                else if(ans[k][j]!=0&&ans[i][j]==0&&i==k||ans[i][k]!=0&&j==k&&ans[i][j]==0) ans[i][j]=ans[i][k]+ans[k][j];
                else if(ans[i][k]!=0&&j==k&&ans[i][j]!=0||i==k&&ans[k][j]!=0&&ans[i][j]!=0) ans[i][j]=min(ans[i][j],ans[i][k]+ans[k][j]);
            }
        }
    }
    for(int i=1;i<=q;i++){
        int u,v;
        cin>>u>>v;
        cout<<ans[u][v]+x[u]+x[v]<<endl;
    }
    return 0;
}
