#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
ll a,xa,ya,za;
ll b,xb,yb,zb;
char s1[2010];
char s2[2010];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    scanf("%lld%s%lld%s",&a,s1,&b,s2);
    xa=(s1[0]-48)*10+(s1[1]-48);
    xb=(s2[0]-48)*10+(s2[1]-48);
    ya=(s1[2]-64);
    yb=(s2[2]-64);
    za=(ya<=3);
    zb=(yb<=3);
    printf("%lld%lld%lld%lld",a==b,a==b&&xa==xb,a==b&&xa==xb&&za==zb,a==b&&xa==xb&&za==zb&&llabs(ya-yb)==1);
    return 0;
}
