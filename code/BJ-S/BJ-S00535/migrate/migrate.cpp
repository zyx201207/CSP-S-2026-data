#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,d,c,T,a[2000006],dis[505][505],path[505][505];
inline void slvA(){
    int k=a[2]-a[1];
    if(d<=k){
        cout<<0<<'\n';
        return;
    }int id=d/k;
    cout<<max(0ll,n-id-id+1ll)<<'\n';
    return;
}inline void slv1(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) dis[i][j]=dis[j][i]=llabs(a[i]-a[j]);
    }int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(dis[i][j]<=d) continue;
            int cnt=0ll;
            for(int k=i+1;k<j;k++){
                if(dis[i][k]<=d&&dis[k][j]<=d) cnt++;
            }if(cnt==2ll) ans++;
        }
    }cout<<ans<<'\n';
    return;
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>T;
    while(T--){
        cin>>n>>d;
        for(int i=1;i<=n;i++) cin>>a[i];
        if(c==11||c==12) slvA();
        else if(c<=6) slv1();
    }
    return 0;
}