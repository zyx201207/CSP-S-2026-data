# include <bits/stdc++.h>
using namespace std;
const int N=2e3+10;
int c,n,m,q,d,w[N],k[N],t[600][N],a[600][N],g[N][N],e[N][N],x,y;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1; i<=m; i++){
        for(int j=1; j<=m; j++) g[i][j]=INT_MAX;
    }
    for(int i=1; i<=m; i++) scanf("%d",&w[i]);
    for(int i=1; i<=n; i++){
        scanf("%d",&k[i]);
        for(int j=1; j<=k[i]; j++){
            scanf("%d%d",&a[i][j],&t[i][j]);
            for(int l=1; l<j; l++){
                g[a[i][l]][a[i][j]]=min(g[a[i][l]][a[i][j]],t[i][j]+t[i][l]);
                g[a[i][j]][a[i][l]]=min(g[a[i][j]][a[i][l]],t[i][l]+t[i][j]);
            }
        }
    }
    for(int l=1; l<=m; l++){
        for(int i=1; i<=m; i++){
            if(i==l) continue;
            if(g[i][l]==INT_MAX) continue;
            for(int j=i+1; j<=m; j++){
                if(i==j || j==l) continue;
                if(g[l][j]==INT_MAX) continue;
                g[i][j]=g[j][i]=min(g[i][j],g[i][l]+g[l][j]);
            }
        }
    }
    while(q--){
        cin>>x>>y;
        cout<<g[x][y]+w[x]+w[y]<<"\n";
    }
    return 0;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
