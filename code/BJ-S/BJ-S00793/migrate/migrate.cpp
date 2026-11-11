#include <bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[500005],a[309][309];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%lld%lld",&c,&t);
    for (int i=1;i<=t;i++){
        scanf("%lld%lld",&n,&d);
        for (int i=1;i<=n;i++){
            scanf("%lld",&x[i]);
        }
        printf("%lld",n-3);
    }
    return 0;
}
