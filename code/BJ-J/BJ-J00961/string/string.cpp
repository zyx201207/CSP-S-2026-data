#include <bits/stdc++.h>
using namespace std;
const long long N=200005;
long long a[N];
char c[N];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n;
    cin>>n;
    for(long long i=1;i<=n;i++)
    {
        long long x;
        cin>>x>>c[i];
        a[i]=a[i-1]+x;
    }
    long long ans=0;
    long long i;
    for(i=1;a[i-1]<a[n]/2;i++)
    {
        long long l1=a[i-1]+1;
        long long r1=a[i];
        long long l2=max(a[n]-l1+1,a[n]/2+1);
        long long r2=max(a[n]-r1+1,a[n]/2+1);
        long long dl=lower_bound(a+1,a+n+1,l2)-a;
        long long dr=lower_bound(a+1,a+n+1,r2)-a;
        //cout<<l1<<" "<<r1<<" "<<l2<<" "<<r2<<" "<<dl<<" "<<dr<<endl;
        if(dl==dr && c[dl]!=c[i])
        {
            ans=ans+l2-r2+1;
            continue;
        }
        if(c[dr]!=c[i])
        {
            ans=ans+a[dr]-r2+1;
        }
        if(c[dl]!=c[i])
        {
            ans=ans+l2-a[dl-1];
        }
        for(long long j=dr+1;j<=dl-1;j++)
        {
            if(c[i]!=c[j])
            {
                ans=ans+a[j]-a[j-1];
            }
        }
    }
    cout<<ans;
    return 0;
}
