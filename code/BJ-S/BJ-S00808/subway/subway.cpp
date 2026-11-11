#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005],a[505][500005],t[505][500005],x,y;
int ds[505][505],k[500005],maxn;

int main(void)
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k[i];
        maxn=max(maxn,k[i]);
        for(int j=1;j<=k[i];j++) cin>>a[i][j]>>t[i][j];
    }
    memset(ds,0x3f,sizeof(ds));
    if(maxn<=2){
        for(int i=1;i<=n;i++){
            ds[i][i]=0;
            if(k[i]==2){
                ds[a[i][1]][a[i][2]]=t[i][1]+t[i][2];
                ds[a[i][2]][a[i][1]]=t[i][1]+t[i][2];
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                ds[i][j]=min(ds[i][j],ds[i][k]+ds[k][j]);
            }
        }
    }
    while(q--){
        cin>>x>>y;
        cout<<ds[x][y]<<endl;
    }

    return 0;
}
