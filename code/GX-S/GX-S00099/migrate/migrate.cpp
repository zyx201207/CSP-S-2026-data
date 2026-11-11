#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    long long c,t,n,d,v1,v2,sum=0;
    cin>>c>>t;
    for(long long i=1;i<=t;i++){
        cin>>n>>d;
        long long a[n],dp[n];
        for(long long w=d;d>=1;w--){
            for(long long m=0;m<n;m++){
                for(long long j=m;j<n;j++){
                    if(j==0) dp[j]==0;
                    else if(j<w) dp[j]=dp[j-1]+1;
                    else{
                        v1=dp[j-w]+1;
                        v2=dp[j-1]+1;
                        dp[j]=min(v1,v2);
                    }
                }
            }
            }
            for(long long j=0;j<n;j++){
                if(dp[j]%2==0){
                    sum+=dp[j]/2;
                }
            }
            cout<<sum<<endl;
            sum=0;
        }
    return 0;
}
