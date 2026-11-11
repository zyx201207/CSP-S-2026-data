#include<bits/stdc++.h>
#define int long long
using namespace std;
int db;
int n,a[500005],m,sum[500005];
int fd(int i){
    int l=1,r=i+1;
    while(l<r){
        int mid=l+r>>1;
        if(a[i]*(i-mid+1)<=sum[i]-sum[mid-1]+m)r=mid;
        else l=mid+1;
    }
    return r;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    db=0;
    if(db==0){
        freopen("crystal.in","r",stdin);
        freopen("crystal.out","w",stdout);
    }
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
    int ans=0;
    for(int i=1;i<=n;i++){
        ans=max(ans,i-fd(i)+1);
    }
    cout<<ans;
    return 0;
}