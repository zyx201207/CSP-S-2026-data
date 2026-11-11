#include<bits/stdc++.h>
using namespace std;
long long a[500010],n,dp[500010],ans=-2,cnt=0;
unsigned long long m;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    dp[1]=1;
    unsigned long long ck=0;
    for(int i=2;i<=n;i++){
        if(m-ck-abs(a[i]-a[i-1])*(i-1)>=0&&ck<=m){
            cnt++;
            ck+=abs(a[i]-a[i-1])*(i-1);
        }
        dp[i]=max(dp[i-1],dp[i]+cnt);
        ans=max(ans,dp[i]);
    }
    cout<<ans<<"\n";
    return 0;
}
