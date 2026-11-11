#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
long long sum;
bool check(long long x){
    long long cnt=0;
    long long ans=0;
    for(int i=1;i<=n;i++){
        if(a[i]<x)cnt+=x-a[i];
        if(a[i]<=x)ans++;
    }
    if(cnt<=m)sum=max(sum,ans);
    return cnt<=m;
}
bool check2(long long x){
    long long cnt=0;
    for(int i=1;i<=n;i++){
        if(a[i]<x)cnt+=x-a[i];
    }
    return cnt<m;
}
long long check3(long long x){
    long long cnt=0;
    for(int i=1;i<=n;i++){
        if(a[i]<x)cnt+=x-a[i];
    }
    return m-cnt;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    long long l=a[1],r=a[n];
    while(l<=r){
        long long mid=l+(r-l)/2;
        if(check(mid))l=mid+1;
        else r=mid-1;
    }
    if(check2(r)){
        long long x=check3(r);
        int i=1;
        while(sum<=n && a[sum]-a[i]+x>(sum-i)*(a[sum+1]-a[sum]) && x>0){
            x+=a[sum]-a[i];
            x-=(sum-i)*(a[sum+1]-a[sum]);
            i++;
            while(a[sum]==a[sum+1])sum++;
        }
    }
    cout<<sum;
    return 0;
}
