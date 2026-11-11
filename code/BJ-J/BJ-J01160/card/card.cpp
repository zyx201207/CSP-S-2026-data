#include <iostream>
using namespace std;
int n,m,a[500005],diff[500005],fm[500005];
struct loop
{
    int start,end;
}ll[500005];
long long sum[500005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%d %d",&n,&m);
    for (int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for (int i=n;i>0;i--)
    {
        if (!fm[a[i]]) fm[a[i]]=i,ll[i]=ll[i+1];
        else ll[i].start=i,ll[i].end=fm[a[i]];
        diff[fm[a[i]]]++;
        int addpos=fm[a[i]];
        while (ll[addpos+1].start)
            diff[ll[addpos+1].start]-=1,
            diff[ll[addpos+1].end]+=1,
            addpos=ll[addpos+1].end;
    }
    for (int i=1;i<=n;i++)
        sum[i]=sum[i-1]+diff[i];
    for (int i=1;i<=m;i++)
        printf("%lld ",sum[fm[i]]);
}
