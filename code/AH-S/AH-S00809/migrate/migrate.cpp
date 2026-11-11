#include<bits/stdc++.h>
using namespace std;
#define ll long long

int c,T;

ll a[2*1000005];

int main(){

    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%d%d",&c,&T);
    while(T--){
        ll d;
        ll n;
        scanf("%lld%lld",&n,&d);
        for(int i=1;i<=n;++i)
            scanf("%lld",&a[i]);
        if(a[n]-a[1]<=d){
            ll t=n*(n+1)/2;
            printf("%lld\n",0);
            continue;
        }
        ll num=a[2]-a[1];
        ll tot=d/num;
        if(tot>=n)
            tot=n;
        else
            tot++;
        printf("%lld\n",(n-tot));
    }
    return 0;
}
