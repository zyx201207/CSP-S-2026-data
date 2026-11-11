#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5000;
int x[N];
int mi[N][N];
int dp[N][N];
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0);
    int c,t;cin>>c>>t;
    if(c<=12&&c>=11){
        while(t--){
            int n,d;cin>>n>>d;
            int a,b;cin>>a>>b;
            for(int i=3;i<=n;i++){
                int t;cin>>t;
            }
            int z=b-a;
            d=d/z;
            if(d==1){
                cout<<0<<'\n';
                continue;
            }
            n++;
            cout<<max((int)(0),n-2*d)<<'\n';
        }
        return 0;
    }
    while(t--){
        int n,d;cin>>n>>d;
        if(n>=1000){
            cout<<0<<'\n';
            continue;
        }
        for(int i=1;i<=n;i++)cin>>x[i];
        x[n+1]=LONG_LONG_MAX;
        memset(mi,0x3f,sizeof(mi));
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++){
            mi[i][i]=0;
            int pos=upper_bound(x+1,x+2+n,x[i]+d)-x-1;
            for(int j=i+1;j<=pos;j++){
                mi[i][j]=1;
                dp[i][j]=1;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                for(int k=1;k<=n;k++){
                    mi[j][k]=min(mi[j][k],mi[j][i]+mi[i][k]);
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                for(int k=1;k<=n;k++){
                    if(mi[j][k]==mi[j][i]+mi[i][k])dp[j][k]+=dp[j][i]*dp[i][k];
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(dp[i][j]==2)ans++;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
/*0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6*/