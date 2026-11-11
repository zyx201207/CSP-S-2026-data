#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],mx,sum[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
    for(int i=1;i<=n;i++){
        long long l=1,r=i,ans=0;
        while(l<=r){
            long long mid=(l+r)/2;
            if(a[i]*(i-mid+1)-sum[i]+sum[mid-1]<=m)ans=mid,r=mid-1;
            else l=mid+1;
        }
        mx=max(mx,i-ans+1);
    }
    cout<<mx;
    return 0;
}
