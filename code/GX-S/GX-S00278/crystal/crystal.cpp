#include<bits/stdc++.h>
using namespace std;
int n;
long long sum[500005],a[500005];
long long m;

bool check(int k){
    for(int i=1;i+k-1<=n;i++){
        int r=i+k-1;
        if(1ll*k*a[r]-(sum[r]-sum[i-1])<=m) return 1;
    }
    return 0;
}

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
    }
    int l=1,r=n,ans=1;
    while(l<=r){
        int mid=l+r>>1;
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
//O(nlogn) ke neng guo ma?
