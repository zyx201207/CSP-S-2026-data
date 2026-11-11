#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],sum[500005],ans;
bool check(int x){
    long long cnt=1e18;
    for(int i=x;i<=n;i++){
        cnt=min(a[i]*x-sum[i]+sum[i-x],cnt);
    }
    if(cnt<=m){
        return 1;
    }else{
        return 0;
    }
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
    }
    int l=0,r=n;
    while(l<=r){
        int mid=(l+r)/2;
        if(check(mid)){
            ans=mid;
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    cout<<ans;
    return 0;
}
