#include <bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
    }
    if(m==1)
    {
        long long maxx=0;
        for(int i=1;i<=n;i++)
        {
            maxx=max(a[i],maxx);
        }
        printf("%d",maxx);
    }
    else if(m==2)
    {
        long long maxx=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                maxx=max(a[i]&a[j],maxx);
            }
        }
        printf("%d",maxx);
    }
    return 0;
}