#include<bits/stdc++.h>
using namespace std;
struct ftw
{
    long long x;
    char c;
    long long id;
}a[200010];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    scanf("%lld",&n);
    for(long long i=1;i<=n;i++)
    {
        long long t;
        char ch;
        scanf("%lld %c",&t,&ch);
        a[i].id=i;
        a[i].x=t;
        a[i].c=ch;
    }

    long long l=1,r=n;
    long long cnt=0;
    while(l<r)
    {
        if(a[l].x==0)
        {
            l++;
            continue;
        }
        if(a[r].x==0)
        {
            r--;
            continue;
        }
        if(a[l].c!=a[r].c)
        {
            long long t=min(a[l].x,a[r].x);
            cnt+=t;
            a[l].x-=t;
            a[r].x-=t;
        }
        else
        {
            long long t=min(a[l].x,a[r].x);
            a[l].x-=t;
            a[r].x-=t;
        }
    }
    printf("%lld\n",cnt);
    return 0;
}
