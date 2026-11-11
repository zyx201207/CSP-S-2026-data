#include<bits/stdc++.h>
using namespace std;
unsigned long long  d,ans[2000010];
long long s[2000010],p,dp[2000010];
int c,t,n,i;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    for(p=1;p<=t;p++){
        cin>>n>>d;
        for(i=1;i<=n;i++)
            cin>>s[i];
        int x=s[2]-s[1];
        int k=d/x;
        if(d==x){
           ans[p]=0;
        }
        if(k<x) ans[p]=0;
        else{
            dp[2]=n-3;
            for(int j=3;j<=n;j++){
                dp[j]=dp[j-1]+(n-j-1)*(j/4)*(j+1);
            }
            ans[p]=dp[d/x];
        }
    }
    for(p=1;p<=t;p++) {
        cout<<ans[p]<<endl;
    }
  //  cout<<dp[d/x];
    return 0;
}
