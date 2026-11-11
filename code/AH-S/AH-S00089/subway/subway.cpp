#include <bits/stdc++.h>
using namespace std;
mt19937_64 rng(chrono::steady_clock()::now().time_since_epoch().count());
long long rand_ll(ll L,ll R){
    return uniform_int_distribution<long long>(L,R)(rng);
}
int main(void){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    long long a,b,c,d,e,f,g,s=0;
    scanf("%lld%lld%lld%lld%lld",&a,&b,&c,&d,&e);
    for(i=1;i<=c;++i)scanf("%lld",&f);
    for(i=1;i<=b;++i){
        scanf("%lld",&g);
        for(j=1;j<=g*2;++j)scanf("%lld",f),s+=f;
    }
    for(i=1;i<=e;++i){
        scanf("%lld",&f);
        printf("%lld",rand_ll(1,s/2));
    }
    return 0;
}
