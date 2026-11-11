#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
using namespace std;

int a[200010];
long long s[200010];
char c[200010];

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    long long l=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        cin>>c[i];
        l+=a[i];
        s[i]=s[i-1]+a[i];
    }
    if(l%2==0)
    {
        l/=2;
        int cur=lower_bound(s+1,s+n+1,l)-s;
        long long cnt1=a[1],cnt2=a[n],ans=0;
        for(int i=1,j=n;i<j;i=i)
        {
            if(cnt1>cnt2)
            {
                if(c[i]!=c[j])
                {
                    ans+=cnt2;
                }
                cnt1-=cnt2;
                cnt2=a[--j];
            }
            else if(cnt1<cnt2)
            {
                if(c[i]!=c[j])
                {
                    ans+=cnt1;
                }
                cnt2-=cnt1;
                cnt1=a[++i];
            }
            else
            {
                if(c[i]!=c[j])
                {
                    ans+=cnt1;
                }
                cnt2=a[--j];
                cnt1=a[++i];
            }
        }
        cout<<ans;
    }
    else
    {
        l=l/2+1;
        int cur=lower_bound(s+1,s+n+1,l)-s;
        long long cnt1=a[1],cnt2=a[n],ans=0;
        for(int i=1,j=n;i<j;i=i)
        {
            if(cnt1>=cnt2)
            {
                if(c[i]!=c[j])
                {
                    ans+=cnt2;
                }
                cnt1-=cnt2;
                cnt2=a[--j];
            }
            else if(cnt1<cnt2)
            {
                if(c[i]!=c[j])
                {
                    ans+=cnt1;
                }
                cnt2-=cnt1;
                cnt1=a[++i];
            }
        }
        cout<<ans;
    }
    return 0;
}
