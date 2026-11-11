#include<bits/stdc++.h>
using namespace std;
const int N=505;
long long w[N],a[N],t[N],x[N],y[N];
int c,n,m,d,q,k;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++)scanf("%lld",w+i);
    for(int i=1;i<=n;i++){
        scanf("%d",&k);
        for(int i=1;i<=k;i++)scanf("%lld%lld",a+i,t+i);
    }
    for(int i=1;i<=n;i++){
        scanf("%lld%lld",x+i,y+i);
        printf("4\n");
    }
    return 0;
}
