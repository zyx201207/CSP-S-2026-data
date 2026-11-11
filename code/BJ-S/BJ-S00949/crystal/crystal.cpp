#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500010];
long long sum[500010];
long long check(long long l){
    for(int i=1;i<=n-l+1;i++){
        if(a[i+l-1]*l-(sum[i+l-1]-sum[i-1])<=m)return 1;
    }
    return 0;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
    }
    long long l=1,r=n;
    while(l<r){
        long long mid=l+r+1>>1;
        //cout<<l<<' '<<r<<endl;
        if(check(mid))l=mid;
        else r=mid-1;
    }
    cout<<l<<endl;
    return 0;
}
