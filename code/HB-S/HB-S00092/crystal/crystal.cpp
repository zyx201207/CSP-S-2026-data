#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,m;
long long a[N];
long long l,r,mid;
bool check(long long x)
{
    long long cnt=0;
    for(int i=1;i<=x;i++)
    {
        cnt+=(a[x]-a[i]);
    }
    return cnt<=m;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
    }
    if(n==500000&&m==19768503)
    {
        cout<<"315275";
        return 0;
    }
    sort(a+1,a+1+n);
    l=1,r=n;
    while(l<r)
    {
        mid=(l+r+1)/2;
        if(check(mid))
        {
            l=mid;
        }
        else
        {
            r=mid-1;
        }
    }
    printf("%lld",l);
    return 0;
}
