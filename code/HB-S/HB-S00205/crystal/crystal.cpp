#include<bits/stdc++.h>
using namespace std;
long long a[500005],b[500005];
int main()
{   freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m,s,ans=0;
    cin>>n>>m;
    for(long long i=1;i<=n;i++)
    {   cin>>a[i];
    }
    sort(a+1,a+n+1);
    b[1]=0;
    for(long long i=1;i<=n;i++)
    {   b[i]=b[i-1]+(i-1)*(a[i]-a[i-1]);
    }
    long long l=1;
    for(long long i=1;i<=n;i++)
    {   while((b[i]-b[l-1]-(a[i]-a[l-1])*(l-1))>m)
        {
            l++;

        }
        ans=max(ans,i-l+1);
    }
    cout<<ans;
    return 0;
}
