#include<bits/stdc++.h>
using namespace std;
long long n;
long long m;
long long a[500005],cnt[500005],sum[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    sum[0]=0;
    for(int i=2;i<=n;i++){
        sum[i]=a[i]-a[i-1]+sum[i-1];
    }
    int ans=1,l=1,r=2;
    sum[2]=a[2]-a[1];
    while(r<=n){
        if(l==r) r++;
        if(sum[r]-sum[l-1]<=m){
            ans=max(ans,r-l+1);
            r++;
            sum[r]=sum[r-1]+(a[r]-a[r-1])*(r-1);
        }
        else{
            l++;
            sum[l-1]+=(a[r]-a[l-1]);
        }
    }
    cout<<ans;
    return 0;
}
