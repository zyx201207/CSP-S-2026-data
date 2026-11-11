#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
bool check(long long mid){
    long long ans=0;
    for(int i=1;i<=n;i++){
        if(a[i]<a[mid]){
            ans+=(a[mid]-a[i]);
        }
    }if(ans<=m){
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
    }sort(a+1,a+n+1);
    long long l=1,r=n;
    while(l<=r){
        long long mid=(l+r)/2;
        if(check(mid)){
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    long long an=l-1,ans=0;
    for(int i=1;i<=n;i++){
        if(a[i]<=a[an]){
            ans++;
        }
    }cout<<ans;
    return 0;
}
