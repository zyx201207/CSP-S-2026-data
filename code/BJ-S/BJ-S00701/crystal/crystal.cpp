#include<bits/stdc++.h>
using namespace std;
const long long SIZE=500005;
int n;
long long m,a[SIZE],add[SIZE],dif[SIZE],l,r,mid;
bool check(int x){
    long long sum=0,mmin=1e18+5;
    for(int i=2;i<=x;i++){
        sum=sum+dif[i]*(i-1);
    }
    mmin=min(mmin,sum);
    for(int i=x+1;i<=n;i++){
        sum=sum+(x-1)*dif[i]-(a[i-1]-a[i-x]);
        mmin=min(mmin,sum);
    }
    if(mmin<=m) return 1;
    return 0;
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
        add[i]=add[i-1]+a[i];
        if(i>1){
            dif[i]=a[i]-a[i-1];
        }
    }
    l=1;
    r=n;
    while(l<r){
        mid=(l+r)/2;
        if(check(mid)) l=mid+1;
        else r=mid;
    }
    if(check(l)) cout<<l;
    else cout<<l-1;
    return 0;
}