#include<bits/stdc++.h>
using namespace std;
long long t,n,d,a[2000005],sum[2000005],dp1[2000005],dp2[2000005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>t>>t;
    while(t--){
        cin>>n>>d;
        long long l=1,ans=0;
        for(int b=1;b<=n;b++){
            cin>>a[b];
            while(a[l]<a[b]-d)l++;
            sum[b]=l;
            dp1[b]=dp2[b]=0;
            if(b!=l){
                dp1[b]=dp1[l]-l+sum[l+1]+b-sum[b];
                if(sum[l+1]!=sum[l])dp2[b]=dp2[l];
                if(l+1!=b && sum[l+1]!=sum[l+2]){
                    dp2[b]=dp2[b]+sum[l+2]-sum[l+1]+dp1[sum[l+1]]-sum[l+1]+sum[sum[l+1]+1];
                    //cout<<b<<" "<<sum[l+2]-sum[l+1]+dp1[sum[l+1]]-sum[l+1]+sum[sum[l+1]+1]<<"\n";
                }
            }
            ans=ans+dp2[b];
        }
        cout<<ans<<"\n";

    }
    return 0;
}