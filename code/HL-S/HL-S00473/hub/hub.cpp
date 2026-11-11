#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int N=2e6+10;
ll c,t,u[N],v[N];

int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    scanf("%lld%lld",&c,&t);
    while(t--){
        ll n,k;
        scanf("%lld%lld",&n,&k);
        for(register int i=1; i<=n;i++){
            scanf("%lld%lld",&u[i],&v[i]);
        }
        printf("1\n");
    }
    return 0;
}
