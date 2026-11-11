#include <bits/stdc++.h>
using namespace std;
long long a[500001],m,n;
bool check(int x){
    long long ans=0,res=0;
    for(int i=n-x+1;i<=n;i++){
        ans+=a[i];
    }
    for(int i=n-x+1;i>=2;i--){
        if(ans-x*res<=m)return true;
        ans+=a[i-1];
        ans-=a[i+x-1];
        res=a[i+x-2];
    }
    if(ans-x*res<=m)return true;
    return false;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        a[i]=a[n]-a[i];
    }
    int l=1,r=n,mid;
    while(l<=r){
        mid=(l+r)/2;
        if(check(mid)){
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    cout<<r<<endl;
    return 0;
}
