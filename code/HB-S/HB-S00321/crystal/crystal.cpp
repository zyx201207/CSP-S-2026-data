#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500005],sum[500005];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
    }
    int ans=1;
    for(int i=1;i<=n;i++){
        int l=0,r=i-1;
        while(l<r){
            int mid=(l+r+1)/2;
            if(a[i]*mid-sum[i-1]+sum[i-1-mid]<=m){
                l=mid;
            }
            else{
                r=mid-1;
            }
        }
        ans=max(ans,l+1);
    }
    cout<<ans;
    return 0;
}
