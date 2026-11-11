#include<bits/stdc++.h>
using namespace std;
int n;
long long a[500001],l,r,ans,m;
bool ch(long long x){
    long long sum=0;
    for(int i=1;i<x;i++){
        sum+=a[x]-a[i];
    }
    if(sum<=m)return 1;
    return 0;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    l=1,r=n;
    while(l<=r){
        long long mid=(l+r)/2;
        if(ch(mid)){
            ans=mid;
            l=mid+1;
        }
        else r=mid-1;
    }
    cout<<ans;
    return 0;
}
