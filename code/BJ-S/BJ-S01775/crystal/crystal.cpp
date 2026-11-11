#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
bool check(long long mid){
    //cout<<mid<<endl;
    long long num=0;
    for(long long i=1;i<mid;i++){
        num+=a[mid]-a[i];
    }
    //cout<<num<<" ";
    if(num<=m) return 1;
    for(long long i=mid+1;i<=n;i++){
        num-=a[i-1]-a[i-mid];
        num+=mid*(a[i]-a[i-1]);
        //cout<<num<<" ";
        if(num<=m) return 1;
    }
    return 0;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    long long l=0,r=n;
    while(l<r){
        long long mid=(l+r+1)/2;
        if(check(mid)) l=mid;
        else r=mid-1;
    }
    cout<<l;
    //cout<<endl<<check(315275)<<endl;
    return 0;
}
