#include<bits/stdc++.h>
using namespace std;
long long int a[200005],n,m,dp[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=0;i<=m;i++)dp[i]=1073741823;
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
        for(int j=min((long long int)i,m);j>=1;j--)
            if(dp[j]==1073741823)dp[j]=dp[j-1]&a[i];
            else dp[j]=max(dp[j],dp[j-1]&a[i]);
    cout<<dp[m];
    return 0;
}
