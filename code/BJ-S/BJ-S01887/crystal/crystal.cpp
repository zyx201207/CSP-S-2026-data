#include<bits/stdc++.h>
using namespace std;
long long int n,m,a[500005],l,r,dp[500005],sum;
int cheak(int len){
    for(int i=len;i<=n;i++)
        if(dp[i]-dp[i-len]-(a[i]-a[i-len])*(i-len)<=m)return 1;
    return 0;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        dp[i]=a[i]*(i-1)-sum;
        sum+=a[i-1];
    }
    l=1;r=n;
    while(l<=r){
        int mid=(l+r)/2;
        if(cheak(mid)){
            l=mid+1;
        }else r=mid-1;
    }
    cout<<l-1;
    return 0;
}
