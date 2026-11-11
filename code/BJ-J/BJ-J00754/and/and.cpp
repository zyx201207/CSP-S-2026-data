#include<bits/stdc++.h>
using namespace std;
long long n,m,ans=0,a[214514];
bool cmp(long long a,long long b)
{
    return a>b;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%lld",&n);
    scanf("%lld",&m);
    for(long long i=0;i<n;i++)
    {
        scanf("%lld",&a[i]);
    }
    sort(a,a+n,cmp);
    ans=a[0];
    for(long long i=1;i<m;i++)
    {
        ans=ans&a[i];
    }
    printf("%lld",ans);
    return 0;
}
