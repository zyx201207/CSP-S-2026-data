#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,ans=-1e18,a[1000005],sum[1000005],m;
int ch(int i){
    int l=1,r=i;
    while(l<r){

        int mid=(l+r+1)/2;
        if(a[i]*mid-(sum[i]-sum[i-mid])<=m)l=mid;
        else r=mid-1;
    }return l;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
    }
    //cao:
    for(int i=1;i<=n;i++){
        ans=max(ans,ch(i));
    }cout<<ans;
    return 0;
}
