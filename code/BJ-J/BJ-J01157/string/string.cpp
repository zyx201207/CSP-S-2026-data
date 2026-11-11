#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
int n,tmp,tmpl,tmpr,l,r;
ll a[N],sum[N],len,mid,cnt;
char c[N];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        cin>>c[i];
        len+=a[i];
        sum[i]=sum[i-1]+a[i];
    }
    mid=len/2ll+(len%2ll);
    for (int i=n-1;i>=0;i--)
        if (mid>sum[i])
        {
            tmp=i+1;
            tmpl=mid-sum[i]-1;
            tmpr=sum[i+1]-mid;
            break;
        }
    a[tmp]-=min(tmpl,tmpr)*2;
    l=tmp-1;
    r=tmp;
    if (len%2ll==1)
        a[tmp]-=1;
    else
    {
        if (mid==sum[tmp])
        {
            a[tmp]-=1,a[tmp+1]-=1;
            if (c[tmp]!=c[tmp+1])
                cnt+=1;
            l=tmp,r=tmp+1;
        }
        else
            a[tmp]-=2;
    }
    for (;l>=1 && r<=n;)
    {
        if (a[l]>a[r])
        {
            if (c[l]!=c[r])
            {
                cnt+=a[r];
            }
            a[l]-=a[r];
            r++;
        }
        else if (a[r]>a[l])
        {
            if (c[l]!=c[r])
            {
                cnt+=a[l];
            }
            a[r]-=a[l];
            l--;
        }
        else if (a[l]==a[r])
        {
            if (c[l]!=c[r])
            {
                cnt+=a[l];
            }
            a[l]=a[r]=0;
            l--;
            r++;
        }
    }
    printf("%lld\n",cnt);
    return 0;
}
