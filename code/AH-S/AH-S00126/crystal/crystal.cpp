#include<bits/stdc++.h>
#define int long long
using namespace std;
long long n,m,a[500010];

signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+1+n);
    int flag=n,ll=1,ans=1;int money=m;
    while(flag>=ans){
        while(money>=a[flag]-a[flag-ll]){
            money-=a[flag]-a[flag-ll];
            //cout<<a[flag]-a[flag-ll]<<' '<<"money="<<money<<' ';
            ll++;
        }
        ans=max(ans,ll);
       // cout<<ll<<"@ "<<a[flag]<<'\n';
        money+=(ll-1)*(a[flag]-a[flag-1]);
        flag--;
        ll--;
    }
    printf("%lld",ans);
    return 0;
}
