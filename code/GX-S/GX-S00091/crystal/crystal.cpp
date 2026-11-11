#include<bits/stdc++.h>
using namespace std;
long long ans,n,m,a[500010],s[500010];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    for(long long i=1;i<=n;i++) s[i]=s[i-1]+a[i];
    for(long long i=n;i>=1;i--){
        long long l=1,r=i;
        while(l<r){
            long long mid=l+r+1LL>>1LL;
            if(a[i]*mid-s[i]+s[i-mid]<=m) l=mid;
            else r=mid-1LL;
        }
        ans=max(ans,l);
    }
    cout<<ans;
    return 0;
}
