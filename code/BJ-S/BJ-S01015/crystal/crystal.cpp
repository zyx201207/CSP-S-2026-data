#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005];
__int128 cha[500005],sum[500005],sum1[500005];
bool check(long long xx){
    if(xx==1)return 1;
    __int128 x=xx;
    for(int i=x-1;i<n;i++){
        if((sum[i]-sum[i-x+1])*(x-1)-sum1[i-1]+sum1[i-x+1]*(x-1)>=0&&(sum[i]-sum[i-x+1])*(x-1)-sum1[i-1]+sum1[i-x+1]*(x-1)<=m){
            return 1;
        }
    }
    return 0;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<n;i++){
        cha[i]=a[i+1]-a[i];
        //cout<<cha[i]<<" ";
    }
    for(int i=1;i<n;i++){
        sum[i]=sum[i-1]+cha[i];
        //cout<<sum[i]<<" ";
    }
    sum1[0]=0;
    for(int i=1;i<n;i++){
        sum1[i]=sum1[i-1]+sum[i];
        //cout<<sum1[i]<<" ";
    }
    long long l=1,r=n;
    long long res=0;
    while(l<=r){
        long long mid=(l+r)>>1;
        if(check(mid)){
            res=mid;
            l=mid+1;
        }
        else r=mid-1;
    }
    cout<<res;
    return 0;
}