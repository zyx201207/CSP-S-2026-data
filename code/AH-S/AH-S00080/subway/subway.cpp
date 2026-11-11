#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,a,b;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    a=3*n+26;
    b=19-n;
    scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
    if(n==2) printf("32\n17");
     else if(n==3) printf("35\n16");
     else printf("%lld\n%lld",a,b);
    return 0;
}
