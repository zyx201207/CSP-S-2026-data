#include <bits/stdc++.h>
using namespace std;
int c,t,n;
long long d,x[2000005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%d %d",&c,&t);
    for(int i=1;i<=t;i++)
    {
        scanf("%d %lld",&n,&d);
        for(int i=1;i<=n;i++)
        {
            scanf("%lld",&x[i]);
        }
        if(x[2]-x[1]>d/2||x[2]-x[1]<=d/3)
        {
            printf("0\n");
        }
        if(x[2]-x[1]<=d/2&&x[2]-x[1]>d/3)
        {
            printf("%d\n",n-3);
        }
    }
    return 0;
}