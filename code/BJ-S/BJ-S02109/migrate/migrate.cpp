#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,n,d,C,a[2000001],dp[2000001],dis[2000001],ans;
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>C>>t;
    while(t--){
        cin>>n>>d,ans=0;
        for(int i=1;i<=n;i++)cin>>a[i];
        if(C>=11&&C<=12){
            int c=a[2]-a[1],t=__gcd(c,d);
            c/=t,d/=t,d-=d%c;
            if(c>=d)cout<<"0\n";
            else cout<<max(0ll,n-(d*2-1)/c)<<"\n";
            continue;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++)dp[j]=0,dis[j]=-1;
            dp[i]=1,dis[i]=0;
            for(int j=i;j<=n;j++){
                for(int k=j+1;k<=n;k++){
                    if(a[k]-a[j]>d)break;
                    if(dis[k]<0)dis[k]=dis[j]+1;
                }
            }
            for(int j=i;j<=n;j++){
                for(int k=j+1;k<=n;k++){
                    if(a[k]-a[j]>d)break;
                    if(dis[k]==dis[j]+1&&dp[j]<100)dp[k]+=dp[j];
                }
            }
            for(int j=i;j<=n;j++)if(dp[j]==2)ans++;
        }
        cout<<ans<<"\n";
    }
    return 0;
}
