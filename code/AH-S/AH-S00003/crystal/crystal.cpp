#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
ll n,m;
ll sum;
ll maxn;
ll a[2000010];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(ll i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+1+n);
    for(ll l=1,r=1;r<=n;r++){
        sum+=(a[r]-a[r-1])*(r-l);
        while(l<r&&sum>m){
            sum-=a[r]-a[l];
            l++;
        }
        maxn=max(maxn,r-l+1);
    }
    printf("%lld",maxn);
    return 0;
}
