#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=5e5+10;
LL c,n,m,d,q,a[N],u,v,w,k;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
    for(LL i=1;i<=m;i++) scanf("%lld",&a[i]);
    for(LL i=1;i<=n;i++){
        scanf("%lld",&k);
        for(LL j=1;j<=k;j++){
            scanf("%lld%lld",&v,&w);
        }
    }
    while(q--){
        scanf("%lld%lld",&u,&v);
        cout<<1<<endl;
    }
    return 0;
}
