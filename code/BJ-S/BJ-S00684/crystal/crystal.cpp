#include <iostream>
#include <algorithm>
using namespace std;

long long n,m;
long long a[500010];

bool check(long long x)
{
    long long cnt=0;
    for(long long i=1;i<=x;i++)
    {
        cnt+=a[x]-a[i];
    }

    return cnt<=m;
}

int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;

    for(int i=1;i<=n;i++)cin>>a[i];

    sort(a+1,a+n+1);

    long long l=1,r=n;
    long long ans=0;
    while(l<=r)
    {
        long long mid=(l+r)/2;

        if(check(mid))
        {
            ans=mid;
            l=mid+1;
        }
        else r=mid-1;
    }

    cout<<ans<<endl;
    return 0;
}
