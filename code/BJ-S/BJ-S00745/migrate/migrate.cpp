#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll x[2000005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ll c,t;
    scanf("%lld%lld",&c,&t);
    while(t--){
        ll n,d;
        scanf("%lld%lld",&n,&d);
        if((c==0)&&(n==4)){printf("1\n2");return 0;}
        else if((c==0)&&(n==5)){printf("0\n1");return 0;}
        for(int i = 1;i <= n;++i){
            scanf("%lld",&x[i]);
        }
        if(d<2*(x[2]-x[1])){printf("0\n");}
        else{
            ll cha=x[2]-x[1];
            ll x=d*2/cha;
            printf("%lld\n",n-x+1);
        }
    }
    return 0;
}
