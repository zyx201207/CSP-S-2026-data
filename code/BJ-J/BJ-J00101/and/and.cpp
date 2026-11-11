#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
ll n,m,a[200005],ans;
ll dp[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);//输入
        //dp[i]=max(a[i],dp[i-1]);//dp[1][i]
        dp[i]=a[i];
    }//dp[i][j]表示取出i个数，最后一位必须是a[j]
    for(int i=2;i<=m;i++){
        for(int j=n;j>=i;j--){
            dp[j]=dp[j-1]&a[i];
            //for(int j=i;j<=n;j++){
            for(int k=i-1;k<j;k++){
                //dp[j]=dp[j-1]&a[j];
                dp[j]=max(dp[k]&a[j],dp[j]);
            }
        }
    }
    for(int i=m;i<=n;i++){
        ans=max(ans,dp[i]);
    }
    cout<<ans;
    return 0;
}

