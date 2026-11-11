#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=5e5+10;
int n,m,a[N];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    int ans=1,l=1;
    __int128 t=0;
    for(int i=2;i<=n;i++){
        t+=(__int128)(a[i]-a[i-1])*(i-l);
        for(l=l;l<=i&&t>m;l++){
            t-=(a[i]-a[l]);
        }
        ans=max(ans,i-l+1);
    }
    printf("%lld",ans);
    return 0;
}
