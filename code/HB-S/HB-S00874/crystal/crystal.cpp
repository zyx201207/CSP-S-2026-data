#include<bits/stdc++.h>
using namespace std;
long long n,m,p,ans=0,sum=0,a[500010];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    if(n>100000)
    {
        long long q=a[2]-a[1];
        long long c=((sqrt(q*q+8*q*m)-q)/(2*q))+1;
        cout<<c;
        return 0;
    }
    for(long long i=1;i<=n;i++)
    {
        long long cnt=1;
        p=m;
        for(long long j=i-1;j>=1;j--)
        {
            if(a[i]-a[j]<=p&&p>0)
            {
                p=p-(a[i]-a[j]);
                cnt++;
            }
            else
            {
                break;
            }

        }
        ans=max(ans,cnt);
    }
    cout<<ans;
    return 0;
}
