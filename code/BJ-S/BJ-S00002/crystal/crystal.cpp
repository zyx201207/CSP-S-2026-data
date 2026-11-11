#include<bits/stdc++.h>
using namespace std;
long long n,ans;
long long a[500010],sum[500010],m;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(long long i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
    }
    for(long long i=1;i<=n;i++){
        long long l=1,r=i,tmp=-1;
        while(l<=r){
            long long mid=(l+r)/2;
            //cout<<i<<" "<<mid<<" "<<a[i]*(i-mid)-(sum[i-1]-sum[mid-1])<<endl;
            if(a[i]*(i-mid)-(sum[i-1]-sum[mid-1])<=m){
                r=mid-1;
                tmp=mid;
            }else{
                l=mid+1;
            }
        }
        if(tmp!=-1){
            ans=max(ans,i-tmp+1);
        }
    }
    cout<<ans;
    return 0;
}
