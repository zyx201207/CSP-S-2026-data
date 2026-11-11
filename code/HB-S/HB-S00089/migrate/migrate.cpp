#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2000005;
int c,n,d,a[N],f[N],dis[N],ans;
void solve(){
    ans=0;
    cin>>n>>d;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        memset(f,0,sizeof(f));
        memset(dis,0,sizeof(dis));
        f[i]=1,dis[i]=0;
        for(int j=i+1;j<=n;j++){
            int minn=1e18;
            for(int k=i;k<j;k++){
                if(a[j]-a[k]<=d) minn=min(minn,dis[k]);
            }
            for(int k=i;k<j;k++) if(a[j]-a[k]<=d&&dis[k]==minn) f[j]+=f[k],dis[j]=dis[k]+1;
        }
        for(int j=i+1;j<=n;j++){
            if(f[j]==2) ans++;
        }
    }
    cout<<ans<<endl;
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int T;cin>>c>>T;
    while(T--) solve();
    return 0;
}
