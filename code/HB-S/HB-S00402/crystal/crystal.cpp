#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long sj[500005];
long long sum=0;
long long maxn=0;
bool d=false;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld %lld",&n,&m);
    int dc;
    for(int i = 1;i<=n;i++)
    {
        scanf("%lld",&sj[i]);
    }
    sort(sj+1,sj+n+1);
    for(int i = 1;i<=n;i++)
    {
        if(i==2)
        {
            dc=sj[2]-sj[1];
            d=true;
        }
        if(i>2&&sj[i]-sj[i-1]!=dc)
        {
            d=false;
            break;
        }
    }
    if(d)
    {
        long long mm=0;
        for(int i = 1;i<=n;i++)
        {
            mm+=i*dc;
            if(mm>m)
            {
                printf("%d",i);
                break;
            }
        }
        return 0;
    }
    for(int i = 1;i<=n;i++)
    {
        sum+=sj[i];
        long long t=sum+min(m,i*sj[i]-sum);
        long long tt=t-(t%sj[i]);
        maxn=max(maxn,tt/sj[i]);
    }
    printf("%lld",maxn);
    return 0;
}
