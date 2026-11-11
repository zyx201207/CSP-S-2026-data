#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=505;
ll a[N],n,f[N][N],d,inf=1e18,sum[N][N];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ll T,c; cin>>c>>T;
    ll ans=0;
    while(T--){
        cin>>n>>d;
        ans=0;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n-2;i++){
            for(int j=0;j<=n;j++) f[i][j]=f[i+1][j]=sum[i][j]=sum[i+1][j]=sum[i-1][j]=0;
            f[i][0]=1;f[i+1][1]=1;
            sum[i][0]=1;sum[i+1][0]=1;sum[i+1][1]=1;
            for(int j=i+2;j<=n;j++){
                int x=lower_bound(a+i,a+j,a[j]-d)-a;
                // cout<<i<<"-"<<j<<" "<<x<<"\n";          
                int fl=0;
                for(int k=1;k<=n;k++){
                    f[j][k]=sum[j-1][k-1]-sum[x-1][k-1];
                    // cout<<f[j][k]<<"/"<<sum[j-1][k-1]<<"/"<<k-1<<" ";
                    sum[j][k]=sum[j-1][k]+max(f[j][k],0ll);
                    if(f[j][k]>0 && !fl) fl=f[j][k];
                    // if(f[j][k]>0 && fl) fl=-1;
                }
                sum[j][0]=sum[j-1][0];
                // cout<<"\n";
                // cout<<fl<<"\n";
                if(fl==2) ans++;//cout<<i<<" "<<j<<"\n";
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
/*
0 1
6 3
0 1 2 3 4 7

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/