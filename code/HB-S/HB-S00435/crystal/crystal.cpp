#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5;
ll n,m,a[N+5],l,r,x,ms=1;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(ll i=0;i<n;i++)scanf("%lld",&a[i]);
    sort(a,a+n);
    while(r<n){
        if(x<=m)r++,x+=(a[r]-a[r-1])*(r-l);
        else ms=max(ms,r-l),x-=(a[r]-a[r-1])*(r-l),r--,x-=a[r]-a[l],l++;
    }printf("%lld",ms);
    return 0;
}
