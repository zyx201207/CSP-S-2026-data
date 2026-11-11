#include<bits/stdc++.h>
using namespace std;
int n;
long long m,ans=0;
long long a[500005];
long long dp[500005];
long long cnt;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
      dp[1]=0;
      cnt=1;
      for(int i=2;i<=n;i++){
            if(dp[i-1]+abs(a[i]-a[i-1])*cnt>m){
                ans=max(ans,cnt);
                while(dp[i-1]+abs(a[i]-a[i-1])*cnt>m){
                    dp[i-1]-=abs(a[i-1]-a[i-cnt+1]);
                    cnt--;
                }
            }

            dp[i]=dp[i-1]+abs(a[i]-a[i-1])*cnt;
            cnt++;
      }
      ans=max(ans,cnt);
   printf("%lld",ans);
    return 0;
}
