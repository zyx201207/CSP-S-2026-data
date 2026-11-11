#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=501000;
int a[N],sum[N],n,m;
bool check(int mid){
    for(int i=mid;i<=n;i++){
        int j=i-mid+1;
        if(sum[i]-sum[j-1]+m>=a[i]*mid)return 1;
    }
    return 0;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
    }
    int ans,l=1,r=n;
    while(l<=r){
        int m=l+r>>1;
        if(check(m)){
            ans=m;
            l=m+1;
        }
        else r=m-1;
    }
    cout<<ans<<'\n';
    return 0;
}