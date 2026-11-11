#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,dis[5005][5005],w[5005],ans[5005],anstrue[5005],cnt;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=m;i++)for(int j=1;j<=m;j++)dis[i][j]=1e15;
    for(int i=1;i<=n;i++){
        int k;cin>>k;
        long long a[5005],b[5005];
        for(int j=1;j<=k;j++)cin>>a[j]>>b[j];
        for(int j=1;j<=k;j++){
            for(int p=1;p<=k;p++){
                dis[a[j]][a[p]]=min(dis[a[j]][a[p]],b[j]+b[p]);
            }
        }
    }
    for(int i=1;i<=n;i++)dis[i][i]=0;
    for(int k=1;k<=m;k++){
        for(int i=1;i<=m;i++){
            if(dis[i][k]==1e15)continue;
            for(int j=1;j<=m;j++){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        cout<<w[x]+w[y]+dis[x][y]<<endl;
    }
    return 0;
}