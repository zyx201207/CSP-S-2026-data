#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q,w[510],a[500010],dis[2010][2010],t[500010];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    memset(dis,0x3f,sizeof dis);
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>a[j]>>t[j];
        }
        for(int j=1;j<=k;j++){
            for(int l=j+1;l<=k;l++){
                dis[a[j]][a[l]]=min(t[j]+t[l],dis[a[j]][a[l]]);
                dis[a[l]][a[j]]=min(t[j]+t[l],dis[a[l]][a[j]]);
            }
        }
    }
    for(int i=1;i<=m;i++){
        dis[i][i]=0;
    }
    for(int k=1;k<=m;k++){
        for(int i=1;i<=m;i++){
            for(int j=1;j<=m;j++){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        if(x==y){
            cout<<0<<'\n';
            continue;
        }
        cout<<dis[x][y]+w[x]+w[y]<<'\n';
    }
    return 0;
}
