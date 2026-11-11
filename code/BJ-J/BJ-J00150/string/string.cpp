#include <bits/stdc++.h>
using namespace std;
long long a;
int n;
char b;
char c[2000000005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    scanf("%d",&n);
    unsigned long long t=0;
    for(int k=1;k<=n;k++)
    {
        scanf("%lld",&a);
        cin >>b;
        for(long long i=1;i<=a;i++)
        {
            c[++t]=b;
        }
    }
    long long ans=0;
    for(unsigned long long i=1;i<=t/2;i++)
    {
        if(c[i]!=c[t-i+1])
        {
            ans++;
        }
    }
    printf("%lld",ans);
    return 0;
}
