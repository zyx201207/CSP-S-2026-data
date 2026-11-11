#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=200005;
LL n,m,a[N],l=1,maxn;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
    }sort(a+1,a+n+1);LL sum=0;a[0]=a[1];
    for(int r=1;r<=n;r++){
        sum+=(a[r]-a[r-1])*(r-l);
        while(l<=r&&sum>m){sum-=(a[r]-a[l]);l++;}
        maxn=max(maxn,r-l+1);
    }cout<<maxn;
    return 0;
}
