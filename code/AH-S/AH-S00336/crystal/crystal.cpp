#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int n,m,ans;ll a[500010],sum[500010];
bool check(int l,int r){
    return -sum[r]+sum[l-1]+a[r]*(r-l+1)<=m;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
    for(int i=1;i<=n;i++){
        int l=1,r=i;
        while(l+1<r){
            int mid=(l+r)>>1;
            if(check(mid,i))r=mid;
            else l=mid;
        }
        if(check(l,i))ans=max(ans,i-l+1);
        else ans=max(ans,i-r+1);
    }
    cout<<ans;
}
