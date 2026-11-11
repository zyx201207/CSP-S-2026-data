#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int b=1;b<=n;b++)cin>>a[b];
    sort(a+1,a+1+n);
    for(int b=1;b<=n;b++){
        a[b]=a[b-1]+a[b];
        long long l=1,r=b+1;
        while(l!=r){
            long long mid=(l+r)/2;
            if((a[b]-a[b-1])*mid-a[b]+a[b-mid]<=m)l=mid+1;
            else r=mid;
        }
        ans=max(ans,l-1);
    }
    cout<<ans;
    return 0;
}