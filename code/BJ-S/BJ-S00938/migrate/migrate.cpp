#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int c,t,n;
long long a[N],d;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%d%d",&c,&t);
    if(c==11||c==12)
    {
        while(t--)
        {
            scanf("%d%lld",&n,&d);
            for(int i=1;i<=n;i++)
            scanf("%lld",&a[i]);
            int e=a[2]-a[1];
            if((n-2*(d/e-1))<0||d<2*e)printf("0\n");
            else printf("%lld\n",1ll*(n-2*(d/e-1))/2);
        }
    }
    fclose(stdin);
    fclose(stdout);
}
