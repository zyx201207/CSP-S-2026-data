#include<bits/stdc++.h>
using namespace std;
int n;
long long m,a[500005],sum[500005],sum2[500005];
int ans=0;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=2;i<=n;i++){
        sum[i]=a[i]-a[i-1];
        sum2[i]=sum[i]*(i-1)+sum2[i-1];
    }
    for(int i=n;i>=1;i--){
        if(sum2[i]-sum2[i-ans]>m)continue;
        else{
            for(int j=0;j<=i-ans;j++){
                if(sum2[i]-sum2[j]<=m){
                    ans=max(i-j,ans);
                    break;
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
