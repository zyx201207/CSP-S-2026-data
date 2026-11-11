#include<cstdio>
#include<algorithm>
using namespace std;

const int nn=500005;

int n;
long long m;
long long a[nn];

long long sum[nn];

int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);

    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];

    long long ans=0;

    for(long long i=1,j=0;i<=n;i++)
    {
        while(sum[i]-sum[j]+m<a[i]*(i-j)) j++;
        if(i-j>ans) ans=i-j;
    }

    printf("%lld",ans);

    return 0;
}
