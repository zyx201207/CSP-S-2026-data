#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=5e5+10;
LL a[N],sum[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    LL n,m;
    cin>>n>>m;
    for(LL i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    for(LL i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
    LL l=1,maxn=0;
    for(LL r=1;r<=n;r++){
        while(l<r&&a[r]*(r-l+1)-(sum[r]-sum[l-1])>m)l++;
        maxn=max(maxn,r-l+1);
    }
    cout<<maxn;
    return 0;
}
