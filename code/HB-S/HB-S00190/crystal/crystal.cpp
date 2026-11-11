#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a[500005],cnt,l,r,mid,maxn=-100000;
ll check(ll x){
    ll cntn=0;
    if(x>n) return 0;
    cnt=m;
    for(int j=x;j>=1;j--){
        if((cnt-(a[x]-a[j]))<0){
            return cntn;
        }
        else{
           cntn++;
           cnt-=(a[x]-a[j]);
        }
    }
    return cntn;
}
bool check2(ll x){
    if(x>n) return false;
    cnt=m;
    for(int j=1;j<=(x-1);j++){
        if((cnt-(a[x]-a[j]))<0){
            return false;
        }
        else{
           cnt-=(a[x]-a[j]);
        }
    }
    return true;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+1+n);
    if(n<=5000){
        for(ll i=n;i>=1;i--){
            maxn=max(maxn,check(i));
            if(i<maxn){
                break;
            }
        }
        cout<<maxn;
        return 0;
    }
    l=1,r=n;
    while(l<r){
        mid=(l+r)/2;
        if(check2(mid)==0){
            r=mid;
        }
        else if(check2(mid)==1){
            l=mid+1;
        }
    }
    for(int i=l;;i++){
        if(check2(i)==0){
            cout<<i-1;
            break;
        }
    }
    return 0;
}

