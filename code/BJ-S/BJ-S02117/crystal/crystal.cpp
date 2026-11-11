#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
typedef long long LL;
LL n,m,a[500005],f[500005];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(LL i=1;i<=n;++i)
        cin>>a[i];
    /*for(LL i=1;i<=n;++i)
    {
        f[i]=a[i]*n-f[i];
    }*/
    sort(a+1,a+1+n);
    for(int i=1;i<=n;++i)
        f[i]=f[i-1]+a[i];
    LL maxx=0,t,cnt=0;
    for(LL i=n;i>=1;--i)
    {
        //t=m,cnt=0;
        /*for(LL j=i;j>=1;--j)
        {
            if(t<a[i]-a[j])break;
            t=t-a[i]+a[j];
            cnt++;
        }*/
        int l=1,r=i;
        while(l<r)
        {
            int mid=(l+r)/2;
            if( (i-mid+1)*a[i] - (f[i]-f[mid-1]) <=m)r=mid;
            else l=mid+1;
        }
        maxx=max(maxx,i-l+1);
    }
    cout<<maxx;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
