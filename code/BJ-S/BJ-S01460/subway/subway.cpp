#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,f[505][505],a[5005][505],t[5005][505],w[500005];
struct nd{
    int u,w;
};
vector<nd>g[500005];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    //cin>>c>>n>>m>>d>>q;
    memset(f,0x3f,sizeof f);
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>a[i][j]>>t[i][j];
        }
        for(int j=1;j<=k;j++){
            f[a[i][j]][a[i][j]]=0;
            if(j==k) continue;
            for(int l=1;l<=k-1;l++){
                f[a[i][j]][a[i][j+l]]=t[i][j]+t[i][j+l];
                f[a[i][j+l]][a[i][j]]=t[i][j]+t[i][j+l];
            }
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++){
            for(int k=1;k<=m;k++){
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
                //cout<<i<<" "<<j<<" "<<" "<<k<<" "<<f[i][j]<<endl;
            }
        }
    }
    //for(int i=1;i<=m;i++){
    //    for(int j=1;j<=m;j++){
    //        cout<<f[i][j]<<" ";
    //    }
    //    cout<<endl;
    //}
    while(q--){
        int x,y;
        scanf("%d%d",&x,&y);
        int num=f[x][y]+w[x]+w[y];
        printf("%d\n",num);
    }
    return 0;
}
