#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,a[2000005],ans,dp[2000005],s[2000005],p;
int main(){
freopen("migrate.in","r",stdin);
freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
    cin>>n>>d;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        for(int j=1;j<i;j++){
            memset(dp,0,sizeof(dp));
            memset(s,0,sizeof(s));
            dp[j]=1;
            p=1;
            s[j]=j;
            for(int k=j+1;k<=i;k++){
                dp[k]+=k-s[k-1];
                p*=dp[k];
                s[k]=s[k-1];
                while(a[k]-a[s[k]]>d){
                    s[k]++;
                }
            }
            if(p==2){
                ans++;
            }
        }
    }
    cout<<ans;
    ans=0;
    }
    return 0;
}
