#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[500010]={};
int prefix[500010]={};
int calc(int k,int i){
    return a[k]*(k-i)-prefix[k-1]+prefix[i-1];
}
int bs(int l,int r,int k){
    int ans=r;
    while(l<=r){
        int mid=l+r>>1;
        if(calc(k,mid)<=m){
            r=mid-1;
            ans=mid;
        }else{
            l=mid+1;
        }
    }
    return ans;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;++i){
        prefix[i]=prefix[i-1]+a[i];
    }
    int ans=1;
    for(int i=1;i<=n;++i){
        int t=bs(1,i,i);
        ans=max(ans,i-t+1);
    }
    cout<<ans<<endl;
    return 0;
}