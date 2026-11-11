#include<bits/stdc++.h>
using namespace std;
long long n,m,ans,cry;
long long a[500005];
long long check(long long midd){
    long long cost=1e13;
    for(int i=midd;i<=n;i++){
            long long costt=0;
        for(int j=i;j>=i-midd+1;j--){
            costt+=a[i]-a[j];
        }
    cost=min(cost,costt);
    }
    if(cost>m){
        return 0;
    }
    else{
        return 1;
    }
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    long long l=1,r=n,mid;
    while(l<=r){
        mid=(l+r)>>1;
        if(check(mid)){
            l=mid+1;
            ans=mid;
        }else{
            r=mid-1;
        }
    }
    cout<<ans;
    return 0;
}
