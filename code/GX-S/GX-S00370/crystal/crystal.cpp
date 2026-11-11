#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a);i<=(b);i++)
#define Ror(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;using ll=long long;
const int N=5e5+10;
ll n,m,a[N],ans;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    For(i,1,n)scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    ll l=1,sum=0;
    For(r,1,n){
        sum+=a[r];
        while((r-l+1)*a[r]-sum>m)sum-=a[l],l++;
        ans=max(ans,r-l+1);
    }
    printf("%lld",ans);
    return 0;
}
