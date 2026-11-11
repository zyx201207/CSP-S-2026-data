#include <bits/stdc++.h>
using namespace std;

long long n,m;
long long a[500010],s[500010];
long long ans=1;

bool cmp(long long x,long long y)
{
    return x<y;
}

int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    cin>>n>>m;
    for(long long i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+1+n,cmp);

    bool ab=1;
    for(long long i=1;i<n;i++)
    {
        s[i]=a[i+1]-a[i];
        if(s[i]!=s[1]) ab=0;
    }
    if(ab)
        for(long long i=1;i<=n;i++)
            if((i+1)*i*i/2>m||i==n)
            {
                cout<<i<<endl;
                return 0;
            }
    long long sum,mm;
    for(long long i=1;i<=n-1;i++)
    {
        mm=m,sum=1;
        while(s[i+sum-1]*sum<=mm&&i+sum-1<n)
        {
            mm-=s[i+sum-1]*sum;
            sum++;
        }
        ans=max(ans,sum);
    }
    cout<<ans;
    return 0;
}
