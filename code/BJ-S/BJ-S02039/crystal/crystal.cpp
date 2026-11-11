#include <iostream>
#include <algorithm>
using namespace std;
long long n,m;long long a[500005];long long ans=1,now=0;long long dp[5005][5005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for (long long i=1;i<=n;i++){
        cin>>a[i];
    }

    sort(a+1,a+n+1);
    if (n>5003){

    for(long long i=2;i<=n;i++){
        if(now+(a[i]-a[i-1])*ans<=m){
            now+=(a[i]-a[i-1])*ans;
            ans++;
            cout<<a[i]<<' '<<a[i-1]<<' '<<(a[i]-a[i-1])<<' '<<now<<' '<<ans<<endl;
        }
    }
    cout<<ans;}else{
    for (long long i=1;i<=n;i++){
        for (long long j=i;j<=n;j++){
            if(dp[i][j-1]!=-1){
                if(dp[i][j-1]+(a[j]-a[j-1])*(j-i)<=m){
                    //cout<<i<<' '<<j<<' '<<dp[i][j-1]<<' '<<m<<endl;
                    dp[i][j]=dp[i][j-1]+(a[j]-a[j-1])*(j-i);
                    ans=max(ans,j-i+1);

                }else{
                    dp[i][j]=-1;
                }
            }else{
                dp[i][j]=-1;
            }

        }
    }
    cout<<ans;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
