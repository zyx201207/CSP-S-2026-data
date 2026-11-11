#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500005];
bool check(int x){
    long long sum=0;
    for(int i=1;i<=x;i++)sum+=a[i];
    if(a[x]*x-sum<=m)return true;
    for(int i=x+1;i<=n;i++){
        sum=sum-a[i-x]+a[i];
        if(a[i]*x-sum<=m)return true;
    }
    return false;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++)scanf("%lld",a+i);
    sort(a+1,a+1+n);
    ll l=1,r=n;
    while(l<r){
        ll mid=(l+r)/2;
        if(check(mid)){
            if(l==mid)r--;
            else l=mid;
        }
        else{
            r=mid-1;
        }
    }
    printf("%lld\n",l);
}