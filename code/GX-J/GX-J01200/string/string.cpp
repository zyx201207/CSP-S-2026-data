#include<bits/stdc++.h>
using namespace std;
long long n,m,f=0,sum=0,a[200005];
char b[200005];
int bj(long long x,long long y)
{
    long long q1,q2,fla=0;
    for(int i=1;i<=n;i++)
    {
        if(fla==0&&x-a[i]<=0)
        {
            q1=i;
            fla=1;
        }
        x-=a[i];
        if(y-a[i]<=0)
        {
            q2=i;
            break;
        }
        y-=a[i];
    }
    if(b[q1]==b[q2])
        return 0;
    else
        return 1;

}
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%lld",&n);
    for(long long i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        cin>>b[i];
        f+=a[i];
    }
    for(long long i=1;i<=f/2;i++)
        sum+=bj(i,f-i+1);
    printf("%lld",sum);
    return 0;
}
