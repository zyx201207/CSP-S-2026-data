#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,t,n,d;
ll a[1000050];
ll ds[350][350],route[350][350];
ll come[350][350];
void cal(){
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
               if(k!=i&&i!=j&&k!=j){
                    if(route[i][j]>route[i][k]+route[k][j]){
                        route[i][j]=route[i][k]+route[k][j];
                    }
               }
            }
        }
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         cout<<route[i][j]<<' ';
    //     }
    //     cout<<'\n';
    // }
    //cout<<route[1][5]<<'\n';
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(k!=i&&i!=j&&k!=j){
                    if(route[i][j]==route[i][k]+route[k][j]){
                        //cout<<k<<" on path:"<<i<<' '<<j<<'\n';
                        ds[i][j]=ds[i][k]+ds[k][j];
                    }
                }
            }
        }
    }
}
void sol(){
    cin>>n>>d;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) route[i][j]=(i!=j)*0x3f3f3f3f3f3f3f3f;
    }
    memset(ds,0,sizeof ds);
    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
            if(abs(a[i]-a[j])<=d) route[i][j]=route[j][i]=ds[i][j]=ds[j][i]=1;
        }
    }
    cal();
    // cout<<"ds:\n";
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++) cout<<ds[i][j]<<' ';
    //     cout<<'\n';
    // }
    if(c<=6){
        ll ans=0;
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                if(ds[i][j]==2) ans++;
            }
        }
        if(n&1) cout<<ans-1<<'\n';
        else cout<<ans<<'\n';
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--) sol();
    return 0;
}