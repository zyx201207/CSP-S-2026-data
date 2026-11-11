#include<iostream>
#include<algorithm>
using namespace std;
long long n,m;
long long a[500005],cnt[500005];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(m<=1000000000&&n<=5000)
    {
    sort(a+1,a+1+n);
    cnt[0]=0;
    for(int i=1;i<=n;i++)
    {
        cnt[i]=cnt[i-1]+a[i];
    }
    int ans=-1;
    for(int i=1;i<=n;i++)
    {
        for(int j=n;j>=i;j--)
        {
            
            if(a[j]*(j-i+1)<=(cnt[j]-cnt[i-1]+m))
            {
                ans=max(ans,j-i+1);
                break;
            }
        }
    }
    cout<<ans<<endl;
    }
    else
    {
        sort(a+1,a+1+n);
    cnt[0]=0;
    for(long long i=1;i<=n;i++)
    {
        cnt[i]=cnt[i-1]+a[i];
    }
    long long i=1,j=n;
    while(i<=j)
    {
        long long t=cnt[j]-cnt[i-1]+m;
        long long d=a[j]*(j-i+1);
        if(t>=d) break;
        else
        {
            if((j-i)*(a[j]-a[j-1])>a[j]-a[i]) j--;
            else i++;
        }
    }
    cout<<j-i+1<<endl;
    }
    return 0;
}