#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[200005],sum[200005],l,r,li,ri,temp,ans;
char c[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld %c",&a[i],&c[i]);
        sum[i]=sum[i-1]+a[i];
    }
    l=1,r=sum[n],li=1,ri=n;
    while(li<ri)
    {
        temp=min(sum[li]-l+1,r-sum[ri-1]);
        if(c[li]!=c[ri])ans+=temp;
        l+=temp,r-=temp;
        if(l>sum[li])li++;
        if(r<=sum[ri-1])ri--;
    }
    printf("%lld\n",ans);
    return 0;
}
