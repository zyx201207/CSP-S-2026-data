#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005];
bool check(long long mid){
    for(int i=1;i<=n-mid+1;i++){
            if(a[i+mid-1]*mid-b[i+mid-1]+b[i-1]<=m)
            return true;
    }
    return false;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)b[i]=b[i-1]+a[i];
    check(n);
    long long l=1,r=n;long long mid;
    while(l<r){
        mid=(l+r)/2;
        if(check(mid)){
            l=mid+1;
        }
        else {
            r=mid-1;
        }
    }
    if(check(mid+1))cout<<mid+1;
    else if(check(mid))cout<<mid;
    else cout<<mid-1;
}
