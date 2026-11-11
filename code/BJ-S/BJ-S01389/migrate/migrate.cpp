#include <bits/stdc++.h>
#define int long long
#define rep(i,s,t) for(int i=s;i<=t;++i)
using namespace std;
const int N=2e6+11;
int c,t,n,d,a[N];
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%lld%lld",&c,&t);
    while(t--){
        scanf("%lld%lld",&n,&d);
        rep(i,1,n)scanf("%lld",a+i);
        int k=d/(a[2]-a[1]);
        if(k==1||k==0){
            puts("0");
            continue;
        }
        printf("%lld\n",max(0ll,n-2*k+1));
    }
    return 0;
}
